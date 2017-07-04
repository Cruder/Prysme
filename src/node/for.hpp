#ifndef __NODE_For_HPP__
#define __NODE_For_HPP__

#include "node.hpp"

namespace Pry {
    namespace node {
        class For : public Node {
        public:
            For();
            For(Node* cond, Node* child, Node* pre, Node* post);
            virtual Node* exec();
        protected:
            virtual std::string type_string() const;
        };
    }
}

#endif /* end of include guard: __NODE_For_HPP__ */
