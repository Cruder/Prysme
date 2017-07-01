#ifndef __VARIABLE_ROW_HPP__
#define __VARIABLE_ROW_HPP__

#include <map>
#include <memory>
#include "variable.hpp"

namespace Pry {
    namespace variable {
        class Row {
        public:
            Row();

            Variable* find(std::string name);
            void      define(std::string name, std::unique_ptr<Variable> variable);

            bool      is_exist(std::string name);
        private:
            std::map<std::string, std::unique_ptr<Variable>> variables;
        };
    }
}

#endif /* end of include guard: __VARIABLE_ROW_HPP__ */
