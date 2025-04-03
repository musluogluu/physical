#include "EventAction.hh"
#include "G4Event.hh"
#include "G4AnalysisManager.hh"
#include "G4Neutron.hh"

EventAction::EventAction() {}

void EventAction::BeginOfEventAction(const G4Event*) {}

void EventAction::EndOfEventAction(const G4Event* event) {
  G4AnalysisManager* analysis = G4AnalysisManager::Instance();
  
  // Tüm parçacıkları tarayarak nötronları say
  G4int nNeutrons = 0;
  G4double maxNeutronEnergy = 0;

  G4TrajectoryContainer* trajectories = event->GetTrajectoryContainer();
  if (trajectories) {
    for (size_t i=0; i<trajectories->size(); ++i) {
      if ((*trajectories)[i]->GetParticleName() == "neutron") {
        nNeutrons++;
        G4double e = (*trajectories)[i]->GetInitialMomentum().mag();
        if (e > maxNeutronEnergy) maxNeutronEnergy = e;
      }
    }
  }

  // Verileri kaydet
  analysis->FillNtupleIColumn(0, nNeutrons);
  analysis->FillNtupleDColumn(1, maxNeutronEnergy);
  analysis->AddNtupleRow();
}
