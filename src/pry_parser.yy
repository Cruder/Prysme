%skeleton "lalr1.cc"
%require  "3.0"
%debug
%defines
%define api.namespace {Pry}
%define parser_class_name {Parser}

%code requires{
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

%token EOL

%locations

%start Language
%%

Language:
	| Input {  }
	;

Input:
  EOL  { std::cout << "Hello"; }
  ;
