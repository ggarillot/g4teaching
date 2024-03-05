#include "DetectorConstruction.h"

#include <CLHEP/Units/SystemOfUnits.h>
#include <G4Box.hh>
#include <G4LogicalVolume.hh>
#include <G4NistManager.hh>
#include <G4PVPlacement.hh>
#include <G4ThreeVector.hh>

G4VPhysicalVolume* DetectorConstruction::Construct()
{
    // call the class responsible for handling materials
    auto nist = G4NistManager::Instance();

    // auto voidMaterial = nist->FindOrBuildMaterial("G4_Galactic");
    auto airMaterial = nist->FindOrBuildMaterial("G4_AIR");
    auto waterMaterial = nist->FindOrBuildMaterial("G4_WATER");

    auto solidWorld = new G4Box("solidWorld", 5 * CLHEP::m, 5 * CLHEP::m, 5 * CLHEP::m);
    auto logicWorld = new G4LogicalVolume(solidWorld, airMaterial, "logicWorld");

    auto physWorld = new G4PVPlacement(nullptr,     // rotation matrix
                                       {0, 0, 0},   // position of the volume center
                                       logicWorld,  // logical volume
                                       "physWorld", // name
                                       nullptr,     // the mother volume
                                       false,       // is there nany of this volume
                                       0,           // copy number
                                       true);       // overlaps checks

    G4double boxSize = 30 * CLHEP::cm;

    auto solidWater = new G4Box("solidWater", 0.5 * boxSize, 0.5 * boxSize, 0.5 * boxSize);
    auto logicWater = new G4LogicalVolume(solidWater, waterMaterial, "logicWater");

    new G4PVPlacement(nullptr,               // rotation matrix
                      {0, 0, 0.5 * boxSize}, // position of the volume center
                      logicWater,            // logical volume
                      "physWater",           // name
                      logicWorld,            // the mother volume
                      false,                 // is there nany of this volume
                      0,                     // copy number
                      true);                 // overlaps checks

    return physWorld;
}