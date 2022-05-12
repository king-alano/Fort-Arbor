/*
  auth: AJ Boyd, aboyd3@umbc.edu
  date: 5/11/22
  file: Party.cpp
  desc: implimentation of the Party class
*/

#include <iostream>
#include "CharNode.cpp"
#include "Character.h"
#include "Party.h"
using namespace std;

//defualt Constructor
Party::Party(){
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
}

//getter
int Party::GetSize(){
  return m_size;
}

//iterates through party and displays each PM's name
void Party::Display(){
  if(m_size == 0){
    cout << "Party is empty." << endl;
  }else{
    CharNode *curr = m_head;
    while(curr != nullptr){
      cout << *(curr->GetData()) << "->";

      /*
      if(curr->GetNext() != nullptr){
        cout << curr->GetData()->Get <<
        */
      curr = curr->GetNext();
    }
    cout << "END" << endl;
  }
}

//unless speicailly told, the defualt AddNode() adds a CharNode at the end
void Party::AddNode(Character* character){
  //makes new CharNode
  CharNode *newChar = new CharNode(character);

  //if Party is empty
  if(m_head == nullptr){
    //cout << "party is currently empty" << endl;
    m_head = newChar;
    m_tail = newChar;
  }else{
    m_tail->SetNext(newChar);
    m_tail = newChar;
  }
  m_size++;
}

//overloaded AddNode function that adds a CharNode to a desired location
void Party::AddNode(Character* character, int index){
  if(m_size == 4){
    cout << "Party is full, cannot add new Character." << endl;
  }else{
    //makes a new CharNode
    CharNode *newChar = new CharNode(character);

    //iterates thru Party and adds newChar into Party
    CharNode *curr = m_head;
    CharNode *prev = m_head;
    int count = 0;

    if(index == 0){
      //special case if adding at m_head
      m_head = newChar;
      m_head->SetNext(curr);
    }else if(index == 3){
      //special case if adding at m_tail
      m_tail->SetNext(newChar);
    }else{
      //loops until it gets to the right spot
      while(count != index){
        prev = curr;
        curr = curr->GetNext();
        count++;
      }
      //inserts CharNode
      prev->SetNext(newChar);
      newChar->SetNext(curr);
    }
    m_size++;
  }
}

//removes a CharNode at a certain location
void Party::RemoveNode(int index){
  CharNode *curr = m_head;
  CharNode *prev = m_head;
  int count = 0;

  while(count != index){
    prev = curr;
    curr = curr->GetNext();
    count++;
  }

  CharNode *next = curr->GetNext();
  delete curr;
  prev->SetNext(next);
  m_size--;
}
