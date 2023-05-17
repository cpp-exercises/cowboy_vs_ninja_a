#include "Character.hpp"


namespace ariel{
    using namespace std;
       Character::Character(string _name, Point _location, int _hits)
        :name(_name), location(_location), hits(_hits){}
        bool Character::isAlive(){
            return true;
        }
        double Character::distance(Character &other){
            return 0;
        }
        void Character::hit(int){}
        string Character::getName(){
            return "";
        }
        Point Character::getLocation(){
            return Point(0,0);
        }
        string Character::print(){
            return "";
        }





}