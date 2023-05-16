
// Team.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include "Character.hpp"
namespace ariel
{
    class Team
    {
    public:
        Character *leader;
        std::vector<Character *> fighters;

        Team(Character *leaderPtr) : leader(leaderPtr) {}

        void add(Character *fighter)
        {
            fighters.push_back(fighter);
        }

        void attack(Team *enemyTeam)
        {
            if (!leader->isAlive())
            {
                // Find the living character closest to the dead leader and set as new leader
                double closestDistance = std::numeric_limits<double>::max();
                Character *newLeader = nullptr;
                for (Character *fighter : fighters)
                {
                    if (fighter->isAlive())
                    {
                        double distance = leader->getLocation().distance(fighter->getLocation());
                        if (distance < closestDistance)
                        {
                            closestDistance = distance;
                            newLeader = fighter;
                        }
                    }
                }
                if (newLeader)
                    leader = newLeader;
                else
                    return; // No living character in the attacking group
            }

            Character *victim = nullptr;
            double closestDistance = std::numeric_limits<double>::max();
            for (Character *enemy : enemyTeam->fighters)
            {
                if (enemy->isAlive())
                {
                    double distance = leader->getLocation().distance(enemy->getLocation());
                    if (distance < closestDistance)
                    {
                        closestDistance = distance;
                        victim = enemy;
                    }
                }
            }

            while (!fighters.empty() && victim->isAlive())
            {
                iterateCharacters([&](Character *fighter)
                                  {
                                      if (fighter->isAlive())
                                      {
                                          Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter);
                                          if (cowboy)
                                          {
                                              if (cowboy->hasBullets())
                                                  cowboy->shoot(victim);
                                              else
                                                  cowboy->reload();
                                          }
                                          else
                                          {
                                              Ninja *ninja = dynamic_cast<Ninja *>(fighter);
                                              if (ninja)
                                                  ninja->move(victim);
                                          }
                                      } });

                if (!victim->isAlive())
                {
                    victim = nullptr;
                    closestDistance = std::numeric_limits<double>::max();
                    for (Character *enemy : enemyTeam->fighters)
                    {
                        if (enemy->isAlive())
                        {
                            double distance = leader->getLocation().distance(enemy->getLocation());
                            if (distance < closestDistance)
                            {
                                closestDistance = distance;
                                victim = enemy;
                            }
                        }
                    }
                }
            }
        }

        int stillAlive() const
        {
            int aliveCount = 0;
            for (Character *fighter : fighters)
            {
                if (fighter->isAlive())
                    aliveCount++;
            }
            return aliveCount;
        }

        void print() const
        {
            iterateCharacters([](Character *fighter)
                              { fighter->print(); });
        }

        virtual void iterateCharacters(const std::function<void(Character *)> &action) const
        {
            for (Character *fighter : fighters)
            {
                if (fighter->isAlive())
                {
                    action(fighter);
                }
            }
        }

        ~Team()
        {
            for (Character *fighter : fighters)
            {
                delete fighter;
            }
        }
    };

    class Team2 : public Team
    {
    public:
        void iterateCharacters(const std::function<void(Character *)> &action) const override
        {
            for (Character *fighter : fighters)
            {
                if (fighter->isAlive())
                {
                    action(fighter);
                }
            }
        }
    };

    class SmartTeam : public Team
    {
    public:
        void iterateCharacters(const std::function<void(Character *)> &
                                   action) const override
        {
            std::vector<Character *> orderedFighters(fighters);
            std::sort(orderedFighters.begin(), orderedFighters.end(), [&](Character *a, Character *b)
                      {
                          // Sort characters based on your custom logic
                          // Here you can implement your smart and creative algorithm
                          // to determine the order in which the characters will be iterated

                          // Example: Sort based on hit points in descending order
                        //   return a->getHitPoints() > b->getHitPoints();
                         });

            for (Character *fighter : orderedFighters)
            {
                if (fighter->isAlive())
                {
                    action(fighter);
                }
            }
        }
    };
} // namespace ariel
