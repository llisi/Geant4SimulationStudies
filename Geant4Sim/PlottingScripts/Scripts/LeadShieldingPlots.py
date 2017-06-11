from ROOT import *
import math

def PrintHitInfo(hitInfo):

	keys = hitInfo.keys()
	for key in keys:

		noOfCounts = hitInfo[key]["Counts"]

		if noOfCounts != 0:
			print "~~~~~~~~~~~~"
			print "Particle: ", key
			print "Counts: ", noOfCounts
			print "MeanEnergy: ", hitInfo[key]["MeanEnergy"]/noOfCounts, "[MeV"
			print ""

filePath="/Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/LeadSheildParticleInfo.root"

rFile = TFile(filePath)

# Get Trees

FrontHits = rFile.Get('ETT_FrontHits')
BackHits = rFile.Get('ETT_BackHits')


# How many events in file (1 event = 1 incedent photon)

nFrontHits = FrontHits.GetEntries()
nBackHits = BackHits.GetEntries()


HitInfo = {"e-":{"Counts":0,"MeanEnergy":0}, "e+":{"Counts":0,"MeanEnergy":0}, "gamma":{"Counts":0,"MeanEnergy":0}, "N":{"Counts":0,"MeanEnergy":0}, "P":{"Counts":0,"MeanEnergy":0}, "Mu-":{"Counts":0,"MeanEnergy":0}, "Mu+":{"Counts":0,"MeanEnergy":0}, "Pi0":{"Counts":0,"MeanEnergy":0}, "Pi+":{"Counts":0,"MeanEnergy":0}, "Pi-":{"Counts":0,"MeanEnergy":0}}
NeutrinoHits = 0
OtherHits = 0
OtherHitIDs = []

ParticleIDs = {11:"e-", -11:"e+", 22:"gamma", 2112:"N", 2212:"P", 13:"Mu-", -13:"Mu+",111:"Pi0",211:"Pi+",-211:"Pi-"}
NeutrinoIDs = [12,14]

for hitNo in range(nBackHits):

	if hitNo%1000 == 0:
		print "Processing Back Hit: ", hitNo

	#Get the Hit
	BackHits.GetEntry(hitNo)

	Energy = BackHits.GetLeaf('eKin').GetValue()

	pdgID = BackHits.GetLeaf('pdgID').GetValue()
	if pdgID in ParticleIDs.keys():
		HitInfo[ParticleIDs[pdgID]]["Counts"] += 1
		HitInfo[ParticleIDs[pdgID]]["MeanEnergy"] += Energy

	elif abs(pdgID) in NeutrinoIDs:
		NeutrinoHits += 1

	else:
		OtherHitIDs.append(pdgID)
		OtherHits += 1

PrintHitInfo(HitInfo)

print "Neutrino Hits: ", NeutrinoHits
print "Unknown Hits: ", OtherHits, " with IDs: ", OtherHitIDs

