#include "GateOR.h"
#include <vector>

GateOR::GateOR(const Node& input1 , const Node& input2 , const Node& out):Gate("OR",(vector<Node>){input1,input2},out)
{

}
void GateOR::calc_output_self()
{
    if (output.already_computed)
        return ;

    output.set_value(inputs[0].value || inputs[1].value);
        return;
}
