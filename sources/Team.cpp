#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Character.hpp"
#include "Team.hpp"

namespace ariel
{

    Team::Team(){};
    Team::Team(Character *leader) : leader(leader)
    {
        members.push_back(leader);
    }

    void Team::add(Character *member)
    {
        members.push_back(member);
    }

    std::vector<Character *> getTeamMembers(const Team &team)
    {
        return team.members;
    }

    int Team::stillAlive() const
    {
        int aliveCount = 0;
        // for (auto member : members)
        // {
        //     if (member->stillAlive())
        //     {
        //         aliveCount++;
        //     }
        // }
        return aliveCount;
    }

   std::string Team::print() const
{
    std::string result;
    for (auto member : members)
    {
        result += member->print() + "\n";
    }
    return result;
}
    Character *Team::closestLivingMember()
    {
        double minDistance = std::numeric_limits<double>::max();
        Character *closestLivingMember = nullptr;

        for (auto member : members)
        {
            if (member->stillAlive() && leader->distance(member) < minDistance)
            {
                closestLivingMember = member;
                minDistance = leader->distance(member);
            }
        }

        if (closestLivingMember == nullptr)
        {
            throw std::runtime_error("No living members found.");
        }

        return closestLivingMember;
    }
    void Team::attack(Team *enemyTeam)
    {
        // // Check if leader is alive, if not, find a new leader
        // if (!leader->stillAlive())
        // {
        //     try
        //     {
        //         leader = closestLivingMember();
        //     }
        //     catch (std::runtime_error &e)
        //     {
        //         std::cerr << e.what() << "\n";
        //         return;
        //     }
        // }

        // // Now attack the enemy team
        // while (members.size() > 0 && enemyTeam->members.size() > 0)
        // {
        //     // Choose a victim from the enemy team
        //     Character *victim = nullptr;
        //     double minDistance = std::numeric_limits<double>::max();
        //     for (auto enemyMember : enemyTeam->members)
        //     {
        //         if (enemyMember->stillAlive() && leader->distance(enemyMember) < minDistance)
        //         {
        //             victim = enemyMember;
        //             minDistance = leader->distance(enemyMember);
        //         }
        //     }

        //     // // If no living enemy was found, break out of the loop
        //     // if (victim == nullptr)
        //     // {
        //     //     return;
        //     // }

        //     // All living members of this team attack the chosen victim
        //     for (auto member : members)
        //     {
        //         if (member->stillAlive())
        //         {
        //             Cowboy *cowboy = dynamic_cast<Cowboy *>(member);
        //             Ninja *ninja = dynamic_cast<Ninja *>(member);

        //             if (cowboy)
        //             {
        //                 if (cowboy->hasBullets())
        //                 {
        //                     cowboy->shoot(victim);
        //                 }
        //                 else
        //                 {
        //                     cowboy->reload();
        //                 }
        //             }
        //             else if (ninja)
        //             {
        //                 if (ninja->distance(victim) < 1)
        //                 {
        //                     ninja->slash(victim);
        //                 }
        //                 else
        //                 {
        //                     ninja->move(victim);
        //                 }
        //             }

        //             // If the victim is dead, break the loop to choose a new victim
        //             if (!victim->stillAlive())
        //             {
        //                 break;
        //             }
        //         }
        //     }
        // }
    }

    Team::~Team()
    {
        // for (auto member : members)
        // {
        //     delete member;
        // }
        // members.clear();
    }

} // namespace ariel
