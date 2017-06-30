#ifndef __NODE_NODE_HPP__
#define __NODE_NODE_HPP__

#include <vector>
#include <memory>

namespace Pry {
    namespace node {
        class Node {
        public:
            Node();
            ~Node();

            void add_children(Node* child);
            void add_children(std::vector<Node*> child);
            Node* exec();
        protected:
            std::vector<Node*> children;
        };
    }
}

#endif /* end of include guard: __NODE_NODE_HPP__ */
