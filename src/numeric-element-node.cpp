#include "numeric-element-node.h"

namespace expcounter {

    inline NumericElementNode::NumericElementNode(double val)
        : number(val)
    {
    }

    inline double NumericElementNode::value()
    {
        return number;
    } 
}