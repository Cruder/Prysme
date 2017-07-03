#include "bool_comparator.hpp"
#include "algebra_exception.hpp"

#include <iostream>

using BoolOp = Pry::node::BoolOp;
using Pry::node::AlgebraException;

struct bool_visitor {
    Pry::variable::PrimitiveType action(BoolOp op, auto&& lhs, auto&& rhs) {
        if(op == BoolOp::EQ)    { return lhs == rhs; }
        if(op == BoolOp::NEQ)   { return lhs != rhs; }
        if(op == BoolOp::INF)   { return lhs <  rhs; }
        if(op == BoolOp::INFEQ) { return lhs <= rhs; }
        if(op == BoolOp::SUP)   { return lhs >  rhs; }
        if(op == BoolOp::SUPEQ) { return lhs >= rhs; }
    }

    Pry::variable::PrimitiveType operator()(Pry::node::BoolOp op, int lhs, int rhs) {
        return action(op, lhs, rhs);
    }

    Pry::variable::PrimitiveType operator()(Pry::node::BoolOp op, int lhs, double rhs) {
        return action(op, lhs, rhs);
    }

    Pry::variable::PrimitiveType operator()(Pry::node::BoolOp op, int lhs, char rhs) {
        return action(op, lhs, rhs);
    }

    Pry::variable::PrimitiveType operator()(Pry::node::BoolOp op, double lhs, int rhs) {
        return action(op, lhs, rhs);
    }

    Pry::variable::PrimitiveType operator()(Pry::node::BoolOp op, double lhs, double rhs) {
        return action(op, lhs, rhs);
    }

    Pry::variable::PrimitiveType operator()(Pry::node::BoolOp op, double lhs, char rhs) {
        return action(op, lhs, rhs);
    }

    Pry::variable::PrimitiveType operator()(Pry::node::BoolOp op, std::string lhs, std::string rhs) {
        if(op == BoolOp::EQ || op == BoolOp::NEQ) { return action(op, lhs, rhs); }
        throw AlgebraException("String", "String");
    }

    Pry::variable::PrimitiveType operator()(Pry::node::BoolOp op, char lhs, char rhs) {
        return action(op, lhs, rhs);
    }

    Pry::variable::PrimitiveType operator()(Pry::node::BoolOp op, auto&& lhs, auto&& rhs) {
        throw AlgebraException("String", "String");
    }
};

struct bool_visitor2 {
    Pry::variable::PrimitiveType operator()(auto&& lhs, auto&& rhs) {
        return 0;
    }
};

namespace Pry {
    namespace node {
        BoolComparator::BoolComparator() :
            Node() {
        }

        BoolComparator::BoolComparator(const BoolOp& op, Node* child1, Node* child2) :
            Node(),
            op { op } {
            if(child1) { add_children(child1); }
            if(child2) { add_children(child2); }
        }

        Node* BoolComparator::exec() {
            auto val1 = children[0]->exec()->value;
            auto val2 = children[1]->exec()->value;

            std::cout << "Comparator" << std::endl;
            std::cout << "1. " << variable::primitive_type::as_string(val1) << variable::primitive_type::class_string(val1) << std::endl;
            std::cout << "2. " << variable::primitive_type::as_string(val2) << variable::primitive_type::class_string(val2) << std::endl;

            value = std::visit(bool_visitor2{}, val1, val2);

            return this;
        }
    }
}
