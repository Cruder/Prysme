#ifndef __VARIABLE_TABLE_HPP__
#define __VARIABLE_TABLE_HPP__

#include <vector>
#include "row.hpp"

namespace pry {
    namespace variable {
        class Table {
        public:
            Table();

            void incrementDepth();
            void decrementDepth();

            Variable* find(std::string name);
            void      define(std::string name, std::unique_ptr<Variable> variable);
        private:
            std::vector<std::unique_ptr<Row>> variable_stack;
        };
    }
}

#endif /* end of include guard: __VARIABLE_TABLE_HPP__ */