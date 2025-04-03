#include "RunAction.hh"
#include "G4AnalysisManager.hh"

RunAction::RunAction() {
  // Analiz dosyasını oluştur
  G4AnalysisManager* analysis = G4AnalysisManager::Instance();
  analysis->CreateNtuple("NeutronData", "Nötron Bilgileri");
  analysis->CreateNtupleIColumn("NeutronCount");
  analysis->CreateNtupleDColumn("MaxNeutronEnergy");
  analysis->FinishNtuple();
}

void RunAction::BeginOfRunAction(const G4Run*) {
  G4AnalysisManager::Instance()->OpenFile("output.root");
}

void RunAction::EndOfRunAction(const G4Run*) {
  G4AnalysisManager::Instance()->Write();
  G4AnalysisManager::Instance()->CloseFile();
}
