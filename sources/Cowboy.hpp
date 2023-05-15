#include "Character.hpp"

namespace ariel{

    class Cowboy : public Character
    {
        int numOfBullets;

    public:
        Cowboy(string, Point, int, int); // Constractor (created with 6 bullets and 110 hits)
        void shoot(const Character &enemy);//if the cowboy is alive, shoot 1 bullet, take 10 hit from enemy.
        bool hasboolets();//if exists bullets in stack
        string print() override;
        void reload();//reload the gun with 6 bullets
    };
}
  //For cowboys: int numOfBullets (created with 6 bullets and 110 hits)
  //Functions:
  //shoot(Character &enemy), if the cowboy is alive, shoot 1 bullet, take 10 hit from enemy.
  //bool hasboolets() - if exists bullets in stack
  //void reload() - reload the gun with 6 bullets