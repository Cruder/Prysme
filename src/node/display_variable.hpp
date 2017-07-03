#ifndef __NODE_DISPLAY_VARIABLE_HPP__
#define __NODE_DISPLAY_VARIABLE_HPP__

#include <string>
#include "node.hpp"
#include "../variable/table.hpp"

namespace Pry {
    namespace node {
        class DisplayVariable : public Node {
        public:
            DisplayVariable();
            DisplayVariable(const std::string& name, variable::Table* table);
            virtual Node* exec();

        private:
            std::string name;
            variable::Table* table;
        };
    }
}

#endif /* end of include guard: __NODE_DISPLAY_VARIABLE_HPP__ */
