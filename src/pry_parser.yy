%skeleton "lalr1.cc"
%require  "3.0"
%defines
%define api.namespace {Pry}
%define parser_class_name {Parser}

%code requires{
  #include "src/node/_utility.hpp"

   namespace Pry {
      class Driver;
      class Scanner;
   }

    #ifndef YY_NULLPTR
        #if defined __cplusplus && 201103L <= __cplusplus
            #define YY_NULLPTR nullptr
        #else
            #define YY_NULLPTR 0
        #endif
    #endif
}

%parse-param { Scanner &scanner }
%parse-param { Driver  &driver  }

%code{
    #include "src/pry_driver.hpp"

    #undef yylex
    #define yylex scanner.yylex
    #define vtable driver.variables.get()
    #define stable driver.scope.get()
}

%define api.value.type variant
%define parse.assert

%token EOL_T EQ_T VAR_T VAL_T
%token COMMENT EOL LPAR_T RPAR_T
%token <std::string> VAR STRING
%token <int>         INT
%token <double>      DOUBLE
%token <Pry::node::MathOp> PLUS_T MINUS_T TIMES_T DIVIDE_T POW_T
%token <Pry::node::BoolOp> COND_EQ_T COND_NEQ_T COND_INF_T COND_INFEQ_T COND_SUP_T COND_SUPEQ_T
%token <Pry::tree::List*> DO_T
%token IF_T ELSE_T END_T

%type <Pry::node::Node*> Expr Math
%type <Pry::node::Assignment*> Assignment
%type <Pry::node::Declarement*> Declarement
%type <Pry::node::Variable*> Variable
%type <Pry::node::Primitive*> Primitive
%type <Pry::node::Condition*> Condition
%type <Pry::node::BoolComparator*> BoolExpr
%type <Pry::node::Scope*> Block

%type <Pry::tree::List*> BlockBegin

%locations

%left PLUS_T MINUS_T
%left TIMES_T DIVIDE_T
%right POW_T
%right VAR

%start Language
%%

Language:
    Input { return 0; }
    ;

Input:
                    {}
    |  Input Line   {}
    |  Line         {}
    ;

Line:
        EOL_T      {}
    |   COMMENT    {}
    |   Expr EOL_T { driver.scope->add_node(std::move($1)); }
    ;

Expr:
        Variable           { $$=$1; }
    |   Primitive          { $$=$1; }
    |   Math               { $$=$1; }
    |   LPAR_T Expr RPAR_T { $$=$2; }
    |   Declarement        { $$=$1; }
    |   Assignment         { $$=$1; }
    |   Condition          { $$=$1; }
    ;

Variable:
      VAR { $$=new Pry::node::Variable($1, vtable); }
    ;

Primitive:
        INT    { $$=new Pry::node::Primitive($1); }
    |   DOUBLE { $$=new Pry::node::Primitive($1); }
    |   STRING { $$=new Pry::node::Primitive($1); }
    ;

Math:
        Expr PLUS_T Expr     { $$=new Pry::node::Math($2, $1, $3); }
    |   Expr MINUS_T Expr    { $$=new Pry::node::Math($2, $1, $3); }
    |   Expr TIMES_T Expr    { $$=new Pry::node::Math($2, $1, $3); }
    |   Expr DIVIDE_T Expr   { $$=new Pry::node::Math($2, $1, $3); }
    |   Expr POW_T Expr      { $$=new Pry::node::Math($2, $1, $3); }
    ;

BoolExpr:
        Expr COND_EQ_T Expr    { $$=new Pry::node::BoolComparator($2, $1, $3); }
    |   Expr COND_NEQ_T Expr   { $$=new Pry::node::BoolComparator($2, $1, $3); }
    |   Expr COND_INF_T Expr   { $$=new Pry::node::BoolComparator($2, $1, $3); }
    |   Expr COND_INFEQ_T Expr { $$=new Pry::node::BoolComparator($2, $1, $3); }
    |   Expr COND_SUP_T Expr   { $$=new Pry::node::BoolComparator($2, $1, $3); }
    |   Expr COND_SUPEQ_T Expr { $$=new Pry::node::BoolComparator($2, $1, $3); }
  	;


Declarement:
        VAR_T VAR EQ_T Expr {
          $$=new Pry::node::Declarement($2, vtable, false, $4);
    }
    |   VAL_T VAR EQ_T Expr {
          $$=new Pry::node::Declarement($2, vtable, true, $4);
    }

Assignment:
        VAR EQ_T Expr       { $$=new Pry::node::Assignment($1, vtable, $3); }
    ;

Condition:
        IF_T BoolExpr Block     { $$=new Pry::node::Condition($2, $3); }
    |   Expr IF_T BoolExpr      { $$=new Pry::node::Condition($3, $1); }
    ;

Block:
        BlockBegin Input BlockEnd { $$=new Pry::node::Scope($1, vtable); }
    ;

BlockBegin:
        DO_T { std::cout << "begin" << std::endl; stable->increment_depth($1); $$=$1; }
    ;

BlockEnd:
        END_T { std::cout << "end" << std::endl; stable->decrement_depth(); }
    ;

%%

void  Pry::Parser::error(Pry::location const &l, std::string const &err_message) {
    std::cerr << std::endl;
    std::cerr << "Error: " << err_message << " at " << l << std::endl;
}
