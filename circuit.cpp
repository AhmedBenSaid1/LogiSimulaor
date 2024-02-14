#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "Node.h"
#include "gate.h"
#include "GateOR.h"
#include "GATEAND.h"
#include "GateNOT.h"
#include "circuit.h"
#include <sstream>

using namespace std;

/***********************************************/

void Circuit::show_gates()
{
	for (unsigned int i = 0; i< this->gates.size(); i++)
    {
        cout<<"Gate"<<this->gates[i]->name<<" << ";
        this->gates[i]->show();
    }
}

/*********************************************/

void Circuit::inputs_to_gates () {

    for (unsigned int i = 0; i< (this->inputs.size()); i++)
    {
    for (unsigned int j = 0; j< this->gates.size(); j++)
    {
    for (unsigned int k = 0; k< this->gates[j]->inputs.size(); k++)
    {
    if((this->inputs[i].name)==(this->gates[j]->inputs[k].name))
        (this->gates[j]->inputs[k]).set_value((this->inputs[i].value));
    }}}}

/*********************************************/

void Circuit::internal_outputs_to_inputs ()
{
    for (unsigned int i = 0; i< (this->gates.size()); i++)
        {
        for (unsigned int j = 0; j< this->gates.size(); j++)
            {
            for (unsigned int k = 0; k< this->gates[j]->inputs.size(); k++)
                {
                if((this->gates[i]->inputs[k].name)==(this->gates[j]->output.name))
                    {(this->gates[i]->inputs[k]).set_value((this->gates[j]->output.value));
                    }

    }}}}

/*********************************************/

bool Circuit::are_all_outputs_computed()
{

for (unsigned int i = 0; i< (this->gates.size()); i++)
{
   if(!this->gates[i]->output.already_computed)
        return false;

}
return true;
}

/*********************************************/

void Circuit::compute ()
{
    this->inputs_to_gates ();
    while (!this->are_all_outputs_computed())
{
    for (unsigned int i = 0; i< (this->gates.size()); i++)
        {gates[i]->calc_output_self();
        this->internal_outputs_to_inputs ();
        }
    this->gates_to_outputs();
}}

/*********************************************/

void Circuit::gates_to_outputs()
{
    for (unsigned int i = 0; i< (this->gates.size()); i++)
    {for (unsigned int j = 0; j< this->outputs.size(); j++)
    {
        if((this->outputs[j].name)==(this->gates[i]->output.name))
        this->outputs[j].set_value(this->gates[i]->output.value);
    }}}

/*********************************************/

void Circuit::reset () {
    for (unsigned int i = 0; i< (this->gates.size()); i++)
    {
    for (unsigned int j = 0; j< this->gates[i]->inputs.size(); j++)
    gates[i]->inputs[j].already_computed=false;
    gates[i]->output.already_computed=false;
}}

/*********************************************/

void Circuit::clear_inputs () {
    for (unsigned int i = 0; i< (this->inputs.size()); i++)
    {
    inputs[i].already_computed=false;
    }}

/*********************************************/

void Circuit::load_gates_from_file ( string inFileName )
{
    vector<string> ligne_type = {"INPUT", "OUTPUT", "AND", "OR", "NOT"};
	cout << "    Circuit D'APRES Description    " << endl;
	string line;
	ifstream Circuit_Fichier (inFileName);
	while (getline(Circuit_Fichier, line))
	{
		string mot;
		vector<string> ligne_vecteur(0);
		stringstream ss(line);

		while (getline(ss, mot,' '))
		{
            ligne_vecteur.push_back(mot);
		}

if  (ligne_vecteur[0]==ligne_type[0]) {
for(unsigned int i=1;i<ligne_vecteur.size();i++)
        {this -> inputs . push_back ( Node (ligne_vecteur[i],false ) ) ;}
}

    if  (ligne_vecteur[0]==ligne_type[1]){
        for (unsigned int i=1;i<ligne_vecteur.size();i++)
        this -> outputs . push_back ( Node (ligne_vecteur[i]) ) ;
    }
        if  (ligne_vecteur[0]==ligne_type[2]){

this -> gates . push_back ( new GateAND ( Node (ligne_vecteur[2]) , Node (ligne_vecteur[3]) , Node (ligne_vecteur[1]) ) ) ;
        }
        if  (ligne_vecteur[0]==ligne_type[3]){
this -> gates . push_back ( new GateOR ( Node (ligne_vecteur[2]) , Node (ligne_vecteur[3]) , Node (ligne_vecteur[1]) ) ) ;
        }
         if  (ligne_vecteur[0]==ligne_type[4]){
            this -> gates . push_back ( new GateNOT ( Node (ligne_vecteur[2]) , Node (ligne_vecteur[1]) ) ) ;
         }
}
Circuit_Fichier.close();
}

/**********************************************/

void Circuit::load_inputs_from_file ( string inFileName )
{

	string line;
	ifstream Outputs_Fichier (inFileName);
	getline(Outputs_Fichier, line);
    int x=stoi(line);
    cout <<"-------------->"<<x<<endl;
	for (unsigned int j=1;j<=x;j++){
	 getline(Outputs_Fichier, line);
        cout <<"*************************************************"<<endl;
	    cout << line<<endl;
        for (unsigned int i=0;i<line.size();i++)
        {if (line[i]=='0')
        {cout<<"  V  "<<endl;
            this->inputs[i].set_value(false);}
            else {if (line[i]=='1'){
        this->inputs[i].set_value(true);
        cout<<"  V  "<<endl;
        }}}
        this->compute();
		this->show_gates();
        }Outputs_Fichier.close();}

/*********************************************/

