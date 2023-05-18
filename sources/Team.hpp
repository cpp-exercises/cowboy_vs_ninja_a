#ifndef TEAM_HPP
#define TEAM_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include "Character.hpp"

namespace ariel {
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

        void attack(Team *enemyTeam);

        int stillAlive() const;

        void print();

        virtual ~Team();


        };


    // class Team2 : public Team
    // {
    // public:
    //     Team2(Character *leader);

    //     void attack(Team *enemyTeam) override;
    // };

    // class SmartTeam : public Team
    // {
    // public:
    //     SmartTeam(Character *leader);

    //     void SmartTeam::attack(Team *enemyTeam) override;
    // };
} // namespace ariel

#endif // TEAM_HPP
