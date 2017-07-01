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
    #include <iostream>
    #include "src/pry_driver.hpp"

    #undef yylex
    #define yylex scanner.yylex
}

%define api.value.type variant
%define parse.assert

%token EOL_T EQ_T VAR_T VAL_T
%token COMMENT EOL LPAR_T RPAR_T
%token <std::string> VAR STRING
%token <int>         INT
%token <double>      DOUBLE
%token PLUS_T MINUS_T TIMES_T DIVIDE_T POW_T

%type <Pry::node::Node*> Expr Math Assignment
%type <Pry::node::Variable*> Variable
%type <Pry::node::Primitive*> Primitive

%locations

%left PLUS_T MINUS_T
%left TIMES_T DIVIDE_T
%right POW_T

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
    |   Expr EOL_T {} // driver.scope->add_node(std::make_unique<Pry::node::Node>($1));
    ;

Expr:
        Assignment         { std::cout << "variable :)" << std::endl; $$=$1; }
    |   Primitive          { std::cout << "primitive :)" << std::endl; $$=$1; }
    |   Math               { $$=$1; }
    |   LPAR_T Expr RPAR_T { $$=$2; }
    |   Variable           { std::cout << "variable :)" << std::endl; $$=$1; }
    ;

Variable:
      VAR { $$=new Pry::node::Variable(driver.variables->find($1)); }
    ;

Primitive:
        INT    { $$=new Pry::node::Primitive(); }
    |   DOUBLE { $$=new Pry::node::Primitive(); }
    |   STRING { $$=new Pry::node::Primitive(); }
    ;

Math:
        Expr PLUS_T Expr     {}
    |   Expr MINUS_T Expr    {}
    |   Expr TIMES_T Expr    {}
    |   Expr DIVIDE_T Expr   {}
    |   Expr POW_T Expr      {}
    ;

Assignment:
        VAR_T VAR EQ_T Expr {}
    |   VAL_T VAR EQ_T Expr {}
    |   VAR EQ_T Expr       {}
    ;
%%

void  Pry::Parser::error(Pry::location const &l, std::string const &err_message) {
    std::cerr << std::endl;
    std::cerr << "Error: " << err_message << " at " << l << std::endl;
}
