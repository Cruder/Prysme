#ifndef __SCOPE_HPP__
#define __SCOPE_HPP__

#include <stack>
#include <memory>

#include "list.hpp"

namespace pry {
    namespace tree {
        class Scope {
        public:
            Scope(List* list);

            void add_node(std::unique_ptr<Node> node);

            void increment_depth(List* list);
            void decrement_depth();
        private:
            std::stack<List*> links;
        };
    }
}

#endif /* end of include guard: __SCOPE_HPP__ */
