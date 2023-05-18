#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <cmath>
#include <string>
#include "Point.hpp"

namespace ariel
{
    class Character
    {
    protected:
        Point location;
        int hitPoints;
        std::string name;

    public:
        Character(std::string name, Point location, int hitPoints);

        bool stillAlive() const;

        double distance(const Character *character) const;

        void hit(int damage);

        std::string getName() const;

        Point getLocation() const;

        virtual std::string print() const;

        int getHitPoints() const;

        virtual ~Character();
    };

    class Cowboy : public Character
    {
    private:
        int bullets;

    public:
        Cowboy(const std::string &charName, const Point &charLocation);

        void shoot(Character *enemy);

        bool hasBullets() const;

        void reload();

        std::string print() const override;
    };

    class Ninja : public Character
    {
    private:
        int speed;

    public:
        Ninja(const std::string &name, const Point &location, int speed);

        void move(Character *enemy);
        void slash(Character *enemy);
        std::string print() const override;
        virtual ~Ninja();
    };

    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(const std::string &name, const Point &location);
        virtual ~YoungNinja();
        std::string print() const override;
    };

    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(const std::string &name, const Point &location);
        virtual ~TrainedNinja();
        std::string print() const override;
    };

    class OldNinja : public Ninja
    {
    public:
        OldNinja(const std::string &name, const Point &location);
        virtual ~OldNinja();
        std::string print() const override;
    };
} // namespace ariel

#endif // CHARACTER_HPP
