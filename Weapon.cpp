/*
  auth: AJ Boyd, aboyd3@umbc.edu
  date: 5/11/22
  file: Weapon.cpp
  desc: implimentation of the Weapon class
*/

#ifndef WEAPON_CPP
#define WEAPON_CPP

//how can someone battle demons and monsters without a weapon?
//luckily we have a Weapon class for that
//in battle, a Character can have up to 2 Weapons--1 Primary Weapon (i.e Sword, Spear, Bow, etc.)
//and 1 Secondary Weapon (think Dagger, Crossbow, Pistol)
//currently, there are 7 Primaries and 4 Secondaries
//Weapon's, like some other Items, have tiered rarities.
//Weapons have a LOT of properties that I'll explain in detail further into the code

#include <iostream>
#include <cmath>
using namespace std;

class Weapon{
private:
  string m_name, m_desc, m_type, m_tier, m_range, m_collection;
  int m_baseAtk, m_hitIndex, m_durability, m_maxDurability, m_level, m_toll, m_exp, m_maxExp;
public:
  //overloaded constructor
  Weapon(string n, string desc, string ty, string t, string r, string c, int atk, int hi, int dur, int maxDur, int lvl, int to, int xp, int maxXp){
    m_name = n;                 //name of the Weapon
    m_desc = desc;              //description of Weapon
    m_type = ty;                //Weapon type (Spear, Axe, Sword, Club) 
    m_tier = t;                 //Weapon's rarity
    m_range = r;                //Weapon's range (melee or ranged)
    m_collection = c;           //the collection the Weapon belongs to
    m_baseAtk = atk;            //Weapon's base damage
    m_hitIndex = hi;            //Weapon's hit index--think of the hit index as a n-sided die used in DND. hit indexes are explianed more in the Battle class
    m_durability = dur;         //Weapon's duribility--Weapons don't last forever, but they can be restored
    m_maxDurability = maxDur;
    m_level = lvl;              //Weapon's level
    m_toll = to;                //how much durability is lost per use of Weapon
    m_exp = xp;                 //how much exp the Weapon has
    m_maxExp = maxXp;           //how much exp is needed until the Weapon levels up
  }

  //chckes if the Weapon's exp exceeds its max exp, if so, the Weapon's level increases
  void CheckExp(){
    if(m_exp >= m_maxExp){
      m_level++;
      m_exp -= m_maxExp;
      UpdateStats();
    }
  }

  //if you're reading this comment can i get a "heck yeah"?
  //since all Weapon stats scale off its HP, updates all stats here once the Weapon levels up
  void UpdateStats(){
    //updates m_baseAtk and m_maxDurability depending on its rarity
    if(m_tier == "Common"){
      m_baseAtk = round(3 * m_level + 3);
      m_maxDurability = round(0.5 * m_level +100);
    }else if(m_tier == "Uncommon"){
      m_baseAtk = round(3.2 * m_level + 4);
      m_maxDurability = round(1 * m_level + 110);
    }else if(m_tier == "Rare"){
      m_baseAtk = round(3.6 * m_level + 5);
      m_maxDurability = round(1.75 * m_level + 120);
    }else if(m_tier == "Legendary"){
      m_baseAtk = round(4.2 * m_level + 6);
      m_maxDurability = round(2.75 * m_level + 130);
    }else{
      m_baseAtk = round(5.2 * m_level + 7);
      m_maxDurability = round(4 * m_level + 140);
    }
    m_maxExp = pow(m_level, 2) / 5 + 17 * m_level + 100;
    m_durability = m_maxDurability;
  }

  //freindly overloaded insertion << operator
  friend ostream &operator<<(ostream &output, Weapon *w){
    output << w->m_name << "(" << w->m_type << ") -- BASE ATK: " << w->m_baseAtk << "  DURABILITY: " << w->m_durability << "/" << w->m_maxDurability << "  LVL: " << w->m_level << " (" << w->m_exp << "/" << w->m_maxExp << " exp)";
    return output;
  }
};
#endif
