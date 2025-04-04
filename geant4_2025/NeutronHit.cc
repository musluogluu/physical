// NeutronHit.cc
#include "NeutronHit.hh"
#include "G4SystemOfUnits.hh"

G4ThreadLocal G4Allocator<NeutronHit>* NeutronHitAllocator = nullptr;

NeutronHit::NeutronHit() : fEnergy(0), fMomentumDir() {}
NeutronHit::~NeutronHit() {}

void* NeutronHit::operator new(size_t) {
    if(!NeutronHitAllocator)
        NeutronHitAllocator = new G4Allocator<NeutronHit>;
    return (void*)NeutronHitAllocator->MallocSingle();
}

void NeutronHit::operator delete(void* hit) {
    NeutronHitAllocator->FreeSingle((NeutronHit*) hit);
}
