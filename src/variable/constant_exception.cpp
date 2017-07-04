#include "constant_exception.hpp"

namespace Pry {
    namespace variable {
        ConstantException::ConstantException(std::string name) :
            runtime_error("Variable is constant"),
            name(name) {
        }

        const char* ConstantException::what() const throw() {
            std::string error = "";
            error += std::string(runtime_error::what()) + ": " + name;

            return error.c_str();
        }
    }
}
