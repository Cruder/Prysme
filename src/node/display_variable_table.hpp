#ifndef __NODE_DISPLAY_VARIABLE_TABLE_HPP__
#define __NODE_DISPLAY_VARIABLE_TABLE_HPP__

#include <string>
#include "node.hpp"
#include "../variable/table.hpp"

namespace Pry {
    namespace node {
        class DisplayVariableTable : public Node {
        public:
            DisplayVariableTable();
            DisplayVariableTable(variable::Table* table);
            virtual Node* exec();
        protected:
            virtual std::string type_string() const;
        private:
            variable::Table* table;
        };
    }
}

#endif /* end of include guard: __NODE_DISPLAY_VARIABLE_TABLE_HPP__ */
