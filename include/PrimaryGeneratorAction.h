#pragma once

#include <G4VUserPrimaryGeneratorAction.hh>

class G4ParticleGun;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    PrimaryGeneratorAction();
    ~PrimaryGeneratorAction();

    void GeneratePrimaries(G4Event* anEvent) override;

  protected:
    G4ParticleGun* particleGun = nullptr;
};