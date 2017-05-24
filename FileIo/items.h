#ifndef ITEMS_H
#define ITEMS_H //items.h
#include "mechanics.h"
#include <iostream>
using namespace std;

//The Item class has a value and a description
class Item
{
    public:
        // Constructors and Destructor
        Item();
        Item(int value, char* description);
        Item(const Item * to_copy);
        Item(istream& in_file,char delim);

        ~Item();

        void copy(const Item& to_copy);
        void display();
        virtual void write_out(ofstream& fileOut, char delim);
    private:
        int value;
        char* description;

};

//The Weapon class represents A weapon in the game.
//It is a type of loot and has at set of attacks.
class Weapon: public Item
{
    public:
        // Constructors and Destructor
        Weapon();
        Weapon(int weapon_value, char* weapon_description, Attack* attacks_vector);
        Weapon(int weapon_value, char* weapon_description, int weapon_damage, int damage_type, char* attack_description);
        Weapon(const Weapon& to_copy);
        ~Weapon();

        void copy(Weapon & to_copy);
        void display();
        virtual void write_out(ofstream& fileOut, char delim);

       Attack* attacks;
       int num_attacks;
};
#endif //items.h