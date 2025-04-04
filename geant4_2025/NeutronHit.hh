// NeutronHit.hh
#ifndef NEUTRONHIT_HH
#define NEUTRONHIT_HH

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"

class NeutronHit : public G4VHit {
public:
    NeutronHit();
    virtual ~NeutronHit();
    
    inline void* operator new(size_t);
    inline void operator delete(void*);
    
    void SetEnergy(G4double e) { fEnergy = e; }
    G4double GetEnergy() const { return fEnergy; }
    
    void SetMomentumDirection(G4ThreeVector dir) { fMomentumDir = dir; }
    G4ThreeVector GetMomentumDirection() const { return fMomentumDir; }
    
private:
    G4double fEnergy;
    G4ThreeVector fMomentumDir;
};

typedef G4THitsCollection<NeutronHit> NeutronHitsCollection;

#endif
