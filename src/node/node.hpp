#ifndef __NODE_NODE_HPP__
#define __NODE_NODE_HPP__

#include <vector>
#include <memory>
#include <string>
#include "../variable/primitive_type.hpp"

namespace Pry {
    namespace node {
        class Node {
        public:
            Pry::variable::PrimitiveType value;
        public:
            Node();
            Node(const Pry::variable::PrimitiveType& value);
            virtual ~Node();

            void add_children(Node* child);
            void add_children(std::vector<Node*> child);
            virtual Node* exec();

            virtual std::string as_string(std::size_t space = 0) const;
        protected:
            std::vector<Node*> children;
        protected:
            virtual std::string type_string() const;
        };
    }
}

#endif /* end of include guard: __NODE_NODE_HPP__ */
