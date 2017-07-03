#include "bool_comparator.hpp"
#include "algebra_exception.hpp"

#include <iostream>

using BoolOp = Pry::node::BoolOp;
using Pry::node::AlgebraException;

struct bool_visitor {
    bool action(BoolOp op, auto&& lhs, auto&& rhs) {
        if(op == BoolOp::EQ)    { return lhs == rhs; }
        if(op == BoolOp::NEQ)   { return lhs != rhs; }
        if(op == BoolOp::INF)   { return lhs <  rhs; }
        if(op == BoolOp::INFEQ) { return lhs <= rhs; }
        if(op == BoolOp::SUP)   { return lhs >  rhs; }
        if(op == BoolOp::SUPEQ) { return lhs >= rhs; }

        return false;
    }

    bool operator()(BoolOp op, int lhs, int rhs) {
        return action(op, lhs, rhs);
    }

    bool operator()(BoolOp op, int lhs, double rhs) {
        return action(op, lhs, rhs);
    }

    bool operator()(BoolOp op, int lhs, char rhs) {
        return action(op, lhs, rhs);
    }

    bool operator()(BoolOp op, double lhs, int rhs) {
        return action(op, lhs, rhs);
    }

    bool operator()(BoolOp op, double lhs, double rhs) {
        return action(op, lhs, rhs);
    }

    bool operator()(BoolOp op, double lhs, char rhs) {
        return action(op, lhs, rhs);
    }

    bool operator()(BoolOp op, std::string lhs, std::string rhs) {
        if(op == BoolOp::EQ || op == BoolOp::NEQ) { return action(op, lhs, rhs); }
        throw AlgebraException("String", "String");
    }

    bool operator()(BoolOp op, char lhs, char rhs) {
        return action(op, lhs, rhs);
    }

    bool operator()(BoolOp op, bool lhs, bool rhs) {
        if(op == BoolOp::EQ || op == BoolOp::NEQ) { return action(op, lhs, rhs); }
        throw AlgebraException("Bool", "Bool");
    }

    bool operator()(BoolOp op, auto&& lhs, auto&& rhs) {
        throw AlgebraException("UKN", "UKN");
    }
};

namespace Pry {
    namespace node {
        using BoolOpVar = std::variant<BoolOp>;

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
            BoolOpVar op_t = op;

            value = std::visit(bool_visitor{}, op_t, val1, val2);

            return this;
        }

        std::string BoolComparator::type_string() const { return "BoolComparator"; }
    }
}
