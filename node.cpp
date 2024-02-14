#include "Node.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


Node::Node(string inName):name(inName),already_computed(false){}
Node::Node(string inName, bool inValue):name(inName),value(inValue),already_computed(true){}


/******************************************************/

void Node::set_value(bool inValue)
{
    value=inValue;
	already_computed=true;
}

/******************************************************/

void Node::show_value()
{
	if (already_computed==false)
	{
		cout << " : ?";
	} else if (already_computed==true)
	{
		cout <<" : "<< value;
	}
	cout<<" ";
}

/*******************************************************/
