#ifndef __TREE_LIST_HPP__
#define __TREE_LIST_HPP__

#include <vector>
#include <memory>

#include "../node/node.hpp"

namespace pry {
    namespace tree {
        class List {
        public:
            List();

            void add_node(std::unique_ptr<node::Node> node);

            void exec();
        private:
            std::vector<std::unique_ptr<node::Node>> nodes;
        };
    }
}

#endif /* end of include guard: __TREE_LIST_HPP__ */
