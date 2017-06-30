#ifndef __NODE_VARIABLE_HPP__
#define __NODE_VARIABLE_HPP__

#include "node.hpp"
#include "../variable/variable.hpp"

namespace Pry {
    namespace node {
        class Variable : public Node {
        public:
            Variable(variable::Variable* v);
            Node* exec();
        private:
            variable::Variable* variable;
        };
    }
}

#endif /* end of include guard: __NODE_VARIABLE_HPP__ */
