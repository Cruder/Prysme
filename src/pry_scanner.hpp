#ifndef __PRY_SCANNER_HPP__
#define __PRY_SCANNER_HPP__

#if !defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "pry_parser.tab.hh"
#include "location.hh"

namespace Pry {
    class Scanner : public yyFlexLexer {
        using FlexLexer::yylex;

    public:
        Scanner(std::istream *in) : yyFlexLexer(in) {}

        virtual int yylex(
            Pry::Parser::semantic_type * const lval,
            Pry::Parser::location_type *location
        );
    private:
        /* yyval ptr */
        Pry::Parser::semantic_type *yylval = nullptr;
    };
}

#endif /* end of include guard: __PRY_SCANNER_HPP__ */
