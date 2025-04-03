#include "RunAction.hh"
#include "G4Run.hh"
#include "G4AnalysisManager.hh"

RunAction::RunAction()
{
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
    analysisManager->SetVerboseLevel(1);
    analysisManager->CreateNtuple("NeutronData", "Neutron Information");
    analysisManager->CreateNtupleDColumn("Energy");
    analysisManager->FinishNtuple();
}

void RunAction::BeginOfRunAction(const G4Run*)
{
    G4AnalysisManager::Instance()->OpenFile("neutron_data");
}

void RunAction::EndOfRunAction(const G4Run*)
{
    G4AnalysisManager::Instance()->Write();
    G4AnalysisManager::Instance()->CloseFile();
}
