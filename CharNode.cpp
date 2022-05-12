#ifndef CHARNODE_CPP
#define CHARNODE_CPP

//CharNodes are the nodes of the Party linked list
//they come fitted with a head, a tail, and a Character pointer that holds the memory address of a Character
//since it holds the memory of a Character, if that Character's properties are changed, the info in the CharNode will update with it

#include "Character.h"
using namespace std;

class CharNode{
private:
  Character *m_charData; //the data stored in the Node is a Character's memory address
  CharNode *m_next;
public:
  //overloaded constructor
  CharNode(Character *data){
    //cout << "CharNode created)" << endl;
    m_charData = data;
    m_next = nullptr;
  }

  //Getters and Setters
  //GetData() returns the memory address of the data
  Character* GetData(){
    return m_charData;
  }
  //sets data
  void SetData(Character *data){
    m_charData = data;
  }
  //gets m_next
  CharNode* GetNext(){
    return m_next;
  }
  //sets m_next
  void SetNext(CharNode *next){
    m_next = next;
  }
};

#endif
