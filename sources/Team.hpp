#ifndef TEAM_HPP
#define TEAM_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include "Character.hpp"
namespace ariel
{
  class Team
  {
  private:
  public:
    std::vector<Character *> fighters;
    Character *leader;
    void iterateCharacters(const std::function<void(Character *)> &action) const;

    Team(Character *leaderPtr);

    void add(Character *fighter);

    void attack(Team *enemyTeam);

    int stillAlive() const;

    void print() const;

    ~Team();
  };
}
#endif // TEAM_HPP
