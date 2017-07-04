#include "already_defined_exception.hpp"

namespace Pry {
    namespace function {
        AlreadyDefinedException::AlreadyDefinedException(std::string name) :
            runtime_error("Function already defined"),
            name(name) {
        }

        const char* AlreadyDefinedException::what() const throw() {
            std::string error = "";
            error += std::string(runtime_error::what()) + ": " + name;

            return error.c_str();
        }
    }
}
