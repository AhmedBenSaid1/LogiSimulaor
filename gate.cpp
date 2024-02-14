#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include "gate.h"


using namespace std;

/*****************************************************/
void Gate::show()
{
	for (unsigned int i = 0; i<inputs.size(); i++)
	{
	    cout<<inputs[i].name;
		inputs[i].show_value();

	}
	cout << ">> "<<output.name ;
	output.show_value();
	cout << endl;

}
/*****************************************************/

int Gate :: calc_output () {
if ( inputs [0]. already_computed == true && inputs [1]. already_computed== true )
{
// =========
calc_output_self () ;
// =========
//output . already_computed = true ;
return 0;
}
return -1;
}

/*****************************************************/

void Gate::configure_for_two_inputs(const Node &input1, const Node &input2, const Node &out)
{

	inputs.push_back(input1);
	inputs.push_back(input2);
	//Gate("AND",inputs,out);
}
/******************************************************/







