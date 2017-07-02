#include "algebra_exception.hpp"

namespace Pry {
    namespace node {
        AlgebraException::AlgebraException(std::string type1, std::string type2) :
            runtime_error("Algebra error"),
            type1(type1),
            type2(type2) {
        }

        const char* AlgebraException::what() const throw() {
            std::string error = "";
            error += std::string(runtime_error::what()) + " with type: " + type1 + " and type: " + type2;

            return error.c_str();
        }
    }
}
