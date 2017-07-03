#ifndef __NODE_MATH_HPP__
#define __NODE_MATH_HPP__

#include "node.hpp"

namespace Pry {
    namespace node {
        enum class MathOp { ADD, SUB, MUL, DIV, POW };

        class Math : public Node {
        public:
            Math();
            Math(const MathOp& op, Node* child1 = nullptr, Node* child2 = nullptr);
            virtual Node* exec();
        protected:
            virtual std::string type_string() const;
        private:
            MathOp op;
        };
    }
}

#endif /* end of include guard: __NODE_MATH_HPP__ */
