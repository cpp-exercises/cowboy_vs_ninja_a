#include "Team.hpp"
// The same as Team, But the transition to the characters will be in the
// order of addition without distinguishing cowboys or ninjas.
namespace ariel
{

  using namespace std;

  class Team2 : public Team
  {

  public:
    Team2(Character *leader);
    void add(Character *member) override;  // Overiding the add order
    void attac(Character *enemy) override; // Overiding the attac rules
  };
}
