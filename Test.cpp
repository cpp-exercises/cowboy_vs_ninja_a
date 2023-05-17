#include "doctest.h"
#include "iostream"
#include "string"
#include "sources/Team.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Point class")
{
    SUBCASE("Constructors")
    {
        CHECK_NOTHROW(Point(2, 3));
        CHECK_THROWS(Point(2, 3));
    }
    SUBCASE("Functions")
    {
        Point p1(2, 3);
        Point p2(3, 4);
        // Distance
        CHECK_NOTHROW(p1.distance(p2));
        CHECK_EQ(p1.distance(p2), 1);
        // Print
        CHECK_NOTHROW(p1.print());
        string printPoint = p1.print();
        CHECK(printPoint == "");
        // moveTowards
        CHECK_NOTHROW(moveTowards(p1, p2, 1));
        Point p3(3, 4);
        Point moved = moveTowards(p1, p2, 1);
        CHECK_EQ(moved.getX(), p3.getX());
        CHECK_EQ(moved.getY(), p3.getY());
        // Gettes&Setters
        CHECK_NOTHROW(p1.getX());
        CHECK_NOTHROW(p1.getY());
        Point p4(5, 6);
        Point p5(5.0, 6.0);
        CHECK_EQ(p4.getX(), p5.getX());
        CHECK_EQ(p4.getY(), p5.getY());
        p1.setX(5), p1.setY(6);
        CHECK_EQ(p4.getX(), p1.getX());
        CHECK_EQ(p4.getY(), p1.getY());
    }
}

TEST_CASE("Character class")
{
    SUBCASE("Constructors")
    {
        Point p1(1, 2);
        string name = "yulia";
        CHECK_NOTHROW(Character war1(name, p1, 46));
        Character war1(name, p1, 46);
    }
    SUBCASE("Functions")
    {
        // isAlive
        Point p1(1, 2);
        string name = "yulia";
        Character war1(name, p1, 110);
        CHECK_NOTHROW(war1.isAlive());
        CHECK(war1.isAlive());
        war1.setHits(0);
        CHECK_FALSE(war1.isAlive());
        // distance
        Point p2(3, 4);
        Character war2("Dudi", p2, 110);
        CHECK_NOTHROW(war1.distance(war2));
        double charDist = war1.distance(war2);
        CHECK_EQ(charDist, 1);
        // hit
        CHECK_NOTHROW(war1.hit(10));
        war1.hit(10);
        CHECK_EQ(war1.getHits(), 100);
        war1.hit(100);
        CHECK_FALSE(war1.isAlive());
        // getName
        CHECK_NOTHROW(war1.getName());
        string name1 = war1.getName();
        CHECK_EQ(name1, "yulia");
        // getLocation
        CHECK_NOTHROW(war1.getLocation());
        CHECK_EQ(war1.getLocation(), p1);
        CHECK_EQ(war2.getLocation(), p2);
        // print
        CHECK_NOTHROW(war1.print());
        string printWarrior = war1.print();
        CHECK_EQ(printWarrior, "");
    }
}
TEST_CASE("Cowboy class")
{
    SUBCASE("Constructors")
    {
        Point p1(1, 2);
        CHECK_NOTHROW(Cowboy c1("yulia", p1));
        Cowboy c1("yulia", p1);
        CHECK(c1.hasboolets());//Checks if Character and Cowboy constructors combined
        CHECK_EQ(c1.getHits(),110);



    }
    SUBCASE("Functions") {}
}
TEST_CASE("Character class") {}
TEST_CASE("Character class") {}
TEST_CASE("Character class") {}
TEST_CASE("Character class") {}
