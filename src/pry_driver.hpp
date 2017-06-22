#ifndef __PRY_DRIVER_HPP__
#define __PRY_DRIVER_HPP__

#include <memory>
#include <string>
#include "pry_scanner.hpp"
#include "pry_parser.tab.hh"

namespace Pry {
    class Driver {
    public:
        MC_Driver(const &std::string filename) = default;

        void parse();

    private:
        std::unique_ptr<Pry::Parser> parser;
        std::unique_ptr<Pry::Scanner> scanner;
    };
}

#endif /* end of include guard: __PRY_DRIVER_HPP__ */
