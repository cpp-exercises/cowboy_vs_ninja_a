#ifndef TRAINEDNINJA_H
#define TRAINEDNINJA_H
#include "Ninja.hpp"

namespace ariel
{

    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(string, Point); // Constructor created with speed = 12, 120 hits.
    };
}
#endif