#include "GateNOT.h"
#include "Node.h"
#include "gate.h"
#include <vector>

#include <stdio.h>
#include <stdlib.h>


GateNOT::GateNOT(const Node& input, const Node& out):Gate("NOT",(vector<Node>){input},out){}

void GateNOT::calc_output_self()
{
    if (output.already_computed)
        return ;
    output.set_value(!inputs[0].value);
        return;
}
