#ifndef  __NODE_ASSIGNMENT_HPP__
#define  __NODE_ASSIGNMENT_HPP__

#include "node.hpp"
#include "../variable/table.hpp"

namespace Pry {
    namespace node {
        class Assignment : public Node {
        public:
            Assignment();
            Assignment(std::string name, variable::Table* t, Node* child = nullptr);
            virtual Node* exec();
        protected:
            virtual std::string type_string() const;
        private:
            variable::Table* table;
            std::string name;
            bool is_constant = false;
        };
    }
}

#endif /* end of include guard:  __NODE_ASSIGNMENT_HPP__ */
