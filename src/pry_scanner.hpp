#ifndef __PRY_SCANNER_HPP__
#define __PRY_SCANNER_HPP__

#if !defined(yyFlexLexerOnce)
    #include <FlexLexer.h>
#endif

#include "pry_parser.tab.hpp"
#include "location.hh"

namespace Pry {
    class Scanner : public yyFlexLexer {
        using FlexLexer::yylex;

    public:
        Scanner(std::istream *in, std::ostream* out = nullptr) : yyFlexLexer(in, out) {}
//        virtual ~Scanner() {};

//        virtual int yylex(
//            Pry::Parser::semantic_type * const lval,
//            Pry::Parser::location_type *location
//        );

        int yylex(const Parser::semantic_type* lval, Parser::location_type *loc);
    private:
        /* yyval ptr */
        Parser::semantic_type *yylval = nullptr;
    };
}

#endif /* end of include guard: __PRY_SCANNER_HPP__ */
