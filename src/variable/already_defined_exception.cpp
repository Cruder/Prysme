#include "already_defined_exception.hpp"

namespace Pry {
    namespace variable {
        AlreadyDefinedException::AlreadyDefinedException(std::string name) :
            runtime_error("Variable already defined"),
            name(name) {
        }

        const char* AlreadyDefinedException::what() const throw() {
            std::string error = "";
            error += std::string(runtime_error::what()) + ": " + name;

            return error.c_str();
        }
    }
}
