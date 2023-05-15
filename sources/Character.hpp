#include <string>
#include "Point.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"



namespace ariel
{

  using namespace std;

  class Character
  {
  private:
    string name;
    Point location;
    int hits;

  public:
    Character(string, Point, int);
    bool isAlive();
    double distance(Character &other);
    void hit(int);
    string getName();
    Point getLocation();
    string print();
  };

 

  


}
