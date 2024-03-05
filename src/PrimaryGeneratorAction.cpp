#include "PrimaryGeneratorAction.h"

#include <CLHEP/Units/SystemOfUnits.h>
#include <G4IonTable.hh>
#include <G4ParticleGun.hh>
#include <G4ParticleTable.hh>

PrimaryGeneratorAction::PrimaryGeneratorAction()
{
    particleGun = new G4ParticleGun(1);
    particleGun->SetParticlePosition({0, 0, -1 * CLHEP::m});
    particleGun->SetParticleMomentumDirection({0, 0, 1});
}
PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
    delete particleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
    auto particleDefinition = G4ParticleTable::GetParticleTable()->FindParticle("proton");
    particleGun->SetParticleEnergy(240 * CLHEP::MeV);

    // auto particleDefinition = G4IonTable::GetIonTable()->GetIon(1000060120);
    // particleGun->SetParticleEnergy(240 * 12 * CLHEP::MeV);

    particleGun->SetParticleDefinition(particleDefinition);

    particleGun->GeneratePrimaryVertex(anEvent);
}