/*auth: AJ Boyd, aboyd3@umbc.edu
  date: 5/11/22
  file: Character.cpp
  desc: implimenation of the Character class
*/

#include <iostream>
#include "Character.h"
using namespace std;

Character::Character(){
  m_name = "Jimmy";
}

Character::Character(string name){
  m_name = name;

}

//setters and getters
void Character::SetName(string name){
  m_name = name;
}
string Character::GetName(){
  return m_name;
}
void Character::SetPrimary(Weapon *pri){
  m_primary = pri;
}
Weapon* Character::GetPrimary(){
  return m_primary;
}
