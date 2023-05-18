#ifndef POINT_HPP
#define POINT_HPP
namespace ariel
{
class Point {
private:
  double x;
  double y;

public:
  Point(double xCoord, double yCoord);

  double distance(const Point& other) const;

  int getX() const;
  int getY() const;
  void print() const;

  Point moveTowards(const Point& source, const Point& destination, double distance) const;
};
}
#endif  // POINT_HPP
