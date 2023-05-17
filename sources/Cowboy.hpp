#ifndef COWBOY_H
#define COWBOY_H
#include "Character.hpp"

namespace ariel{

    class Cowboy : public Character
    {
        int numOfBullets;

    public:
        Cowboy(string, Point); // Constractor (created with 6 bullets and 110 hits)
        void shoot(const Character *enemy);//if the cowboy is alive, shoot 1 bullet, take 10 hit from enemy.
        bool hasboolets();//if exists bullets in stack
        virtual string print() override;
        void reload();//reload the gun with 6 bullets
        int getBullets();
    };
}
#endif
  //For cowboys: int numOfBullets (created with 6 bullets and 110 hits)
  //Functions:
  //shoot(Character &enemy), if the cowboy is alive, shoot 1 bullet, take 10 hit from enemy.
  //bool hasboolets() - if exists bullets in stack
  //void reload() - reload the gun with 6 bullets