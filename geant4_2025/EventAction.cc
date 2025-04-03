#include "EventAction.hh"
#include "G4Event.hh"
#include "G4SDManager.hh"
#include "G4HCofThisEvent.hh"

EventAction::EventAction()
{}

void EventAction::BeginOfEventAction(const G4Event*)
{}

void EventAction::EndOfEventAction(const G4Event* evt)
{
    // Nötron verilerini işleme kodu buraya gelecek
}
