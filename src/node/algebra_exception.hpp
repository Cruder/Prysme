#ifndef __VARIABLE_ALREADY_DEFINED_EXCEPTION_HPP__
#define __VARIABLE_ALREADY_DEFINED_EXCEPTION_HPP__

#include <string>
#include <stdexcept>

namespace Pry {
    namespace node {
        class AlgebraException : public std::runtime_error {
        public:
            AlgebraException(std::string type1, std::string type2);
            virtual const char* what() const throw();
        private:
            std::string type1;
            std::string type2;
        };
    }
}

#endif /* end of include guard: __VARIABLE_ALREADY_DEFINED_EXCEPTION_HPP__ */
