#ifndef __NODE_WHILE_HPP__
#define __NODE_WHILE_HPP__

#include "node.hpp"

namespace Pry {
    namespace node {
        class While : public Node {
        public:
            While();
            While(Node* cond, Node* child);
            virtual Node* exec();
        protected:
            virtual std::string type_string() const;
        };
    }
}

#endif /* end of include guard: __NODE_WHILE_HPP__ */
