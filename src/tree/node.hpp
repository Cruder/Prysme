#ifndef __NODE_HPP__
#define __NODE_HPP__

#include <vector>
#include <memory>

namespace pry {
    namespace tree {
        class Node {
        public:
            Node(int _type);

            void add_children(std::unique_ptr<Node> _children);
            Node* exec();
        private:
            int type;
            std::vector<std::unique_ptr<Node>> children;
        };
    }
}

#endif /* end of include guard: __NODE_HPP__ */
