// NeutronSD.hh
#ifndef NEUTRON_SD_HH
#define NEUTRON_SD_HH

#include "G4VSensitiveDetector.hh"
#include "NeutronHit.hh"

class NeutronSD : public G4VSensitiveDetector {
public:
    NeutronSD(const G4String& name);
    virtual ~NeutronSD() = default;
    
    virtual void Initialize(G4HCofThisEvent* hitCollection) override;
    virtual G4bool ProcessHits(G4Step* step, G4TouchableHistory* history) override;
    
private:
    NeutronHitsCollection* fHitsCollection;
};

#endif
