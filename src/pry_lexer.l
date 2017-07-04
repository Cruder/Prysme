%option debug
%option yyclass="Pry::Scanner"
%option noyywrap
%option c++
%{
    #include <string>
    #include "src/pry_scanner.hpp"

    #undef  YY_DECL
    #define YY_DECL int Pry::Scanner::yylex(const Pry::Parser::semantic_type* lval, Pry::Parser::location_type *loc)

    using token = Pry::Parser::token;
    using MathOp = Pry::node::MathOp;
    using BoolOp = Pry::node::BoolOp;

    #define yyterminate() return token::EOL
    #define YY_USER_ACTION loc->step(); loc->columns(yyleng);
%}

empty    [ \t]+
num      [0-9]
int      {num}+
real     {int}("."{int})?
string   \"((?:.+)?)\"
variable [a-zA-Z](?:[a-zA-Z_0-9]+)?[\?!]?
comment  [#].+

%%
%{
    yylval = (Pry::Parser::semantic_type *) lval;
%}

{empty}     { /* NOTHING */}
{comment}   { return token::COMMENT; }

"%tree-view" { return token::OPT_TREE_VIEW; }

"display_variable_table" { return token::DSP_VT; }
"display_variable"       { return token::DSP_V;  }

"="         { return token::EQ_T;  }
"\n"        { return token::EOL_T; }
"var"       { return token::VAR_T; }
"val"       { return token::VAL_T; }

"=="        { yylval->build<BoolOp>(BoolOp::EQ);    return token::COND_EQ_T;    }
"!="        { yylval->build<BoolOp>(BoolOp::NEQ);   return token::COND_NEQ_T;   }
"<"         { yylval->build<BoolOp>(BoolOp::INF);   return token::COND_INF_T;   }
"<="        { yylval->build<BoolOp>(BoolOp::INFEQ); return token::COND_INFEQ_T; }
">"         { yylval->build<BoolOp>(BoolOp::SUP);   return token::COND_SUP_T;   }
">="        { yylval->build<BoolOp>(BoolOp::SUPEQ); return token::COND_SUPEQ_T; }

"+"         { yylval->build<MathOp>(MathOp::ADD); return token::PLUS_T;   }
"-"         { yylval->build<MathOp>(MathOp::SUB); return token::MINUS_T;  }
"*"         { yylval->build<MathOp>(MathOp::MUL); return token::TIMES_T;  }
"/"         { yylval->build<MathOp>(MathOp::DIV); return token::DIVIDE_T; }
"**"        { yylval->build<MathOp>(MathOp::POW); return token::POW_T;    }
"("         { return token::LPAR_T;   }
")"         { return token::RPAR_T;   }

"if"        { return token::IF_T; }
"else"      { return token::ELSE_T; }
"do"        { yylval->build<Pry::tree::List*>(new Pry::tree::List()); return token::DO_T; }
"end"       { return token::END_T; }
"while"     { return token::WHILE_T; }
"|"         { return token::PIPE_T; }
"for"       { return token::FOR_T; }

{int} {
    yylval->build<int>(atoi(yytext));
    return token::INT;
}

{real} {
    yylval->build<double>(atof(yytext));
    return token::DOUBLE;
}

{variable} {
    yylval->build<std::string>(yytext);
    return token::VAR;
}

{string} {
    std::string txt(yytext);

    yylval->build<std::string>(txt.substr(1, txt.size() - 2));

    return token::STRING;
}
