/*
  auth: AJ Boyd, aboyd3@umbc.edu
  date: 5/11/22
  file: Character.h
  desc: header file for the Character class
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include "Weapon.cpp"
using namespace std;

//naturally, a RPG needs Characters. 
//although the Character class is small now, it will progressively get bigger

class Character{
private:
  string m_name;
  Weapon *m_primary;
public:
  Character(); //default constructor
  Character(string); //overloaded constructor
  string GetName();
  void SetName(string);
  void SetPrimary(Weapon*);
  Weapon* GetPrimary();
  //friendly overloaded insertion operator
  friend ostream &operator<< (ostream &output, Character& myChar){
    output << myChar.m_name;
    return output;
  }
};
#endif
