#include "SmartTeam.hpp"

namespace ariel
{
    SmartTeam::SmartTeam(Character *leader) : Team(leader) {}
    void SmartTeam::add(Character *member) override {}
    void SmartTeam::attac(Character *enemy) override {}
}