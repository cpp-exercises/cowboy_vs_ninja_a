#include <string>
#include "Point.hpp"

namespace ariel
{

    using namespace std;

    class Character{
      private:
      string name;
      Point location;
      int hit;


      public:

      bool isAlive();
      double distance(Character &other);
      void hit(int);
      string getName();
      Point getLocation();
      void print();
      



    }
}
