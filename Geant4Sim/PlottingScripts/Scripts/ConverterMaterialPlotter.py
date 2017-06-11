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
			print "MeanEnergy: ", hitInfo[key]["MeanEnergy"]/noOfCounts, "[MeV]"
			print ""

Thickness = raw_input("Enter the taret thickness in [mm]: ")
EnergyRequired = raw_input("Enter the gamma Energy [MeV]")

filePath="/Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/ParticleInfo_%sMeV_%smm.root" %(EnergyRequired,Thickness)

rFile = TFile(filePath)

# Get Trees
FrontHits = rFile.Get('ETT_FrontHits')
PrimaryParticles = rFile.Get('PrimaryParticles')
nGammas = PrimaryParticles.GetEntries()

#Initial Particle Energy 
PrimaryParticles.GetEntry(1)
E0 = PrimaryParticles.GetLeaf('eKin').GetValue()

print "Primary particle energy: ", E0

# How many events in file (1 event = 1 incedent photon)

nFrontHits = FrontHits.GetEntries()


HitInfo = {"e-":{"Counts":0,"MeanEnergy":0}, "e+":{"Counts":0,"MeanEnergy":0}, "gamma":{"Counts":0,"MeanEnergy":0}, "N":{"Counts":0,"MeanEnergy":0}, "P":{"Counts":0,"MeanEnergy":0}, "Mu-":{"Counts":0,"MeanEnergy":0}, "Mu+":{"Counts":0,"MeanEnergy":0}, "Pi0":{"Counts":0,"MeanEnergy":0}, "Pi+":{"Counts":0,"MeanEnergy":0}, "Pi-":{"Counts":0,"MeanEnergy":0}}
NeutrinoHits = 0
OtherHits = 0
OtherHitIDs = []
PassThroughs = 0

ParticleIDs = {11:"e-", -11:"e+", 22:"gamma", 2112:"N", 2212:"P", 13:"Mu-", -13:"Mu+",111:"Pi0",211:"Pi+",-211:"Pi-"}
NeutrinoIDs = [12,14]


#Initialize Histograms

H_ElectronEKin = TH1F("e-eKin","e-: %s MeV Gamma; Electron Energy [MeV] ; Average Percent of Electrons / 100 KeV" %E0, int(E0*10),0,int(E0))
H_PositronEKin = TH1F("e+eKin","e+: %s MeV Gamma; Positron Energy [MeV] ; Average Percent of Positrons / 100 KeV" %E0, int(E0*10),0,int(E0))
H_GammaEKin = TH1F("geKin","Gamma: %s MeV Gamma; Exit Gamma Energy [MeV] ; Average Percent of Gammas / 100 KeV" %E0, int(E0*10),0,int(E0))

H_REL_ElectronEKin = TH1F("e-eKinR","e-: %s MeV Gamma; Electron Energy [Percent E_{0}] ; Average Percent of Electrons / 100 KeV" %E0, 50,0,1)
H_REL_PositronEKin = TH1F("e+eKinR","e+: %s MeV Gamma; Positron Energy [Percent E_{0}] ; Average Percent of Positrons / 100 KeV" %E0, 50,0,1)
H_REL_GammaEKin = TH1F("geKinR","Gamma: %s MeV Gamma; Exit Gamma Energy [Percent E_{0}] ; Average Percent of Gammas / 100 KeV" %E0, 50,0,1)


H_El_RPos = TH1F("el_RPos","Electron Radial Distribtuion; R [cm] ; Average Percent of Electrons",100, 0,2)
H_El_Angle = TH1F("el_ThetaDist","Electron Angle; Theta; Average Percent of Electrons",64,-3.2,3.2)
H_El_XYFullDist = TH2F("el_AngularSpread","Electron Pointing ; x [cm]; y [cm]",100,-2,2,100,-2,2)
H_El_RThetaDist = TH2F("el_RThetaDist","Electron Theta vs R; R [cm]; Theta",100,0,2,64,-3.2,3.2)

for hitNo in range(nFrontHits):

	if hitNo%100000 == 0:
		print "Processing Hit: ", hitNo ,"/", nFrontHits

	#Get the Hit
	FrontHits.GetEntry(hitNo)

	Energy = FrontHits.GetLeaf('eKin').GetValue()
	pdgID = FrontHits.GetLeaf('pdgID').GetValue()
	x_Pos = FrontHits.GetLeaf('xPos').GetValue()
	y_Pos = FrontHits.GetLeaf('yPos').GetValue()

	Px = FrontHits.GetLeaf('Px').GetValue()
	Py = FrontHits.GetLeaf('Py').GetValue()
	Pz = FrontHits.GetLeaf('Pz').GetValue()

	if pdgID in ParticleIDs.keys():
		HitInfo[ParticleIDs[pdgID]]["Counts"] += 1
		HitInfo[ParticleIDs[pdgID]]["MeanEnergy"] += Energy

		if pdgID == 11:
			#e-
			H_ElectronEKin.Fill(Energy)
			H_REL_ElectronEKin.Fill(Energy/E0)

			R = math.sqrt(x_Pos**2 + y_Pos**2)
			pR = math.sqrt(Px**2 + Py**2)

			Theta = math.atan2(pR,Pz)

			H_El_RPos.Fill(R)
			H_El_Angle.Fill(Theta)

			H_El_XYFullDist.Fill(x_Pos,y_Pos)
			H_El_RThetaDist.Fill(R,Theta)


		elif pdgID == -11:
			#e+
			H_PositronEKin.Fill(Energy)
			H_REL_PositronEKin.Fill(Energy/E0)

		elif pdgID == 22:
			if Energy == E0:
				#"Pass-through" Gammas
				PassThroughs += 1
				continue
			elif Energy != E0:
				H_GammaEKin.Fill(Energy)
				H_REL_GammaEKin.Fill(Energy/E0)


	elif abs(pdgID) in NeutrinoIDs:
		NeutrinoHits += 1

	else:
		OtherHitIDs.append(pdgID)
		OtherHits += 1

