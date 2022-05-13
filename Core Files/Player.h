/*auth: AJ BOYD
  date: 5/11/22
  file: Player.h
  desc: Header file for the Player class which inherits from Character
*/

#ifndef PLAYER_H
#define PLAYER_H

//the Player is a special Character who has an inventory and gold
//when the RPG has actual activities like battle or hunting they will be done using the
//Player object


#include <iostream>
#include <string>
#include <vector>

#include "Item.cpp"
#include "Character.h"
using namespace std;

class Player: public Character{
private:
  vector<Item*> m_inventory; //the Items in the Player's inventory
  int m_gold; //how much gold the Player has
public:
  Player();
  void DisplayInv();
  void AddItem(Item, int);
  Item* InvAt(int);
};

#endif
