#ifndef __NODE_BOOL_COMPARATOR_HPP__
#define __NODE_BOOL_COMPARATOR_HPP__

#include "node.hpp"

namespace Pry {
    namespace node {
        enum class BoolOp { EQ, NEQ, INF, INFEQ, SUP, SUPEQ };

        class BoolComparator : public Node {
        public:
            BoolComparator();
            BoolComparator(const BoolOp& op, Node* child1 = nullptr, Node* child2 = nullptr);
            virtual Node* exec();

        private:
            BoolOp op;
        };
    }
}

#endif /* end of include guard: __NODE_BOOL_COMPARATOR_HPP__ */
