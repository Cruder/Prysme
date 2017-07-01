#ifndef __PRY_DRIVER_HPP__
#define __PRY_DRIVER_HPP__

#include <memory>
#include <string>
#include "pry_scanner.hpp"
#include "pry_parser.tab.hpp"
#include "variable/table.hpp"
#include "tree/scope.hpp"

namespace Pry {
    class Driver {
    public:
        std::unique_ptr<variable::Table> variables;
        std::unique_ptr<tree::Scope> scope;
    public:
        Driver();

        void parse(const std::string& filename);
    private:
        Parser* parser = nullptr;
        Scanner* scanner = nullptr;

        tree::List node_list {};
    };
}

#endif /* end of include guard: __PRY_DRIVER_HPP__ */
