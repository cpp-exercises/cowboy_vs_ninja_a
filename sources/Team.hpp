#include "Character.hpp"

// Limited to 10 members, can be nunja or cowboy
// When the team created, it gets pointer to leader.
// For all teem one leader,
namespace ariel
{

  using namespace std;

  class Team
  {
  private:
    Character *leader;
    vector<Cowboy *> Cowboys;
    vector<Ninja *> Ninjas;

  public:
    Team(Character *leader); // Constructor, limited to 10 members.When the team created, it gets pointer to leader.
    void add(Character &member);//Adds the warrior by it's type.
    void attack(Team &enemy);//One team attacs another, by the rules of each type of warrior.
    int stillAlive(); // Returns the number of alive warriors in the team.
    void print();     // Prints the details of all warriors in the team.
    // Distructor

    // Going over all members of the team (for attacking, printing, or comparing)
    // will always be done in the following order:
    // first go over all the cowboys, then go over all the ninjas.
    // Within each team, the transition will be made according to the order in which the
    // characters were added - warriers list by vector.
    // When looking for the closest character, and two characters are at the same distance,
    //  the first character that was checked between them will be selected.
  }
}
