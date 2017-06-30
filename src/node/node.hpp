#ifndef __NODE_NODE_HPP__
#define __NODE_NODE_HPP__

#include <vector>
#include <memory>

namespace Pry {
    namespace node {
        class Node {
        public:
            Node();

            void add_children(std::unique_ptr<Node> _children);
            void add_children(std::vector<std::unique_ptr<Node>> _children);
            virtual Node* exec() = 0;
        protected:
            std::vector<std::unique_ptr<Node>> children;
        };
    }
}

#endif /* end of include guard: __NODE_NODE_HPP__ */
