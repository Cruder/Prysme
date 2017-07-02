#include "scope.hpp"

namespace Pry {
    namespace tree {
        Scope::Scope(List* list) : links() {
            increment_depth(list);
        }

        void Scope::add_node(node::Node* node) {
            links.top()->add_node(node);
        }

        void Scope::increment_depth(List* list) {
            links.push(list);
        }

        void Scope::decrement_depth() {
            links.pop();
        }
    }
}
