#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Team.hpp"

class Team2 : public Team {
public:
  using Team::Team;

  void iterateCharacters() const override;
};

#endif  // TEAM2_HPP
