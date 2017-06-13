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
// $Id: ScintEventAction.cc 100946 2016-11-03 11:28:08Z gcosmo $
// 
/// \file ScintEventAction.cc
/// \brief Implementation of the ScintEventAction class

#include "ScintEventAction.hh"
#include "ScintCalorimeterSD.hh"
#include "ScintCalorHit.hh"
#include "ScintAnalysis.hh"

#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4SDManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4UnitsTable.hh"

#include "Randomize.hh"
#include <iomanip>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ScintEventAction::ScintEventAction()
 : G4UserEventAction(),
   fAbsHCID(-1)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ScintEventAction::~ScintEventAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ScintCalorHitsCollection* 
ScintEventAction::GetHitsCollection(G4int hcID,
                                  const G4Event* event) const
{
  auto hitsCollection 
    = static_cast<ScintCalorHitsCollection*>(
        event->GetHCofThisEvent()->GetHC(hcID));
  
  if ( ! hitsCollection ) {
    G4ExceptionDescription msg;
    msg << "Cannot access hitsCollection ID " << hcID; 
    G4Exception("ScintEventAction::GetHitsCollection()",
      "MyCode0003", FatalException, msg);
  }         

  return hitsCollection;
}    

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ScintEventAction::PrintEventStatistics() const
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ScintEventAction::BeginOfEventAction(const G4Event* /*event*/)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ScintEventAction::EndOfEventAction(const G4Event* event)
{  
  // Get hits collections IDs (only once)
  if ( fAbsHCID == -1 ) {
    fAbsHCID 
      = G4SDManager::GetSDMpointer()->GetCollectionID("AbsorberHitsCollection");
  }

  // Get hits collections
  auto absoHC = GetHitsCollection(fAbsHCID, event);

  // Get hit with total values
  auto absoHit = (*absoHC)[absoHC->entries()-1];
 

  // Print per event (modulo n)
  //
  auto eventID = event->GetEventID();
  auto printModulo = G4RunManager::GetRunManager()->GetPrintProgress();
  if ( ( printModulo > 0 ) && ( eventID % printModulo == 0 ) ) {
    //G4cout << "---> End of event: " << eventID << G4endl;     


  }  
  
  // Fill histograms, ntuple
  //

  // get analysis manager

  auto analysisManager = G4AnalysisManager::Instance();
  analysisManager->FillNtupleIColumn(1,3,eventID);

  // fill histograms
  //Only fill if energy was deposited
  if (absoHit->GetEdep() != 0){

  analysisManager->FillH1(analysisManager->GetH1Id("HitBool",true), 0.9);
  analysisManager->FillH1(analysisManager->GetH1Id("Eabs",true), absoHit->GetEdep());
  analysisManager->FillNtupleIColumn(1,2,1);

  }

  else if (absoHit->GetEdep() == 0){
    analysisManager->FillH1(analysisManager->GetH1Id("HitBool",true), -0.9);
    analysisManager->FillNtupleIColumn(1,2,-1);
  }

  analysisManager->FillH1(analysisManager->GetH1Id("Labs",true), absoHit->GetTrackLength());
  
  // fill ntuple
  analysisManager->FillNtupleDColumn(1,0, absoHit->GetEdep());

  analysisManager->FillNtupleDColumn(1,1, absoHit->GetTrackLength());
  analysisManager->AddNtupleRow(1);

  auto EdepId = analysisManager->GetH2Id("Edep",true);
  auto HitCountId = analysisManager->GetH2Id("HitCount",true);
  auto EdepXId = analysisManager->GetH1Id("EdepX",true);
  auto EdepZId = analysisManager->GetH1Id("EdepZ",true);

  G4double perCentEdep;

  // Only fill if there is at least some energy deposited in Calo

  if (absoHit->GetEdep() != 0.){

  for(G4int i=0;i<absoHC->entries()-1;i++){

      //G4cout << (*absoHC)[i]->GetEdep()<< " " << absoHit->GetEdep() << " " << perCentEdep << G4endl;
      if((*absoHC)[i]->GetEdep() != 0.){

        analysisManager->FillNtupleDColumn(2,0, (*absoHC)[i]->GetEdep());
        analysisManager->FillNtupleDColumn(2,1, (*absoHC)[i]->GetTrackPos().x());
        analysisManager->FillNtupleDColumn(2,2, (*absoHC)[i]->GetTrackPos().y());
        analysisManager->FillNtupleDColumn(2,3, (*absoHC)[i]->GetTrackPos().z());      

        perCentEdep = (*absoHC)[i]->GetEdep()/absoHit->GetEdep()*100;

        analysisManager->FillNtupleDColumn(2,4, perCentEdep);

        analysisManager->AddNtupleRow(2);
        analysisManager->FillH1(EdepXId, (*absoHC)[i]->GetTrackPos().x(),(*absoHC)[i]->GetEdep());
        analysisManager->FillH1(EdepZId, (*absoHC)[i]->GetTrackPos().z() + 39,(*absoHC)[i]->GetEdep());
        analysisManager->FillH2(EdepId, (*absoHC)[i]->GetTrackPos().z(),(*absoHC)[i]->GetTrackPos().x(),(*absoHC)[i]->GetEdep());
        analysisManager->FillH2(HitCountId, (*absoHC)[i]->GetTrackPos().z(),(*absoHC)[i]->GetTrackPos().x()); 
      
      }
   }
 }

}  


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
