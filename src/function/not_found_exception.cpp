#include "not_found_exception.hpp"

namespace Pry {
    namespace function {
        NotFoundException::NotFoundException(std::string name) :
            runtime_error("Function not found"),
            name(name) {
        }

        const char* NotFoundException::what() const throw() {
            std::string error = "";
            error += std::string(runtime_error::what()) + ": " + name;

            return error.c_str();
        }
    }
}
