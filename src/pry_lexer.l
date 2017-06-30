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

"="         { return token::EQ_T;  }
"\n"        { return token::EOL_T; }
"var"       { return token::VAR_T; }
"val"       { return token::VAL_T; }

"+"         { return token::PLUS_T;   }
"-"         { return token::MINUS_T;  }
"*"         { return token::TIMES_T;  }
"/"         { return token::DIVIDE_T; }
"**"        { return token::POW_T;    }
"("         { return token::LPAR_T;   }
")"         { return token::RPAR_T;   }

{num} {
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
    yylval->build<std::string>(yytext);
    return token::STRING;
}
