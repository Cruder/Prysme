#include "not_found_exception.hpp"
#include "already_defined_exception.hpp"
#include "row.hpp"

namespace pry {
    namespace variable {
        Row::Row() : variables {} {
        }

        Variable* Row::find(std::string name) {
            if(!is_exist(name)) {
                throw NotFoundException(name);
            }
            return variables[name].get();
        }

        void Row::define(std::string name, std::unique_ptr<Variable> variable) {
            if(is_exist(name)) {
                throw AlreadyDefinedException(name);
            }

            variables[name] = std::move(variable);
        }

        bool Row::is_exist(std::string name) {
            return variables.find(name) != variables.end();
        }
    }
}
