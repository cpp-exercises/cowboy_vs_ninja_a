#include <iostream>
#include <cmath>
#include <string>
#include "Character.hpp"

namespace ariel
{
    Character::Character(std::string name, Point location, int hitPoints )
        :  name(name), location(location), hitPoints(hitPoints) {}

    bool Character::stillAlive() const
    {
        return hitPoints > 0;
    }

    double Character::distance(const Character *character) const
    {
        return location.distance(character->location);
    }

    void Character::hit(int damage)
    {
        hitPoints -= damage;
        if (hitPoints < 0)
        {
            hitPoints = 0;
        }
    }

    std::string Character::getName() const
    {
        return name;
    }

    Point Character::getLocation() const
    {
        return location;
    }

    Character::~Character() {}

    // Definitions for Cowboy

    Cowboy::Cowboy(const std::string& charName, const Point& charLocation)
        : Character(charName, charLocation, 110), bullets(6) {}

    void Cowboy::shoot(Character *enemy)
    {
        if (stillAlive() && bullets > 0)
        {
            enemy->hit(10);
            bullets--;
        }
    }

    bool Cowboy::hasBullets() const
    {
        return bullets > 0;
    }

    void Cowboy::reload()
    {
        bullets = 6;
    }

    std::string Cowboy::print() const
    {
        std::string result = "C: " + name;
        if (stillAlive())
        {
            result += ": " + std::to_string(hitPoints);
        }
        result += " " + std::to_string(location.getX()) + ", " + std::to_string(location.getY());
        return result;
    }

    // Definitions for Ninja and subclasses

    
    Ninja::Ninja(const std::string &name, const Point &location, int speed)
        : Character(name, location, 100), speed(speed) {}

    void Ninja::move(Character *enemy)
    {
        if (stillAlive())
        {
            Point newLocation = location.moveTowards(location, enemy->getLocation(), speed);
            location = newLocation;
        }
    }

    void Ninja::slash(Character *enemy)
    {
        if (stillAlive() && distance(enemy) < 1)
        {
            enemy->hit(40);
        }
    }
    
    Ninja::~Ninja() {}


    std::string Ninja::print() const
    {
        std::string result = "N: " + name;
        if (stillAlive())
        {
            result += ": " + std::to_string(hitPoints);
        }
        result += " " + std::to_string(location.getX()) + ", " + std::to_string(location.getY());
        return result;
    }

    YoungNinja::YoungNinja(const std::string &name, const Point &location)
    : Ninja(name, location, 14) {}

    std::string YoungNinja::print() const
    {
        return "Ninja: " + getName();
    }

    YoungNinja::~YoungNinja() {}
    
    TrainedNinja::TrainedNinja(const std::string &name, const Point &location)
        : Ninja(name, location, 12) {}

    
    std::string TrainedNinja::print() const
    {

        return "Ninja: " + getName();
    }
    TrainedNinja::~TrainedNinja() {}

    OldNinja::OldNinja(const std::string &name, const Point &location)
        : Ninja(name, location, 8) {}


    std::string OldNinja::print() const
    {

        return "Ninja: " + getName();
    }
        OldNinja::~OldNinja() {}

} // namespace ariel
