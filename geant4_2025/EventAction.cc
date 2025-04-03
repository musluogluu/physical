#include "EventAction.hh"
#include "G4Event.hh"
#include "G4TrajectoryContainer.hh"
#include "G4VTrajectory.hh"
#include "G4Neutron.hh"
#include "G4AnalysisManager.hh"

EventAction::EventAction() {}

EventAction::~EventAction() {}  // Düzeltme: Destructor implemente edildi

void EventAction::BeginOfEventAction(const G4Event*) {}

void EventAction::EndOfEventAction(const G4Event* evt) {
    G4TrajectoryContainer* trajectoryContainer = evt->GetTrajectoryContainer();
    if (!trajectoryContainer) return;

    G4int neutronCount = 0;
    G4double maxEnergy = 0.0;

    for (size_t i=0; i<trajectoryContainer->size(); ++i) {
        G4VTrajectory* trajectory = (*trajectoryContainer)[i];
        if (trajectory->GetParticleName() == "neutron") {
            neutronCount++;
            G4double energy = trajectory->GetInitialMomentum().mag();
            if (energy > maxEnergy) maxEnergy = energy;
        }
    }

    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
    analysisManager->FillNtupleDColumn(0, maxEnergy);
    analysisManager->FillNtupleIColumn(1, neutronCount);
    analysisManager->AddNtupleRow();
}
