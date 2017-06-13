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
// $Id: TrackingAction.cc 81501 2014-05-31 13:51:51Z ldesorgh $
//
/// \file eventgenerator/exgps/src/TrackingAction.cc
/// \brief Implementation of the TrackingAction class
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "TrackingAction.hh"
#include "ScintEventAction.hh"
#include "ScintRunAction.hh"
#include "ScintAnalysis.hh"

#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4SDManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4UnitsTable.hh"
#include "G4Track.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "ScintDetectorConstruction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

TrackingAction::TrackingAction(const ScintDetectorConstruction* detectorConstruction)
:G4UserTrackingAction(),
fDetConstruction(detectorConstruction)
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void TrackingAction::PreUserTrackingAction(const G4Track* track)
{
  G4double time           = track->GetGlobalTime();

  G4int pid               = track->GetDynamicParticle()->GetPDGcode();
  G4double ekin           = track->GetKineticEnergy();
  G4ThreeVector vertex    = track->GetPosition();
  G4ThreeVector direction = track->GetMomentumDirection();
  
  auto analysisManager = G4AnalysisManager::Instance();
  
  //Primary Particles
  if (time == 0){
  G4double x = vertex.x(), y = vertex.y(), z = vertex.z();

  // fill histograms    
  analysisManager->FillH1(4,ekin);    
  analysisManager->FillH2(2,x,y);
  analysisManager->FillH2(3,z,y);
  analysisManager->FillH2(4,z,x);      
  
  // fill ntuple  
  analysisManager->FillNtupleIColumn(3,0,pid);
  analysisManager->FillNtupleDColumn(3,1,ekin);
  analysisManager->FillNtupleDColumn(3,2,x);
  analysisManager->FillNtupleDColumn(3,3,y);
  analysisManager->FillNtupleDColumn(3,4,z); 

  analysisManager->AddNtupleRow(3);

  analysisManager->FillNtupleDColumn(4,0,fDetConstruction->GetPixelHeight());

  analysisManager->FillNtupleDColumn(4,0,fDetConstruction->GetPixelNoZ());
  analysisManager->FillNtupleDColumn(4,1,fDetConstruction->GetPixelNoX());
  analysisManager->FillNtupleDColumn(4,2,fDetConstruction->GetPixelHeight());
  analysisManager->FillNtupleDColumn(4,3,fDetConstruction->GetPixelWidth());
  analysisManager->FillNtupleDColumn(4,4,fDetConstruction->GetInnerReflectorThickness());
  analysisManager->FillNtupleDColumn(4,5,fDetConstruction->GetOuterReflectorThickness());

}
  // Use this is you are intrested in tracking ALL particles. 
  // ~~ WARNING, THIS USES A LOT OF MEMORY ~~
  // Also un-comment in RunAction 

  /*
  else{
  G4double x = vertex.x(), y = vertex.y(), z = vertex.z();
  G4double theta = direction.theta(), phi = direction.phi();
  if (phi < 0.) phi += twopi;

  analysisManager->FillNtupleIColumn(4,0,pid);
  analysisManager->FillNtupleDColumn(4,1,ekin);
  analysisManager->FillNtupleDColumn(4,2,x);
  analysisManager->FillNtupleDColumn(4,3,y);
  analysisManager->FillNtupleDColumn(4,4,z); 
  analysisManager->FillNtupleDColumn(4,5,theta);
  analysisManager->FillNtupleDColumn(4,6,phi); 
  analysisManager->FillNtupleDColumn(4,7,weight);
  analysisManager->AddNtupleRow(4);
  }
  */
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....






