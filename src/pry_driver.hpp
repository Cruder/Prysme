#ifndef __PRY_DRIVER_HPP__
#define __PRY_DRIVER_HPP__

#include <memory>
#include <string>
#include "pry_scanner.hpp"
#include "pry_parser.tab.hpp"

namespace Pry {
    class Driver {
    public:
        Driver();

        void parse(const std::string& filename);
    private:
        Pry::Parser* parser = nullptr;
        Pry::Scanner* scanner = nullptr;
    };
}

#endif /* end of include guard: __PRY_DRIVER_HPP__ */
