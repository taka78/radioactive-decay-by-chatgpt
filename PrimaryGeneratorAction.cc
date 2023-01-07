#include "PrimaryGeneratorAction.hh"

#include "DetectorConstruction.hh"
#include "G4Event.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4Geantino.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction(DetectorConstruction* detector)
  : G4VUserPrimaryGeneratorAction(),
    fDetector(detector)
{
  G4int n_particle = 1;
  fParticleGun = new G4ParticleGun(n_particle);
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  delete fParticleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* event)
{
  // Set the particle type to gamma
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName;
  G4ParticleDefinition* particle = particleTable->FindParticle(particleName="gamma");
  fParticleGun->SetParticleDefinition(particle);

  // Set the initial energy of the particle
  G4double energy = 1*MeV;
  fParticleGun->SetParticleEnergy(energy);

  // Set the initial position of the particle
  G4double worldSize = fDetector->GetWorldSize();
  G4double x = (2*G4UniformRand() - 1)*worldSize/2;
  G4double y = (2*G4UniformRand() - 1)*worldSize/2;
  G4double z = (2*G4UniformRand() - 1)*worldSize/2;
  fParticleGun->SetParticlePosition(G4ThreeVector(x, y, z));

  // Generate the primary particle
  fParticleGun->GeneratePrimaryVertex(event);
}