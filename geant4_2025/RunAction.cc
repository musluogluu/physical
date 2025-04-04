// RunAction.cc
#include "RunAction.hh"
#include "G4Run.hh"
#include <fstream>
#include "G4SystemOfUnits.hh"

RunAction::RunAction() : totalNeutrons(0) {
    for(int i=0; i<=180; i+=5) angleHist[i] = 0;
    for(int i=0; i<=1000; i+=10) energyHist[i] = 0;
}

RunAction::~RunAction() {}

void RunAction::BeginOfRunAction(const G4Run*) {
    totalNeutrons = 0;
}

void RunAction::RecordNeutron(G4double energy, G4double angle) {
    G4int angleBin = static_cast<G4int>(angle/deg)/5 * 5;
    angleHist[angleBin]++;
    
    G4int energyBin = static_cast<G4int>(energy/MeV)/10 * 10;
    energyHist[energyBin]++;
    
    totalNeutrons++;
}

void RunAction::EndOfRunAction(const G4Run*) {
    std::ofstream out("neutron_data.csv");
    out << "Angle[deg],Count,Energy[MeV],Count\n";
    
    auto angleIt = angleHist.begin();
    auto energyIt = energyHist.begin();
    
    while(angleIt != angleHist.end() || energyIt != energyHist.end()) {
        if(angleIt != angleHist.end()) {
            out << angleIt->first << "," << angleIt->second << ",";
            ++angleIt;
        } else out << ",,";
        
        if(energyIt != energyHist.end()) {
            out << energyIt->first << "," << energyIt->second;
            ++energyIt;
        }
        out << "\n";
    }
    
    out.close();
}
