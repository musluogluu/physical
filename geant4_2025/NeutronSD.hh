#ifndef NEUTRON_SD_HH
#define NEUTRON_SD_HH

#include "G4VSensitiveDetector.hh"

class EventAction; // Forward declaration

class NeutronSD : public G4VSensitiveDetector {
public:
    NeutronSD(const G4String& name, EventAction* eventAction); // Değiştirildi
    virtual ~NeutronSD() = default;
    
    virtual void Initialize(G4HCofThisEvent* hitCollection) override;
    virtual G4bool ProcessHits(G4Step* step, G4TouchableHistory* history) override;

private:
    EventAction* fEventAction;
};

#endif
