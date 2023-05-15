#include "Cowboy.hpp"

namespace ariel{

        Cowboy::Cowboy(string _name, Point _location, int _hits, int _numOfBullets)
        :Character(_name, _location, _hits),numOfBullets(_numOfBullets){}{} 
        void  Cowboy::shoot(const Character &enemy){} 
        bool  Cowboy::hasboolets(){
            return true;
        } 
        string Cowboy::print(){
            //return "";
        } 
        void  Cowboy::reload(){} 
}