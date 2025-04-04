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

void RunAction::EndOfRunAction(const G4Run* run) {
    // CSV dosyasını aç
    std::ofstream out("neutron_data.csv");
    
    // Başlık satırı
    out << "Angle[deg],Count,Energy[MeV],Count,TotalNeutrons\n";
    
    // Açı ve enerji histogramlarını yazdır
    auto angleIt = angleHist.begin();
    auto energyIt = energyHist.begin();
    size_t max_lines = std::max(angleHist.size(), energyHist.size());
    
    for(size_t i=0; i<max_lines; ++i) {
        // Açı verileri
        if(angleIt != angleHist.end()) {
            out << angleIt->first << "," << angleIt->second << ",";
            ++angleIt;
        } else {
            out << ",,";
        }
        
        // Enerji verileri
        if(energyIt != energyHist.end()) {
            out << energyIt->first << "," << energyIt->second;
            ++energyIt;
        } else {
            out << ",";
        }
        
        // Toplam nötron sayısı (her satırda)
        out << "," << fHitsCollection->entries() << "\n";
    }
    
    out.close();
    
    // Terminale özet bilgi yazdır
    G4cout << "\n--- Nötron Simülasyon Sonuçları ---\n"
           << "Toplam nötron sayısı: " << fHitsCollection->entries() << "\n"
           << "Veriler 'neutron_data.csv' dosyasına kaydedildi.\n"
           << G4endl;
}
