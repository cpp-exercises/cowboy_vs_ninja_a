#include "doctest.h"
#include "Team.hpp"
#include "Character.hpp"
#include "Point.hpp"
#include <stdexcept>

using namespace std;
using namespace ariel;

    TEST_CASE("Team AddMembers Test")
    {
        Team team;
        Cowboy cowboy1("John", Point(0, 0));
        Cowboy cowboy2("Tom", Point(1, 1));
        Ninja ninja1("Ryu", Point(2, 2), 10);
        Ninja ninja2("Ken", Point(3, 3), 12);
        team.add(&cowboy1);
        team.add(&ninja1);
        team.add(&cowboy2);
        team.add(&ninja2);
        CHECK_EQ(team.stillAlive(), 4);
    }

    TEST_CASE("Team Attack Test")
    {
        Team team1;
        Team team2;
        Cowboy cowboy1("John", Point(0, 0));
        Cowboy cowboy2("Tom", Point(1, 1));
        Ninja ninja1("Ryu", Point(2, 2), 10);
        Ninja ninja2("Ken", Point(3, 3), 12);
        team1.add(&cowboy1);
        team1.add(&ninja1);
        team2.add(&cowboy2);
        team2.add(&ninja2);
        team1.attack(&team2);
        CHECK_EQ(team1.stillAlive(), 2);
        CHECK_EQ(team2.stillAlive(), 1);
    }

    TEST_CASE("Character stillAlive Test")
    {
        Character character("John", Point(0, 0), 100);
        CHECK(character.stillAlive());
        character.hit(100);
        CHECK_FALSE(character.stillAlive());
    }

    TEST_CASE("Character Distance Test")
    {
        Character character1("John", Point(0, 0), 100);
        Character character2("Jane", Point(3, 4), 100);
        CHECK_EQ(character1.distance(&character2), doctest::Approx(5.0));
    }

    TEST_CASE("Character GetName Test")
    {
        Character character("John", Point(0, 0), 100);
        CHECK_EQ(character.getName(), "John");
    }

    TEST_CASE("Character Print Test")
    {
        Character character("John", Point(0, 0), 100);
        CHECK_EQ(character.print(), "Name: John, Location: (0, 0), Hit Points: 100");
    }

    TEST_CASE("Cowboy Print Test")
    {
        Cowboy cowboy("John", Point(0, 0));
        cowboy.reload();
        CHECK_EQ(cowboy.print(), "Name: John, Location: (0, 0), Hit Points: 110, Bullets: 6");
    }

    TEST_CASE("Ninja Print Test")
    {
        Ninja ninja("Rain", Point(0, 0), 10);
        CHECK_EQ(ninja.print(), "Name: Rain, Location: (0, 0), Speed: 10");
    }

    TEST_CASE("YoungNinja Print Test")
    {
        YoungNinja youngNinja("Yoshi", Point(0, 0));
        CHECK_EQ(youngNinja.print(), "Ninja: Yoshi");
    }

    TEST_CASE("TrainedNinja Print Test")
    {
        TrainedNinja trainedNinja("Hanzo", Point(0, 0));
        CHECK_EQ(trainedNinja.print(), "Ninja: Hanzo");
    }

    TEST_CASE("Point Distance Test")
    {
        Point p1(0, 0);
        Point p2(3, 4);
        CHECK_EQ(p1.distance(p2), doctest::Approx(5.0));
    }

    TEST_CASE("Cowboy Shoot Test")
    {
        Cowboy cowboy("John", Point(0, 0));
        Cowboy enemyCowboy("Tom", Point(3, 4));
        cowboy.reload();
        CHECK(cowboy.hasBullets());
        cowboy.shoot(&enemyCowboy);
        CHECK_FALSE(enemyCowboy.stillAlive());
        CHECK_FALSE(cowboy.hasBullets());
    }

    TEST_CASE("Ninja Slash Test")
    {
        Ninja ninja("Ryu", Point(0, 0), 10);
        Character enemy("Enemy", Point(1, 1), 110);
        CHECK(enemy.stillAlive());
        ninja.slash(&enemy);
        CHECK_FALSE(enemy.stillAlive());
    }

    TEST_CASE("Team StillAlive Test")
    {
        Team team;
        Cowboy cowboy("John", Point(0, 0));
        Ninja ninja("Ryu", Point(1, 1), 10);
        CHECK_EQ(team.stillAlive(), 0);
        team.add(&cowboy);
        CHECK_EQ(team.stillAlive(), 1);
        team.add(&ninja);
        CHECK_EQ(team.stillAlive(), 2);
        cowboy.hit(110);
        CHECK_EQ(team.stillAlive(), 1);
        ninja.hit(100);
        CHECK_EQ(team.stillAlive(), 0);
    }
    TEST_CASE("OldNinja Print Test")
    {
        OldNinja oldNinja("Sensei", Point(0, 0));
        CHECK_EQ(oldNinja.print(), "Ninja: Sensei");
    }

    TEST_CASE("TEST 21: Team AddMember Test")
    {
        Team team;
        Cowboy cowboy("John", Point(0, 0));
        Ninja ninja("Ryu", Point(1, 1), 10);
        team.add(&cowboy);
        team.add(&ninja);
        CHECK_EQ(team.stillAlive(), 2);
    }

    TEST_CASE("TEST 22: Team Attack Test")
    {
        Team team1;
        Team team2;
        Cowboy cowboy1("John", Point(0, 0));
        Cowboy cowboy2("Tom", Point(1, 1));
        Ninja ninja1("Ryu", Point(2, 2), 10);
        Ninja ninja2("Ken", Point(3, 3), 12);
        team1.add(&cowboy1);
        team1.add(&ninja1);
        team2.add(&cowboy2);
        team2.add(&ninja2);
        team1.attack(&team2);
        CHECK_EQ(team1.stillAlive(), 2);
        CHECK_EQ(team2.stillAlive(), 1);
    }

    TEST_CASE("TEST 23: Character stillAlive Test")
    {
        Character character("John", Point(0, 0), 100);
        CHECK(character.stillAlive());
        character.hit(100);
        CHECK_FALSE(character.stillAlive());
    }

    TEST_CASE("TEST 24: Character Distance Test")
    {
        Character character1("John", Point(0, 0), 100);
        Character character2("Jane", Point(3, 4), 100);
        CHECK_EQ(character1.distance(&character2), doctest::Approx(5.0));
    }

    TEST_CASE("TEST 25: Character GetName Test")
    {
        Character character("John", Point(0, 0), 100);
        CHECK_EQ(character.getName(), "John");
    }

    TEST_CASE("TEST 26: Character Print Test")
    {
        Character character("John", Point(0, 0), 100);
        CHECK_EQ(character.print(), "Name: John, Location: (0, 0), Hit Points: 100");
    }

    TEST_CASE("TEST 27: Cowboy Print Test")
    {
        Cowboy cowboy("John", Point(0, 0));
        cowboy.reload();
        CHECK_EQ(cowboy.print(), "Name: John, Location: (0, 0), Hit Points: 110, Bullets: 6");
    }

    TEST_CASE("TEST 28: Ninja Print Test")
    {
        Ninja ninja("Rain", Point(0, 0), 10);
        CHECK_EQ(ninja.print(), "Name: Rain, Location: (0, 0), Speed: 10");
    }

    TEST_CASE("TEST 29: YoungNinja Print Test")
    {
        YoungNinja youngNinja("Yoshi", Point(0, 0));
        CHECK_EQ(youngNinja.print(), "Ninja: Yoshi");
    }

    TEST_CASE("TEST 30: TrainedNinja Print Test")
    {
        TrainedNinja trainedNinja("Hanzo", Point(0, 0));
        CHECK_EQ(trainedNinja.print(), "Ninja: Hanzo");
    }

