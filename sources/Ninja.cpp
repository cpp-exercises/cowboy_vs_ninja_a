#include "Ninja.hpp"


namespace ariel{

    Ninja::Ninja(string _name, Point _location, int _hits, int _speed)
    : Character(_name, _location, _hits),speed(_speed){}
    void Ninja::move(const Character &enemy){}
    void Ninja::slash(){}
    string Ninja::print(){
        return "";
    }
}
