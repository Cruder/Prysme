#ifndef __FUNCTION_VARIABLE_HPP__
#define __FUNCTION_VARIABLE_HPP__

#include <string>
#include <variant>

#include "../node/node.hpp"

namespace Pry {
    namespace function {
        class Function {
        public:
            Function(node::Node* node);

            node::Node* exec();

            std::string as_string() const;
            friend std::ostream& operator<<(std::ostream& os, const Function& v);
          private:
            node::Node* node;
        };
    }
}

#endif /* end of include guard: __FUNCTION_VARIABLE_HPP__ */
