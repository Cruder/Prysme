#include <cmath>
#include "math.hpp"
#include "primitive.hpp"
#include "algebra_exception.hpp"

using Pry::node::AlgebraException;
using Pry::variable::primitive_type::class_string;

struct add_visitor {
    Pry::variable::PrimitiveType action(auto&& arg1, auto&& arg2) {
        return arg1 + arg2;
    }

    Pry::variable::PrimitiveType operator()(int arg1, int arg2) {
        return action(arg1, arg2);
    }

    Pry::variable::PrimitiveType operator()(int arg1, double arg2) {
        return action(arg1, arg2);
    }

    Pry::variable::PrimitiveType operator()(double arg1, int arg2) {
        return action(arg1, arg2);
    }

    Pry::variable::PrimitiveType operator()(double arg1, double arg2) {
        return action(arg1, arg2);
    }

    Pry::variable::PrimitiveType operator()(std::string arg1, std::string arg2) {
        return action(arg1, arg2);
    }

    Pry::variable::PrimitiveType operator()(auto&& arg1, auto&& arg2) {
        throw AlgebraException("String", "String");
    }
};
struct sub_visitor {
    Pry::variable::PrimitiveType action(auto&& arg1, auto&& arg2) {
        return arg1 - arg2;
    }

    Pry::variable::PrimitiveType operator()(int arg1, int arg2) {
        return action(arg1, arg2);
    }

    Pry::variable::PrimitiveType operator()(int arg1, double arg2) {
        return action(arg1, arg2);
    }

    Pry::variable::PrimitiveType operator()(double arg1, int arg2) {
        return action(arg1, arg2);
    }

    Pry::variable::PrimitiveType operator()(double arg1, double arg2) {
        return action(arg1, arg2);
    }

    Pry::variable::PrimitiveType operator()(auto&& arg1, auto&& arg2) {
        throw AlgebraException("String", "String");
    }
};
struct mul_visitor {
    Pry::variable::PrimitiveType action(auto&& arg1, auto&& arg2) {
        return arg1 * arg2;
    }

    Pry::variable::PrimitiveType operator()(int arg1, int arg2) {
        return action(arg1, arg2);
    }

    Pry::variable::PrimitiveType operator()(int arg1, double arg2) {
        return action(arg1, arg2);
    }

    Pry::variable::PrimitiveType operator()(double arg1, int arg2) {
        return action(arg1, arg2);
    }

    Pry::variable::PrimitiveType operator()(double arg1, double arg2) {
        return action(arg1, arg2);
    }

    Pry::variable::PrimitiveType operator()(auto&& arg1, auto&& arg2) {
        throw AlgebraException("String", "String");
    }
};
struct div_visitor {
    Pry::variable::PrimitiveType action(auto&& arg1, auto&& arg2) {
        return arg1 / arg2;
    }

    Pry::variable::PrimitiveType operator()(int arg1, int arg2) {
        return action(arg1, arg2);
    }

    Pry::variable::PrimitiveType operator()(int arg1, double arg2) {
        return action(arg1, arg2);
    }

    Pry::variable::PrimitiveType operator()(double arg1, int arg2) {
        return action(arg1, arg2);
    }

    Pry::variable::PrimitiveType operator()(double arg1, double arg2) {
        return action(arg1, arg2);
    }

    Pry::variable::PrimitiveType operator()(auto&& arg1, auto&& arg2) {
        throw AlgebraException("String", "String");
    }
};
struct pow_visitor {
    Pry::variable::PrimitiveType action(auto&& arg1, auto&& arg2) {
        return std::pow(arg1, arg2);
    }

    Pry::variable::PrimitiveType operator()(int arg1, int arg2) {
        return action(arg1, arg2);
    }

    Pry::variable::PrimitiveType operator()(int arg1, double arg2) {
        return action(arg1, arg2);
    }

    Pry::variable::PrimitiveType operator()(double arg1, int arg2) {
        return action(arg1, arg2);
    }

    Pry::variable::PrimitiveType operator()(double arg1, double arg2) {
        return action(arg1, arg2);
    }

    Pry::variable::PrimitiveType operator()(auto&& arg1, auto&& arg2) {
        throw AlgebraException("String", "String");
    }
};

#include <iostream>

namespace Pry {
    namespace node {
        Math::Math() :
            Node() {
        }

        Math::Math(const MathOp& op, Node* child1, Node* child2) :
            Node(),
            op { op } {
            if(child1) { add_children(child1); }
            if(child2) { add_children(child2); }
        }

        Node* Math::exec() {
            auto val1 = children[0]->exec()->value;
            auto val2 = children[1]->exec()->value;

            if(op == MathOp::ADD) { value = std::visit(add_visitor{}, val1, val2); }
            if(op == MathOp::SUB) { value = std::visit(sub_visitor{}, val1, val2); }
            if(op == MathOp::MUL) { value = std::visit(mul_visitor{}, val1, val2); }
            if(op == MathOp::DIV) { value = std::visit(div_visitor{}, val1, val2); }
            if(op == MathOp::POW) { value = std::visit(pow_visitor{}, val1, val2); }
            return this;
        }
    }
}
