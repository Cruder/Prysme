#include "node.hpp"

namespace Pry {
    namespace node {
        Node::Node() : children() {
        }

        void Node::add_children(std::unique_ptr<Node> _children) {
            children.push_back(std::move(_children));
        }

        void Node::add_children(std::vector<std::unique_ptr<Node>> _children) {
            for(auto& c : _children) {
                add_children(std::move(c));
            }
        }
    }
}
