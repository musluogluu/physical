#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "RunAction.hh"
#include "G4Run.hh"
#include "G4AnalysisManager.hh"
#include "G4SystemOfUnits.hh"

RunAction::RunAction() {}

void RunAction::BeginOfRunAction(const G4Run*) {
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
    analysisManager->OpenFile("neutron_data");
    analysisManager->CreateNtuple("NeutronData", "Data");
    analysisManager->CreateNtupleDColumn("Energy");
    analysisManager->CreateNtupleIColumn("Count");
    analysisManager->FinishNtuple();
}

void RunAction::EndOfRunAction(const G4Run*) {
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
    analysisManager->Write();
    analysisManager->CloseFile();
}
