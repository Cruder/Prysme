#include "scope.hpp"
#include <iostream>
namespace Pry {
    namespace tree {
        Scope::Scope(List* list) : links() {
            increment_depth(list);
        }

        void Scope::add_node(node::Node* node) {
            std::cout << "links size " << links.size() << std::endl;
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
