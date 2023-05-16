#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "Point.hpp"
namespace ariel
{

    class Character
    {
    protected:
        std::string name;
        int hitPoints;
        Point location;

    public:
        Character(const std::string &charName, int initialHitPoints, const Point &charLocation);

        bool isAlive() const;

        double distance(const Character *other) const;

        void hit(int amount);

        std::string getName() const;

        Point getLocation() const;

        virtual std::string print() const;
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
    protected:
        int speed;

    public:
        Ninja(const std::string &charName, int charSpeed, int initialHitPoints, const Point &charLocation);

        void move(Character *enemy);

        virtual void slash(Character *enemy);
    };

    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(const std::string &charName, const Point &charLocation);
    };

    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(const std::string &charName, const Point &charLocation);
    };

    class OldNinja : public Ninja
    {
    public:
        OldNinja(const std::string &charName, const Point &charLocation);
    };
} // namespace ariel

#endif // CHARACTER_HPP
