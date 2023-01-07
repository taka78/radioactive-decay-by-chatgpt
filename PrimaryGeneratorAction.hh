#ifndef PRIMARYGENERATORACTION_HH
#define PRIMARYGENERATORACTION_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4Event.hh"

class DetectorConstruction;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
 public:
  PrimaryGeneratorAction(DetectorConstruction* detector);
  virtual ~PrimaryGeneratorAction();

  virtual void GeneratePrimaries(G4Event* event);

 private:
  G4ParticleGun* fParticleGun;
  DetectorConstruction* fDetector;
};

#endif
