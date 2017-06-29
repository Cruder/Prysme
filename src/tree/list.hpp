#ifndef __LIST_HPP__
#define __LIST_HPP__

#include <vector>
#include <memory>

#include "node.hpp"

namespace pry {
    namespace tree {
        class List {
        public:
            List();

            void add_node(std::unique_ptr<Node> node);

            void exec();
        private:
            std::vector<std::unique_ptr<Node>> nodes;
        };
    }
}

#endif /* end of include guard: __LIST_HPP__ */
