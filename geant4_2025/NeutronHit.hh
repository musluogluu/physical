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
    
    void* operator new(size_t);
    void operator delete(void* aHit);
    
    void SetEnergy(G4double e) { fEnergy = e; }
    G4double GetEnergy() const { return fEnergy; }
    
    void SetMomentumDirection(G4ThreeVector dir) { fMomentumDir = dir; }
    G4ThreeVector GetMomentumDirection() const { return fMomentumDir; }

    void SetTheta(G4double theta) { fTheta = theta; }
    G4double GetTheta() const { return fTheta; }
    
    void SetEnergy(G4double energy) { fEnergy = energy; }
    G4double GetEnergy() const { return fEnergy; }
    
private:
    G4double fEnergy;
    G4ThreeVector fMomentumDir;
};

typedef G4THitsCollection<NeutronHit> NeutronHitsCollection;

extern G4ThreadLocal G4Allocator<NeutronHit>* NeutronHitAllocator;

#endif
