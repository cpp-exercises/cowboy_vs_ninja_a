#include "Character.hpp"


namespace ariel{
    using namespace std;
       Character::Character(string _name, Point _location, int _hits)
        :name(_name), location(_location), hits(_hits){}
        bool Character::isAlive(){}
        double Character::distance(Character &other){}
        void Character::hit(int){}
        string Character::getName(){}
        Point Character::getLocation(){}
        string Character::print(){}





}