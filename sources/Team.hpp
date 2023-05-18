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
    protected:
        Character *leader;
        int size;

    public:
        Team();

        std::vector<Character *> members;

        Team(Character *leader);

        void add(Character *member);
        Character *closestLivingMember();

        void attack(Team *enemyTeam);

        int stillAlive() const;

        std::string print() const;

        ~Team();
    };

} // namespace ariel

#endif // TEAM_HPP
