#include "DetectorConstruction.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4RotationMatrix.hh"
#include "G4Transform3D.hh"
#include "G4SDManager.hh"
#include "G4VSensitiveDetector.hh"
#include "G4MultiFunctionalDetector.hh"
#include "G4VPrimitiveScorer.hh"
#include "G4PSEnergyDeposit.hh"
#include "G4PSDoseDeposit.hh"
#include "G4VisAttributes.hh"
#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"
#include "GMTubeSD.hh"


DetectorConstruction::DetectorConstruction()
  : G4VUserDetectorConstruction(),
    fWorldSize(10*m)
{
}

DetectorConstruction::~DetectorConstruction()
{
}

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  // Get the material definitions from the NIST database
  G4NistManager* nistManager = G4NistManager::Instance();
  G4Material* air = nistManager->FindOrBuildMaterial("G4_AIR");
  G4Material* aluminum = nistManager->FindOrBuildMaterial("G4_Al");

  // Create the world volume
  G4Box* worldSolid = new G4Box("WorldSolid", fWorldSize/2, fWorldSize/2, fWorldSize/2);
  G4LogicalVolume* worldLogical = new G4LogicalVolume(worldSolid, air, "WorldLogical");
  G4VPhysicalVolume* worldPhysical = new G4PVPlacement(0, G4ThreeVector(), worldLogical, "WorldPhysical", 0, false, 0);

  // Create the GM tube
  G4double innerRadius = 0*mm;
  G4double outerRadius = 1*mm;
  G4double height = 10*cm;
  G4double startAngle = 0*deg;
  G4double spanningAngle = 360*deg;
  G4Tubs* gmTubeSolid = new G4Tubs("GMTubeSolid", innerRadius, outerRadius, height/2, startAngle, spanningAngle);
  G4LogicalVolume* gmTubeLogical = new G4LogicalVolume(gmTubeSolid, aluminum, "GMTubeLogical");
  new G4PVPlacement(0, G4ThreeVector(0, 0, 0), gmTubeLogical, "GMTubePhysical", worldLogical, false, 0);

  // Return the world volume
  return worldPhysical;
}

void DetectorConstruction::ConstructSDandField()
{
  // Create a sensitive detector for the GM tube
  G4SDManager* sdManager = G4SDManager::GetSDMpointer();
  MySensitiveDetector* GMTubeSD = new MySensitiveDetector("GMTubeSD");
  G4SDManager::GetSDMpointer()->AddNewDetector(GMTubeSD);

  // Associate the sensitive detector with the GM tube logical volume
  G4LogicalVolume* gmTubeLogical = G4LogicalVolumeStore::GetInstance()->GetVolume("GMTubeLogical");
  gmTubeLogical->SetSensitiveDetector(GMTubeSD);
}

G4double DetectorConstruction::GetWorldSize() const
{
  return fWorldSize;
}
