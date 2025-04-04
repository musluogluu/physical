#include "RunAction.hh"
#include "G4Run.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include <fstream>

RunAction::RunAction() : fNeutronCount(0) {
    // Enerji spektrumu başlatma
    for(int i=0; i<=1000; i+=10) {
        fEnergySpectrum[i] = 0;
    }
}

RunAction::~RunAction() {}  // AÇIKÇA TANIMLANMIŞ DESTRUCTOR

void RunAction::BeginOfRunAction(const G4Run* run) {
    fNeutronCount.Reset();
    // Ek başlangıç işlemleri buraya
}

void RunAction::EndOfRunAction(const G4Run* run) {
    G4int totalNeutrons = fNeutronCount.GetValue();
    
    G4cout << "\n--- Run Summary ---" << G4endl;
    G4cout << "Total neutrons produced: " << totalNeutrons << G4endl;
    
    std::ofstream outFile("neutron_spectrum.csv");
    outFile << "Energy[MeV],Count\n";
    for(const auto& bin : fEnergySpectrum) {
        outFile << bin.first << "," << bin.second << "\n";
    }
    outFile.close();
}

void RunAction::AddNeutronEnergy(G4double energy) {
    fNeutronCount += 1;
    G4int energyBin = ((G4int)(energy/MeV))/10 * 10;
    fEnergySpectrum[energyBin]++;
}
