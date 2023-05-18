#include <iostream>
#include <cmath>
#include "Point.hpp"

namespace ariel
{

    Point::Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

    double Point::distance(const Point &other) const
    {
        double dx = x - other.x;
        double dy = y - other.y;
        return std::sqrt(dx * dx + dy * dy);
    }

    void Point::print() const
    {
        std::cout << "(" << x << ", " << y << ")";
    }

    Point Point::moveTowards(const Point &source, const Point &destination, double distance) const
    {
        double dx = destination.x - source.x;
        double dy = destination.y - source.y;
        double currentDistance = std::sqrt(dx * dx + dy * dy);

        if (currentDistance <= distance)
        {
            return destination;
        }
        else
        {
            double ratio = distance / currentDistance;
            double newX = source.x + dx * ratio;
            double newY = source.y + dy * ratio;
            return Point(newX, newY);
        }
    }

    int Point::getX() const
    {
        return x;
    }

    int Point::getY() const
    {
        return y;
    }

} // namespace ariel
