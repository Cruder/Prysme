#ifndef __VARIABLE_ALREADY_DEFINED_EXCEPTION_HPP__
#define __VARIABLE_ALREADY_DEFINED_EXCEPTION_HPP__

#include <string>
#include <stdexcept>

namespace pry {
    namespace variable {
        class AlreadyDefinedException : public std::runtime_error {
        public:
            AlreadyDefinedException(std::string name);
            virtual const char* what() const throw();
        private:
            std::string name;
        };
    }
}

#endif /* end of include guard: __VARIABLE_ALREADY_DEFINED_EXCEPTION_HPP__ */
