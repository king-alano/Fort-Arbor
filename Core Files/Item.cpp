/*
  auth: AJ Boyd, aboyd3@umbc.edu
  date: 5/12/22
  file: Item.cpp
  desc: implimentation of the Item class
*/

#ifndef ITEM_CPP
#define ITEM_CPP

//Items are special objects that can be found, crafted, given, or purchased
//There will be different types of Items eventually i.e
//Consumables--eatable Items that give some boost in battle
//Materials--Items used in crafting
//Crafts--Items created by crafting

#include <iostream>
#include <string>
using namespace std;

class Item{
private:
  string m_name, m_desc, m_tier, m_type;
  int m_quantity = 0; //Item's quantity
public:
  //overloaded constructor
  Item(string name, string desc, string tier, string type){
    m_name = name; //name of Item
    m_desc = desc; //description of Item
    m_tier = tier; //Item's rarity
    m_type = type; //this describes the source of the Item, is it a consumable, material
  }

  //Accessors
  string GetName(){
    return m_name;
  }

  string GetTier(){
    return m_tier;
  }

  string GetDesc(){
    return m_desc;
  }

  string GetType(){
    return m_type;
  }

  int GetQuantity(){
    return m_quantity;
  }

  //other public methods
  //increases the quantity of the Item by a certain emount
  void IncreaseQuantity(int amount){
    m_quantity += amount;
  }

  //decreases the quantity of the Item by a certain emount
  void DecreaseQuantity(int amount){
    m_quantity -= amount;
  }

  //virtual void Use

  //freindly overloaded insertion << operator
  friend ostream &operator<<(ostream &output, Item *i){
    output << i->m_name << " (" << i->m_quantity << ") -- " << i->m_desc << endl;
    return output;
  }
};
#endif
