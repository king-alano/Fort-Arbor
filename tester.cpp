#include <iostream>
#include "Weapon.cpp"
#include "Character.h"
#include "Party.h"
#include "Party.cpp"
using namespace std;

//for testing pursposes :)

int main(){
  cout << "test 1: making Characters" << endl;
  Character *jim = new Character("Jimmy");
  Character *tom = new Character("Tommy");
  cout << "Characters created." << endl;
  cout << jim->GetName() << endl;
  cout << tom->GetName() << endl;
  cout << "Should output their names above" << endl;
  cout << "---END TEST 1---" << endl;

  cout << endl;
  cout << endl;

  cout << "test 2: adding Characters to Party" << endl;
  Character *frank = new Character("Frank");
  Character *isaac = new Character("Isaac");
  Party *myParty = new Party();
  cout << "Party size (should be 0): " << myParty->GetSize() << endl;
  myParty->AddNode(jim);
  myParty->AddNode(tom);
  myParty->AddNode(frank);
  myParty->AddNode(isaac);
  cout << "Party size (should be 4): " <<  myParty->GetSize() << endl;
  myParty->Display();
  cout << "should output Party member's names" << endl;
  cout << "what if I update the object?" << endl;
  jim->SetName("James");
  myParty->Display();
  cout << "should output Party member's names (but Jimmy is now James)" << endl;
  cout << "---END TEST 2---" << endl;

  cout << endl;
  cout << endl;

  cout << "test 3: giving a Character a Weapon" << endl;
  cout << "jimmy's weapon: jimmy doesn't have one, but..." << endl;
  Weapon *ex = new Weapon("Lion's Roar", "A powerful sword that once belonged to...", "Sword", "Epic", "Melee", "Fire", 12, 8, 144, 144, 1, 6, 0, 100);
  jim->SetPrimary(ex);
  cout << "jimmy's brand new weapon: " << jim->GetPrimary() << endl;
  cout << "should output Jim's weapon" << endl;
  cout << "---END TEST 3---" << endl;

  cout << endl;
  cout << endl;

  return 0;
}
