// PhysicsList.hh
#ifndef PHYSICSLIST_HH
#define PHYSICSLIST_HH

#include "G4VModularPhysicsList.hh"

class PhysicsList : public G4VModularPhysicsList {
public:
    PhysicsList();
    virtual ~PhysicsList() = default;
};

#endif
