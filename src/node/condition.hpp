#ifndef __NODE_CONDITION_HPP__
#define __NODE_CONDITION_HPP__

#include "node.hpp"

namespace Pry {
    namespace node {
        class Condition : public Node {
        public:
            Condition();
            Condition(Node* cond, Node* child1 = nullptr, Node* child2 = nullptr);
            virtual Node* exec();
        protected:
            virtual std::string type_string() const;
        };
    }
}

#endif /* end of include guard: __NODE_CONDITION_HPP__ */
