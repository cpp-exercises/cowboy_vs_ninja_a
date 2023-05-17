#ifndef NINJA_H
#define NINJA_H
#include "Character.hpp"

namespace ariel{

    class Ninja : public Character
    {
        int speed;

    public:
        Ninja(string, Point, int, int); // Constractor
        void move(const Character *enemy);//moves the dustanse of its speed(???)
        void slash(Character *other);//if the ninja is alive and the enemy is at most 1 meter,takes 40 hits from enemy.
        virtual string print() override;
    };
}
#endif
  //For nunjas: int speed, there is 3 types of nunjas:
  //YoungNunja - created with speed = 14, 100 hits
  //TrainedNinja - created with speed = 12, 120 hits
  //OldNinja - created with speed = 8, 150 hits
  //Functions: 
  //void move(Caracter &enemy) - moves the dustanse of its speed(???)
  //slash(Character &enemy) - if the ninja is alive and the enemy is at most 1 meter,
  // takes 40 hits from enemy.