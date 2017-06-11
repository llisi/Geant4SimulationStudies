from ROOT import *


F_2MeV = TFile("/Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/PlottingScripts/TempPlots/x_EdepDist2MeV.root")
H_2MeV = F_2MeV.Get('x_Edep')
H_2MeV.Scale(1)

F_40MeV = TFile("/Users/Luc/Documents/Research/ScintillatorStudies/geant4sim/PlottingScripts/TempPlots/x_EdepDist40MeV.root")
H_40MeV = F_40MeV.Get('x_Edep')
H_40MeV.Scale(0.01)

H_Total = TH1F("x_Edep","Total; Displacement from Incidence [mm]; Normalized Energy Deposited / Pixel Size" , 60,0.,78.);
H_Divide = TH1F("x_Edep","Division; Displacement from Incidence [mm]; Normalized Energy Deposited / Pixel Size" , 60,0.,78.);



Stack = THStack("",";Displacement in Beam Line Direction [mm]; Normalized Energy Deposited / 1.3 mm")

H_Total.Add(H_2MeV)
H_Total.Add(H_40MeV)

H_Total.SetMinimum(0)

H_Total.Draw('hist')
H_2MeV.Draw('samehist')
H_40MeV.Draw('samehist')
#Stack.Add(H_2MeV)
#Stack.Add(H_40MeV)

#Stack.Draw('nostackhist')

raw_input('Press anything to quit... ')
'''
c1 = TCanvas("c_xEdepStack","xEdepStack",600,900)
pad1 = TPad("pad1","pad1",0,0.3,1,1)
pad1.SetBottomMargin(0)
pad1.Draw()
pad1.cd()

H_Total.Add(H_2MeV)
H_Total.Add(H_40MeV)

H_Total.Draw()
H_40MeV.Draw('same')
H_2MeV.Draw('same')

c1.cd()
pad2 = TPad("pad2","pad2",0,0,1,0.2)
pad2.SetTopMargin(0)
pad2.Draw()
pad2.cd()

H_Divide.Add(H_40MeV)
H_Divide.Add(H_2MeV,-1)
H_Divide.Draw("ep")

c1.cd()


raw_input("")
'''

