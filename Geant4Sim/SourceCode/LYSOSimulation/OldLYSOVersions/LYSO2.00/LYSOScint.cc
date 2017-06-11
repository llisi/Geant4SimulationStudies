
#include "G4VisExecutive.hh"

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4UIExecutive.hh"
#include "G4UIcommand.hh"

#include "ScintDetectorConstruction.hh"
#include "ScintActionInitialization.hh"

#include "G4UIExecutive.hh"
#include "FTFP_BERT.hh"
#include "G4StepLimiterPhysics.hh"


int main(int argc,char** argv)
{

// Detect interactive mode (if no arguments) and define UI session
//
  G4UIExecutive* ui = 0;
  if ( argc == 1 ) {
    ui = new G4UIExecutive(argc, argv);
  }

  // construct the default run manager
  G4RunManager* runManager = new G4RunManager;

// set mandatory initialization classes
  runManager->SetUserInitialization(new ScintDetectorConstruction);
  

// Physics list
  G4VModularPhysicsList* physicsList = new FTFP_BERT;
  physicsList->RegisterPhysics(new G4StepLimiterPhysics());
  runManager->SetUserInitialization(physicsList);


// set mandatory user action class
  runManager->SetUserInitialization(new ScintActionInitialization);


// Instantiation and initialization of the Visualization Manager
// visualization manager
  G4VisManager* visManager = new G4VisExecutive;
// G4VisExecutive can take a verbosity argument - see /vis/verbose guidance.
// G4VisManager* visManager = new G4VisExecutive("Quiet");
  visManager->Initialize();

// Get the pointer to the User Interface manager
  G4UImanager* UImanager = G4UImanager::GetUIpointer();
// Process macro or start UI session
//
  if ( ! ui ) { 
// batch mode
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UImanager->ApplyCommand(command+fileName);
  }
  else { 
// interactive mode
    UImanager->ApplyCommand("/control/execute init_vis.mac");
    ui->SessionStart();
    delete ui;
  }

// job termination
  delete visManager;
  delete runManager;
  

  return 0;
}
