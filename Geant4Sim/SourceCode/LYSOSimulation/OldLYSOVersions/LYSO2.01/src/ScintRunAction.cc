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
// $Id: ScintRunAction.cc 100946 2016-11-03 11:28:08Z gcosmo $
//
/// \file ScintRunAction.cc
/// \brief Implementation of the ScintRunAction class

#include "ScintRunAction.hh"
#include "ScintAnalysis.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ScintRunAction::ScintRunAction()
 : G4UserRunAction()
{ 
  // set printing event number per each event
  G4RunManager::GetRunManager()->SetPrintProgress(1);     
  // Create analysis manager
  // The choice of analysis technology is done via selectin of a namespace
  // in ScintAnalysis.hh
  auto analysisManager = G4AnalysisManager::Instance();
  G4cout << "Using " << analysisManager->GetType() << G4endl;

  // Create directories 
  //analysisManager->SetHistoDirectoryName("histograms");
  //analysisManager->SetNtupleDirectoryName("ntuple");
  analysisManager->SetVerboseLevel(1);
  analysisManager->SetNtupleMerging(true);
    // Note: merging ntuples is available only with Root output

  // Book histograms, ntuple
  //
  
  // Creating histograms

  analysisManager->CreateH1("Eabs","Total Edep in LYSO", 200, 0., 100*MeV);      // 0      
  analysisManager->CreateH1("Labs","trackL in LYSO", 100, 0., 20*cm);            // 1
  analysisManager->CreateH1("EdepX","Edep in X", 60,-39.,39.);                   // 2
  analysisManager->CreateH1("HitBool","Hit Bool", 3,-1.,1.);                     // 3

  analysisManager->CreateH1("ParKN","kinetic energy", 200, 0, 110);              // 4
  analysisManager->CreateH1("ParDir1","direction: theta", 200, -3.2, 3.2);       // 5
  analysisManager->CreateH1("ParDir2","direction: phi", 200, -3.2, 3.2);         // 6

  analysisManager->CreateH2("Edep","Edep in pixels", 60 ,-39., 39., 
                                                    50, -33.15, 31.85);    // 0
  
  analysisManager->CreateH2("HitCount","Hitcount", 60 ,-39., 39., 
                                                    50, -33.15, 31.85);    // 1

  analysisManager->CreateH2("ParXY","vertex: XY",200,-40,40, 200, -40,40); // 2
  analysisManager->CreateH2("ParYZ","vertex: ZY",200,-40,40, 200, -40,40); // 3
  analysisManager->CreateH2("ParZX","vertex: ZX",200,-40,40, 200, -40,40); // 4
  analysisManager->CreateH2("Par2dDir1","direction: phi-theta",
                                                200, -3.2, 3.2, 200, -3.2, 3.2); // 5



  // Creating ntuple
  analysisManager->SetFirstNtupleId(1);

  analysisManager->CreateNtuple("Totals", "Edep and TrackL");
  analysisManager->CreateNtupleDColumn("Eabs");           //column 0         
  analysisManager->CreateNtupleDColumn("Labs");           //column 1
  analysisManager->CreateNtupleIColumn("HitBool");        //column 2
  analysisManager->CreateNtupleIColumn("EventNo");        //column 3

  analysisManager->CreateNtuple("PixelHits", "Edep and Position in Pixels");
  analysisManager->CreateNtupleDColumn("Edep");           //column 0
  analysisManager->CreateNtupleDColumn("xPos");           //column 1
  analysisManager->CreateNtupleDColumn("yPos");           //column 2
  analysisManager->CreateNtupleDColumn("zPos");           //column 3
  analysisManager->CreateNtupleDColumn("EdepPerCent");    //column 4

  analysisManager->CreateNtuple("PrimaryPartInfo", "Position and Energy Distribution");
  analysisManager->CreateNtupleIColumn("PrimaryParticleID");         //column 0
  analysisManager->CreateNtupleDColumn("PrimaryParticleEkin");       //column 1
  analysisManager->CreateNtupleDColumn("PrimaryParticlePosX");       //column 2
  analysisManager->CreateNtupleDColumn("PrimaryParticlePosY");       //column 3
  analysisManager->CreateNtupleDColumn("PrimaryParticlePosZ");       //column 4
  analysisManager->CreateNtupleDColumn("PrimaryParticleDirTheta");   //column 5
  analysisManager->CreateNtupleDColumn("PrimaryParticleDirPhi");     //column 6
  analysisManager->CreateNtupleDColumn("PrimaryParticleWeight");     //column 7

  analysisManager->CreateNtuple("Tracking", "Position and Energy Distribution");
  analysisManager->CreateNtupleIColumn("ParticleID");         //column 0
  analysisManager->CreateNtupleDColumn("ParticleEkin");       //column 1
  analysisManager->CreateNtupleDColumn("ParticlePosX");       //column 2
  analysisManager->CreateNtupleDColumn("ParticlePosY");       //column 3
  analysisManager->CreateNtupleDColumn("ParticlePosZ");       //column 4
  analysisManager->CreateNtupleDColumn("ParticleDirTheta");   //column 5
  analysisManager->CreateNtupleDColumn("ParticleDirPhi");     //column 6
  analysisManager->CreateNtupleDColumn("ParticleWeight");     //column 7

  analysisManager->FinishNtuple();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ScintRunAction::~ScintRunAction()
{
  delete G4AnalysisManager::Instance();  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ScintRunAction::BeginOfRunAction(const G4Run* /*run*/)
{ 
  //inform the runManager to save random number seed
  //G4RunManager::GetRunManager()->SetRandomNumberStore(true);
  
  // Get analysis manager
  auto analysisManager = G4AnalysisManager::Instance();

  // Open an output file
  //
  G4String fileName = "MonoEnergeticPhotons";
  analysisManager->OpenFile(fileName);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ScintRunAction::EndOfRunAction(const G4Run* /*run*/)
{
  // print histogram statistics
  //
  auto analysisManager = G4AnalysisManager::Instance();
  if ( analysisManager->GetH1(1) ) {
    G4cout << G4endl << " ----> print histograms statistic ";
    if(isMaster) {
      G4cout << "for the entire run " << G4endl << G4endl; 
    }
    else {
      G4cout << "for the local thread " << G4endl << G4endl; 
    }
    
    G4cout << " EAbs : mean = " 
       << G4BestUnit(analysisManager->GetH1(0)->mean(), "Energy") 
       << " rms = " 
       << G4BestUnit(analysisManager->GetH1(0)->rms(),  "Energy") << G4endl;
    
    
    G4cout << " LAbs : mean = " 
      << G4BestUnit(analysisManager->GetH1(1)->mean(), "Length") 
      << " rms = " 
      << G4BestUnit(analysisManager->GetH1(1)->rms(),  "Length") << G4endl;

  }

  // save histograms & ntuple
  //
  analysisManager->Write();
  analysisManager->CloseFile();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
