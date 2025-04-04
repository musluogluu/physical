#ifndef NeutronSD_h
#define NeutronSD_h 1

#include "G4VSensitiveDetector.hh"
#include "NeutronHit.hh"

class NeutronSD : public G4VSensitiveDetector {
public:
    NeutronSD(const G4String& name);
    virtual ~NeutronSD();
    
    virtual void Initialize(G4HCofThisEvent*);
    virtual G4bool ProcessHits(G4Step*, G4TouchableHistory*);

private:
    NeutronHitsCollection* fHitsCollection;
    G4int fHCID;
};

#endif
