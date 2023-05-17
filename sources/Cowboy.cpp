#include "Cowboy.hpp"

namespace ariel{

        Cowboy::Cowboy(string _name, Point _location)
        :Character(_name, _location, 110),numOfBullets(6){}
        void  Cowboy::shoot(const Character *enemy){} 
        bool  Cowboy::hasboolets(){
            return true;
        } 
        string Cowboy::print(){
            return "";
        } 
        void  Cowboy::reload(){} 
}