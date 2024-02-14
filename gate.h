#pragma once
#ifndef GATE_H_
#define GATE_H_
#include "node.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Gate
{
public:
        string name;
		vector<Node> inputs;
		Node output;


		void show();
        Gate(string inName,vector<Node> inV,Node out):name(inName),inputs(inV),output(out){}
        virtual int calc_output();
        virtual void calc_output_self () =0;
        void configure_for_two_inputs(const Node &input1, const Node &input2, const Node &out);

};

#endif /* GATE_H_ */

