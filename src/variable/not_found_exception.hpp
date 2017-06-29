#ifndef __NOT_FOUND_EXCEPTION_HPP__
#define __NOT_FOUND_EXCEPTION_HPP__

#include <string>
#include <stdexcept>

namespace pry {
    namespace variable {
        class NotFoundException : public std::runtime_error {
        public:
            NotFoundException(std::string name);
            virtual const char* what() const throw();
        private:
            std::string name;
        };
    }
}

#endif /* end of include guard: __NOT_FOUND_EXCEPTION_HPP__ */
