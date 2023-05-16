#include "Team2.hpp"

namespace ariel
{
    Team2::Team2(Character *leader) : Team(leader){}
    void Team2::add(Character *member) override {}
    void Team2::attac(Character *enemy) override {}
}