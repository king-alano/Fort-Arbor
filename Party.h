/*
  auth: AJ Boyd, aboyd3@umbc.edu
  date: 5/11/22
  file: Party.h
  desc: header file for the Party class
*/

#ifndef PARTY_H
#define PARTY_H

#include <iostream>
#include "CharNode.cpp"
#include "Character.h"
using namespace std;

//another big part of RPGs are parties
//parties are groups of interchangable characters (up to 4) that can enter battles/dungeon crawl
//in this project, the Party is a linked list of Character Nodes that holds the memory address of a certain Character (see CharNode class)

class Party{
private:
  CharNode* m_head;
  CharNode* m_tail;
  int m_size;
public:
  //default constructor
  Party();

  //Getter
  int GetSize();

  //other public functions
  void Display(); //displays CharNode data
  void AddNode(Character *character); //adds a new CharNode as long as m_size != 4 prior to its execution
  void AddNode(Character *character, int); //overloaded AddNode function();
  void RemoveNode(int); //removes a CharNode
};
#endif
