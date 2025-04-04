#include "NeutronSD.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4Neutron.hh"

NeutronSD::NeutronSD(const G4String& name) 
    : G4VSensitiveDetector(name), fEventAction(nullptr) {}

void NeutronSD::Initialize(G4HCofThisEvent*) {}

G4bool NeutronSD::ProcessHits(G4Step* step, G4TouchableHistory*) {
    G4Track* track = step->GetTrack();
    if(track->GetDefinition() == G4Neutron::NeutronDefinition()) {
        G4double energy = track->GetKineticEnergy();
        if(fEventAction) {
            fEventAction->AddNeutron(energy);
        }
    }
    return true;
}
