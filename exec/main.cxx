#include "ActionInitialization.h"
#include "DetectorConstruction.h"

#include <G4RunManagerFactory.hh>

#include <QGSP_BIC_HP.hh>

#include <G4VUserDetectorConstruction.hh>

#include <G4UIExecutive.hh>
#include <G4VisExecutive.hh>

int main(int argc, char** argv)
{
    auto ui = new G4UIExecutive(argc, argv);

    auto runManager = G4RunManagerFactory::CreateRunManager(G4RunManagerType::SerialOnly);

    // initialize physics list
    runManager->SetUserInitialization(new QGSP_BIC_HP);

    // initialize geometry
    runManager->SetUserInitialization(new DetectorConstruction);

    // initialize user actions
    runManager->SetUserInitialization(new ActionInitialization);

    // Initialize visualization with the default graphics system
    auto visManager = new G4VisExecutive(argc, argv);
    visManager->Initialize();

    // Get the pointer to the User Interface manager
    auto UImanager = G4UImanager::GetUIpointer();

    runManager->Initialize();

    UImanager->ApplyCommand("/control/execute ../vis.mac");

    // runManager->BeamOn(10);
    ui->SessionStart();

    delete ui;
    delete visManager;
    delete runManager;

    return 0;
}