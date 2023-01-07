#include "PhysicsList.hh"

#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4VModularPhysicsList.hh"

PhysicsList::PhysicsList()
{
  // Add the decay physics
  G4DecayPhysics* decayPhysics = new G4DecayPhysics;
  decayPhysics->ConstructProcess();
  RegisterPhysics(decayPhysics);

  // Add the radioactive decay physics
  G4RadioactiveDecayPhysics* radioactiveDecayPhysics = new G4RadioactiveDecayPhysics;
  radioactiveDecayPhysics->ConstructProcess();
  RegisterPhysics(radioactiveDecayPhysics);
}

PhysicsList::~PhysicsList()
{
}

void PhysicsList::SetCuts()
{
  // Set the cut values for the simulation
  SetCutsWithDefault();
}
