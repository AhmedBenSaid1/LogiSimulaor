#include "GATEAND.h"
#include <vector>


GateAND::GateAND(const Node& input1 , const Node& input2 , const Node& out):Gate("AND",(vector<Node>){input1,input2},out){}

void GateAND::calc_output_self()
{
    if (output.already_computed)
        return ;

    output.set_value(inputs[0].value && inputs[1].value);
        return;
}



