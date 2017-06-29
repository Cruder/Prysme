#include "node.hpp"

namespace pry {
    namespace tree {
        Node::Node(int _type) : type { _type } {
        }

        void Node::add_children(std::unique_ptr<Node> _children) {
            children.push_back(std::move(_children));
        }

        Node* Node::exec() {
            return nullptr;
        }
    }
}
