#ifndef SMARTTEAM_H
#define SMARTTEAM_H
#include "Team.hpp"
//The transition to the team on the characters will be according to your choice
//in whatever order you see fit to realize it is allowed and desirable at this 
//stage to "ask" the other team about the positions of their forces and status as 
//well as take into account the state of the attacking team in order to maximize damage.

namespace ariel
{

  using namespace std;

  class SmartTeam : public Team
  {
  public:
    SmartTeam(Character *leader);
    void add(Character *member) override;  // Overiding the add order
    void attack(Team *enemy) override; // Overiding the attac rules
  };
}
#endif
