%{
    #include <string>
    #include "pry_scanner.hpp"

    #undef  YY_DECL
    #define YY_DECL int Pry::Scanner::yylex(
        const Pry::Parser::semantic_type* lval,
        Pry::Parser::location_type *loc
    )

    using token = Pry::Parser::token;
}

%option debug
%option yyclass="Pry::Scanner"
%option noyywrap
%option c++

empty    [ \t]+
num      [0-9]
int      {num}+
real     {int}("."{int})?{exp}?
variable [a-zA-Z](?:[a-zA-Z_0-9]+)?[\?!]?

%%

%{
    yylval = lval;
%}


{empty} { /* NOTHING */}
"\n"    { return(token::EOL); }
