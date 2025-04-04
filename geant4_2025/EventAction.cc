#include "EventAction.hh"
#include "G4Event.hh"

EventAction::EventAction(RunAction* runAction) 
    : fRunAction(runAction) {}

void EventAction::BeginOfEventAction(const G4Event*) {
    fNeutronEnergies.clear();
}

void EventAction::EndOfEventAction(const G4Event*) {
    for(auto energy : fNeutronEnergies) {
        fRunAction->AddNeutronEnergy(energy);
    }
}

void EventAction::AddNeutron(G4double energy) {
    fNeutronEnergies.push_back(energy);
}
