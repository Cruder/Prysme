#ifndef __NODE_PRIMITIVE_HPP__
#define __NODE_PRIMITIVE_HPP__

#include "node.hpp"

namespace Pry {
    namespace node {
        class Primitive : public Node {
        public:
            Primitive();
            Primitive(const Pry::variable::PrimitiveType& type);
            virtual Node* exec();
        };
    }
}

#endif /* end of include guard: __NODE_PRIMITIVE_HPP__ */
