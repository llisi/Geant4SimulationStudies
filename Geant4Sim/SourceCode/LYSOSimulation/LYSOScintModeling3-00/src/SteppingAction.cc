//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: SteppingAction.cc 100946 2016-11-03 11:28:08Z gcosmo $
// 
/// \file SteppingAction.cc
/// \brief Implementation of the SteppingAction class

#include "SteppingAction.hh"
#include "ScintEventAction.hh"
#include "ScintRunAction.hh"
#include "ScintAnalysis.hh"

#include "ScintDetectorConstruction.hh"
#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4SDManager.hh"
#include "G4Track.hh"

#include "G4Step.hh"
#include "G4RunManager.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction()
  : G4UserSteppingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SteppingAction::UserSteppingAction(const G4Step* step)
{

  G4int NumberOne = 1;

  //This does not ever happen but keeps a warning from being given on compiling 

  if (NumberOne != 1){
    G4cout << "THIS SHOULD NEVER HAPPEND " << step;
  }
  
// Collect energy and track length step by step

  // get volume of the current step

  /*
  auto volumeName = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetName();
  auto volumePosition = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetTranslation();
  auto edep = step->GetTotalEnergyDeposit();

  auto analysisManager = G4AnalysisManager::Instance();

  //G4cout << volumeName << volumeCopyNo << G4endl;

  if (volumeName == "Pixel"){


    analysisManager->FillNtupleDColumn(5,0,edep);
    analysisManager->FillNtupleDColumn(5,1,volumePosition.x());
    analysisManager->FillNtupleDColumn(5,2,volumePosition.y());
    analysisManager->FillNtupleDColumn(5,3,volumePosition.z());
    analysisManager->AddNtupleRow(5);

    auto EdepIdTest = analysisManager->GetH2Id("EdepTest",true);

    analysisManager->FillH2(EdepIdTest, volumePosition.z(), volumePosition.x(), edep);

  }
  */
  
  // energy deposit
  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
