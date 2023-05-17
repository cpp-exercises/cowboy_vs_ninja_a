#include "Point.hpp"

namespace ariel
{
    using namespace std;
    Point::Point(double _x, double _y){
        x = _x;
        y = _y;
    } 
    double Point::distance(Point &other){
        return 0;
    }
    string Point::print(){
        return "";
    }
    Point moveTowards(Point &source, Point &destenation, double distance){
        return Point(0,0);
    }
    double Point::getX(){
        return this->x;
    }
    double Point::getY(){
        return this->y;
    }
    void Point::setX(double newX){
        this->x = newX;
    }
    void Point::setY(double newY){
        this->y = newY;
    }



}