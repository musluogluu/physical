#include "RunAction.hh"
#include "NeutronHitsCollection.hh"
#include <fstream>

void RunAction::EndOfRunAction(const G4Run* run) {
    // Text dosyasını aç
    std::ofstream out("neutron_data.txt");
    
    // Başlık satırı
    out << "=== NÖTRON VERİLERİ ===\n";
    out << "Toplam Nötron: " << fHitsCollection->entries() << "\n\n";
    out << "Sıra | Açı[°] | Enerji[MeV] | X[mm] | Y[mm] | Z[mm]\n";
    out << "----------------------------------------------------\n";

    // Tüm hit'leri yazdır
    for(size_t i = 0; i < fHitsCollection->entries(); i++) {
        NeutronHit* hit = (*fHitsCollection)[i];
        G4ThreeVector pos = hit->GetPosition();
        G4ThreeVector dir = hit->GetMomentumDirection();
        
        out << i+1 << " | "
            << dir.theta()/deg << " | "
            << hit->GetEnergy()/MeV << " | "
            << pos.x()/mm << " | " 
            << pos.y()/mm << " | " 
            << pos.z()/mm << "\n";
    }

    out.close();

    // Terminal çıktısı
    G4cout << "\n=== KAYIT TAMAMLANDI ===\n"
           << "Toplam " << fHitsCollection->entries() << " nötron kaydedildi\n"
           << "Detaylar 'neutron_data.txt' dosyasında\n"
           << G4endl;
}
