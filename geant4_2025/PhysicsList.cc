#include "PhysicsList.hh"
#include "FTFP_BERT.hh"  // Tüm temel fizik süreçlerini içerir

PhysicsList::PhysicsList() {
    // TEK SATIRDA FİZİK LİSTESİ
    RegisterPhysics(new FTFP_BERT());  // Hem EM hem hadronik süreçler
}

PhysicsList::~PhysicsList() {}
