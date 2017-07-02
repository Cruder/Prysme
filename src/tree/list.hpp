#ifndef __TREE_LIST_HPP__
#define __TREE_LIST_HPP__

#include <vector>
#include <memory>

#include "../node/node.hpp"

namespace Pry {
    namespace tree {
        class List {
        public:
            List();
            ~List();

            void add_node(node::Node* node);

            void exec();
        private:
            std::vector<node::Node*> nodes;
        };
    }
}

#endif /* end of include guard: __TREE_LIST_HPP__ */
