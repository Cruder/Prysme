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

    #define yyterminate() return(token::EOL)
    #define YY_USER_ACTION loc->step(); loc->columns(yyleng);
%}

empty    [ \t]+
num      [0-9]
int      {num}+
real     {int}("."{int})?{exp}?
variable [a-zA-Z](?:[a-zA-Z_0-9]+)?[\?!]?

%%
%{
    yylval = (Parser::semantic_type *) lval;
%}

{empty} { /* NOTHING */}
"\n"    { return(token::EOL); }
