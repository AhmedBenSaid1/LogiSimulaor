#ifndef CIRCUIT_H_
#define CIRCUIT_H_


# pragma once
# include "node.h"
# include "gate.h"

class Circuit {
public :
vector < Node > inputs ;
vector < Node > outputs ;
vector < Gate * > gates ;
void show_gates () ;
void inputs_to_gates () ;
void internal_outputs_to_inputs () ;
bool are_all_outputs_computed();
void compute () ;
void gates_to_outputs () ;
void reset () ;
void clear_inputs () ;
void load_gates_from_file ( string inFileName ) ;
void load_inputs_from_file ( string inFileName ) ;

};
#endif/* CIRCUIT_H_ */
