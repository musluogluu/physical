#ifndef NeutronHit_h
#define NeutronHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4ThreeVector.hh"

class NeutronHit : public G4VHit {
public:
    NeutronHit();
    virtual ~NeutronHit();
    
    // Set/Get metodları
    void SetEnergy(G4double e) { fEnergy = e; }
    G4double GetEnergy() const { return fEnergy; }
    
    void SetPosition(G4ThreeVector pos) { fPos = pos; }
    G4ThreeVector GetPosition() const { return fPos; }
    
    void SetMomentumDirection(G4ThreeVector dir) { fDir = dir; }
    G4ThreeVector GetMomentumDirection() const { return fDir; }

private:
    G4double fEnergy;
    G4ThreeVector fPos;
    G4ThreeVector fDir;
};

typedef G4THitsCollection<NeutronHit> NeutronHitsCollection;

#endif
