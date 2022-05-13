#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include "Weapon.cpp"
using namespace std;

class Character{
private:
  string m_name;
  Weapon *m_primary;
  /*stats
    strength(STR) -- physical damage
    defense(DEF) -- damage mitigation
    dexterity(DEX) -- accuracy
    agility(AGI) -- evasion
    intelligence(INT) -- magic damage
    luck (LUK) -- crit rate
  */

  //my idea originally was to do sort of a skill point system at the beginning
  //of the game that allowed the player to adjust their starting stats.
  //however, in a text-based game, i figured that would be hard to impliment efficiently.
  //instead, i think the game should have D&D classes, and the Player's stats
  //get initialized based on which class they picked
  int m_str, m_def, m_dex, m_agi, m_int, m_luk;
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

