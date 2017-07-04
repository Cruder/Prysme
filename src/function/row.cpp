#include "not_found_exception.hpp"
#include "already_defined_exception.hpp"
#include "row.hpp"

namespace Pry {
    namespace function {
        Row::Row() : functions {} {
        }

        Function* Row::find(std::string name) {
            if(!is_exist(name)) {
                throw NotFoundException(name);
            }
            return functions[name].get();
        }

        void Row::define(std::string name, std::unique_ptr<Function> function) {
            if(is_exist(name)) {
                throw AlreadyDefinedException(name);
            }

            functions[name] = std::move(function);
        }

        bool Row::is_exist(std::string name) {
            return functions.find(name) != functions.end();
        }

        std::string Row::as_string() const {
            std::string t = "Row [\n";
            for(auto& val : functions) { t += "\t\tName " + val.first + ": " + val.second->as_string() + '\n'; }
            t += "\t]";

            return t;
        }

        std::ostream& operator<<(std::ostream& os, const Row& v) {
            os << v.as_string();
            return os;
        }
    }
}
