// EventAction.cc
#include "EventAction.hh"
#include "NeutronHit.hh"
#include "G4Event.hh"
#include "G4HCofThisEvent.hh"

EventAction::EventAction(RunAction* runAction) : fRunAction(runAction) {}

void EventAction::BeginOfEventAction(const G4Event*) {}

void EventAction::EndOfEventAction(const G4Event* event) {
    G4HCofThisEvent* hce = event->GetHCofThisEvent();
    if(!hce) return;

    auto hc = hce->GetHC(0);
    if(!hc) return;

    for(size_t i=0; i<hc->GetSize(); i++) {
        auto hit = dynamic_cast<NeutronHit*>(hc->GetHit(i));
        if(hit) {
            fRunAction->RecordNeutron(
                hit->GetEnergy(),
                hit->GetMomentumDirection().theta()
            );
        }
    }
}
