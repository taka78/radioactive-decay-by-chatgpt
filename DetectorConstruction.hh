#ifndef DETECTORCONSTRUCTION_HH
#define DETECTORCONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"

class G4VPhysicalVolume;

class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
  // Constructor
  DetectorConstruction();

  // Destructor
  ~DetectorConstruction();

  // Member functions
  G4VPhysicalVolume* Construct() override;
  G4double GetWorldSize() const;
  void ConstructSDandField();

private:
  // Member variables
  G4double fWorldSize;
};
#include "G4VSensitiveDetector.hh"

class MySensitiveDetector : public G4VSensitiveDetector {
public:
  MySensitiveDetector(const G4String& name) : G4VSensitiveDetector(name) {}

  G4bool ProcessHits(G4Step* aStep, G4TouchableHistory* ROhist) override {
    // Implement the processing of hits here
    return true;
  }
};
#endif