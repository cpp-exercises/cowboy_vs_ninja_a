#include "SmartTeam.hpp"

namespace ariel
{
    SmartTeam::SmartTeam(Character *leader) : Team(leader) {}
    void SmartTeam::add(Character *member)  {}
    void SmartTeam::attack(Team *enemy)  {}
}