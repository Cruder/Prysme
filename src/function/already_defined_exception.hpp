#ifndef __FUNCTION_ALREADY_DEFINED_EXCEPTION_HPP__
#define __FUNCTION_ALREADY_DEFINED_EXCEPTION_HPP__

#include <string>
#include <stdexcept>

namespace Pry {
    namespace function {
        class AlreadyDefinedException : public std::runtime_error {
        public:
            AlreadyDefinedException(std::string name);
            virtual const char* what() const throw();
        private:
            std::string name;
        };
    }
}

#endif /* end of include guard: __FUNCTION_ALREADY_DEFINED_EXCEPTION_HPP__ */
