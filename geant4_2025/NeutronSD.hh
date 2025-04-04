#ifndef NEUTRON_SD_HH
#define NEUTRON_SD_HH

#include "G4VSensitiveDetector.hh"
#include "EventAction.hh"

class NeutronSD : public G4VSensitiveDetector {
public:
    NeutronSD(const G4String& name);
    virtual ~NeutronSD() = default;
    
    virtual void Initialize(G4HCofThisEvent*) override;
    virtual G4bool ProcessHits(G4Step*, G4TouchableHistory*) override;
    
    void SetEventAction(EventAction* ea) { fEventAction = ea; }
    
private:
    EventAction* fEventAction;
};

#endif
