#ifndef __PRY_DRIVER_HPP__
#define __PRY_DRIVER_HPP__

#include <memory>
#include <string>
#include "variable/table.hpp"
#include "function/table.hpp"
#include "tree/scope.hpp"

#include "pry_scanner.hpp"
#include "pry_parser.tab.hpp"

namespace Pry {
    class Driver {
    public:
        std::unique_ptr<variable::Table> variables;
        std::unique_ptr<function::Table> functions;
        std::unique_ptr<tree::Scope> scope;
    public:
        Driver();

        void parse(const std::string& filename);
        void enable_tree_view() { tree_view = true; }
    private:
        Parser* parser = nullptr;
        Scanner* scanner = nullptr;

        tree::List node_list {};
        bool tree_view = false;
    };
}

#endif /* end of include guard: __PRY_DRIVER_HPP__ */