PrintHitInfo(HitInfo)

## Normalize Histograms ##

H_ElectronEKin.Sumw2(kTRUE)
Norm = H_ElectronEKin.Integral()
if Norm != 0:
	H_ElectronEKin.Scale(1/Norm)

H_PositronEKin.Sumw2(kTRUE)
Norm = H_PositronEKin.Integral()
if Norm != 0:
	H_PositronEKin.Scale(1/Norm)

H_GammaEKin.Sumw2(kTRUE)
Norm = H_GammaEKin.Integral()
if Norm != 0:
	H_GammaEKin.Scale(1/Norm)

H_El_RPos.Sumw2(kTRUE)
Norm = H_El_RPos.Integral()
if Norm != 0:
	H_El_RPos.Scale(1/Norm)

H_El_Angle.Sumw2(kTRUE)
Norm = H_El_Angle.Integral()
if Norm != 0:
	H_El_Angle.Scale(1/Norm)

H_El_RThetaDist.Sumw2(kTRUE)
Norm = H_El_RThetaDist.Integral()
if Norm != 0:
	H_El_RThetaDist.Scale(1/Norm)


H_REL_ElectronEKin.Sumw2(kTRUE)
Norm = H_REL_ElectronEKin.Integral()
if Norm != 0:
	H_REL_ElectronEKin.Scale(1/Norm)

H_REL_PositronEKin.Sumw2(kTRUE)
Norm = H_REL_PositronEKin.Integral()
if Norm != 0:
	H_REL_PositronEKin.Scale(1/Norm)

H_REL_GammaEKin.Sumw2(kTRUE)
Norm = H_REL_GammaEKin.Integral()
if Norm != 0:
	H_REL_GammaEKin.Scale(1/Norm)

Norm = H_El_XYFullDist.Integral()
if Norm != 0:
	H_El_XYFullDist.Scale(1/Norm)

print "Neutrino Hits: ", NeutrinoHits
print "Unknown Hits: ", OtherHits, " with IDs: ", OtherHitIDs
print "Pass-through Gammas: ", PassThroughs
print " "

'''
H_ElectronEKin.Draw()
raw_input("Press enter/return to continue...")
H_PositronEKin.Draw()
raw_input("Press enter/return to continue...")
H_GammaEKin.Draw()
raw_input("Press enter/return to continue...")
H_REL_ElectronEKin.Draw()
raw_input("Press enter/return to continue...")
H_REL_PositronEKin.Draw()
raw_input("Press enter/return to continue...")
H_REL_GammaEKin.Draw()
raw_input("Press enter/return to continue...")
H_El_RPos.Draw()
raw_input("Press enter/return to continue...")
H_El_Angle.Draw()
raw_input("Press enter/return to continue...")
H_El_XYFullDist.Draw('colz')
raw_input("Press enter/return to continue...")
H_El_RThetaDist.Draw('colz')
'''

print " "

H_ElectronEKin.SaveAs('./TempPlots/ElectronEkin_%sGammas_%sThickness.root' %(E0,Thickness))
H_PositronEKin.SaveAs('./TempPlots/PositronEkin_%sGammas_%sThickness.root' %(E0,Thickness))
H_GammaEKin.SaveAs('./TempPlots/GammaEkin_%sGammas_%sThickness.root' %(E0,Thickness))
H_REL_ElectronEKin.SaveAs('./TempPlots/REL_ElectronEkin_%sGammas_%sThickness.root' %(E0,Thickness))
H_REL_PositronEKin.SaveAs('./TempPlots/REL_PositronEkin_%sGammas_%sThickness.root' %(E0,Thickness))
H_REL_GammaEKin.SaveAs('./TempPlots/REL_GammaEkin_%sGammas_%sThickness.root' %(E0,Thickness))
H_El_RPos.SaveAs('./TempPlots/ElRDist_%sGammas_%sThickness.root' %(E0,Thickness))
H_El_Angle.SaveAs('./TempPlots/ElThetaDist_%sGammas_%sThickness.root' %(E0,Thickness))
H_El_XYFullDist.SaveAs('./TempPlots/El_XYFullDist_%sGammas_%sThickness.root' %(E0,Thickness))
H_El_RThetaDist.SaveAs('./TempPlots/El_RThetaDist_%sGammas_%sThickness.root' %(E0,Thickness))

print " "
print "~~~~ Gamma Interaction Rate at %smm and %sMeV ~~~~" %(Thickness,E0)
print 1.0 - float(PassThroughs)/float(nGammas)
print " "
print "~~~~ Electron vs. Positrons at %smm and %sMeV ~~~~" %(Thickness,E0)
print ""
print "Electrons: ", HitInfo['e-']["Counts"]
print "Positrons: ", HitInfo['e+']["Counts"]
print "Difference: ", HitInfo['e-']["Counts"] - HitInfo['e+']["Counts"]
print "Interacting Gammas: ", float(nGammas)-float(PassThroughs)
print "Effective Pair Prod Rate: ", HitInfo["e+"]["Counts"]/(float(nGammas)-float(PassThroughs))
print ""

raw_input("Press enter/return to quit...")
print " "
print "Quitting..."
print " "



