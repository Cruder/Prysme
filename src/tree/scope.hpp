#ifndef __TREE_SCOPE_HPP__
#define __TREE_SCOPE_HPP__

#include <stack>
#include <memory>

#include "list.hpp"

namespace Pry {
    namespace tree {
        class Scope {
        public:
            Scope(List* list);

            void add_node(node::Node* node);

            void increment_depth(List* list);
            void decrement_depth();
        private:
            std::stack<List*> links;
        };
    }
}

#endif /* end of include guard: __TREE_SCOPE_HPP__ */
