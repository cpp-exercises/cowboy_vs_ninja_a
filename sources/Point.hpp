#ifndef POINT_H
#define POINT_H
#include <string>
namespace ariel
{
    using namespace std;
    class Point{
      private:
         double x;
         double y;

      public:
        Point(double, double);
        double distance(Point &Other);
        string print();
        friend Point moveTowards(Point &source, Point &destenation, double distance);
        double getX();
        double getY();
        void setX(double);
        void setY(double);
    };
}
#endif