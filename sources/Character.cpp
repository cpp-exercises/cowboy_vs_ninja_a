// Character.cpp

namespace ariel
{
#include <iostream>
#include <cmath>
#include <string>
#include "Point.hpp"
    class Character
    {
    protected:
        Point location;
        int hitPoints;
        std::string name;

    public:
        Character(Point location, int hitPoints, std::string name)
            : location(location), hitPoints(hitPoints), name(name) {}

        bool isAlive() const
        {
            return hitPoints > 0;
        }

        double distance(const Character *character) const
        {
            return location.distance(character->location);
        }

        void hit(int damage)
        {
            hitPoints -= damage;
            if (hitPoints < 0)
            {
                hitPoints = 0;
            }
        }

        std::string getName() const
        {
            return name;
        }

        Point getLocation() const
        {
            return location;
        }

        virtual void print() const = 0;
    };
    class Cowboy : public Character
    {
    private:
        int bullets;

    public:
        Cowboy(Point location, std::string name)
            : Character(location, 110, name), bullets(6) {}

        void shoot(Character *enemy)
        {
            if (isAlive() && bullets > 0)
            {
                enemy->hit(10);
                bullets--;
            }
        }

        bool hasBullets() const
        {
            return bullets > 0;
        }

        void reload()
        {
            bullets = 6;
        }

        void print() const override
        {
            std::cout << "C: " << name << (isAlive() ? ": " + std::to_string(hitPoints) : "") << " " << location.getX() << ", " << location.getY() << std::endl;
        }
    };

    class Ninja : public Character
    {
    protected:
        int speed;

    public:
        Ninja(Point location, int hitPoints, int speed, std::string name)
            : Character(location, hitPoints, name), speed(speed) {}

        void move(Character *enemy)
        {
            if (isAlive())
            {
                Point newLocation = location.moveTowards(location, enemy->getLocation(), speed);
                location = newLocation;
            }
        }

        void slash(Character *enemy)
        {
            if (isAlive() && distance(enemy) < 1)
            {
                enemy->hit(40);
            }
        }

        void print() const override
        {
            std::cout << "N: " << name << (isAlive() ? ": " + std::to_string(hitPoints) : "") << " " << location.getX() << ", " << location.getY() << std::endl;
        }
    };

    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(Point location, std::string name)
            : Ninja(location, 100, 14, name) {}
    };

    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(Point location, std::string name)
            : Ninja(location, 120, 12, name) {}
    };

    class OldNinja : public Ninja
    {
    public:
        OldNinja(Point location, std::string name)
            : Ninja(location, 150, 8, name) {}
    };
} // namespace ariel