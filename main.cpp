#include <iostream>
#include <string>
#include "circuit.h"
#include "node.h"
#include "gate.h"
#include "GATEAND.h"
#include "gateOR.h"
#include "gateNOT.h"

#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
/*
int X;
Node A("A");
Node B("B");
Node C("C");
A.set_value(false);
B.set_value(false);
std::cout << "Node A: Value= ";
A.show_value();
cout<<"\n";
std::cout << "Node B: Value= ";
B.show_value();
cout<<"\n";
std::cout << "Node C: Value= ";
C.show_value();
cout<<"\n";

GateOR G1 ( Node ("I1",false ) , Node ("I2",false ) , Node ("O") ) ;
G1.calc_output_self();
G1.show();
GateNOT G2 ( Node ("I1",true )  , Node ("O") ) ;
G2.calc_output_self();
G2.show();
GateAND G1 ( Node ("I1") , Node ("I2") , Node ("O") ) ;
G1.show_truth_table(&G1);
*/




/*/
Circ . gates . push_back ( new GateAND ( Node ("I1") , Node ("I2") , Node ("A") ) ) ;
Circ . gates . push_back ( new GateOR ( Node ("I3") , Node ("I4") , Node ("B") ) ) ;
Circ . gates . push_back ( new GateAND ( Node ("B") , Node ("I5") , Node ("C") ) ) ;
Circ . gates . push_back ( new GateOR ( Node ("A") , Node ("C") , Node ("O1") ) ) ;
Circ . gates . push_back ( new GateOR ( Node ("C") , Node ("I6") , Node ("O3") ) ) ;
Circ . gates . push_back ( new GateNOT ( Node ("C") , Node ("O2") ) ) ;
Circ . inputs . push_back ( Node ("I1",false ) ) ;
Circ . inputs . push_back ( Node ("I2",true ) ) ;
Circ . inputs . push_back ( Node ("I3",false ) ) ;
Circ . inputs . push_back ( Node ("I4",false ) ) ;
Circ . inputs . push_back ( Node ("I5",true ) ) ;
Circ . inputs . push_back ( Node ("I6",true ) ) ;
Circ . outputs . push_back ( Node ("O1") ) ;
Circ . outputs . push_back ( Node ("O2") ) ;
Circ . outputs . push_back ( Node ("O3") ) ;
*/


Circuit Circ ;
Circ.load_gates_from_file("circuit_gate.txt");
Circ.load_inputs_from_file ("inputs.txt" );
/*Circ.compute();
Circ.show_gates();*/




/*Circ . compute () ;
Circ . compute () ;
Circ . compute () ;
Circ . compute () ;
Circ . compute () ;
Circ . compute () ;
Circ . compute () ;
Circ . compute () ;
Circ . compute () ;
Circ . compute () ;
Circ . compute () ;
Circ . compute () ;*/

cout<<endl;

//cout<<Circ.are_all_outputs_computed();


//Circ.show_gates();
//Circ.clear_inputs ();
//cout<<"/*****************************/\n";
//Circ.show_gates();
/*
vector<Node> k={A,B};
Gate AA("and",k,C);

AA.calc_output();
AA.show();
*/

//Circ.load_gates_from_file ( "circuit_gate.txt" );




return 0;
}

