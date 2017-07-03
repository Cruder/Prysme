#include "not_found_exception.hpp"
#include "already_defined_exception.hpp"
#include "row.hpp"

namespace Pry {
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

        std::string Row::as_string() const {
            std::string t = "Row [\n";
            for(auto& val : variables) { t += "\t\tName " + val.first + ": " + val.second->as_string() + '\n'; }
            t += "\t]";

            return t;
        }

        std::ostream& operator<<(std::ostream& os, const Row& v) {
            os << v.as_string();
            return os;
        }
    }
}
