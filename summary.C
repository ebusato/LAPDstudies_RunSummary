// Example: root -l 'summary.C("", "~/godaq_rootfiles/analysis_v2.10.0/run9.root")'

TGraph* GetGraph(TChain* ch, TString name, TCut cut, int color)
{
	ch->Draw(name, cut, "goff");
	TGraph *g = new TGraph(ch->GetEntries(),ch->GetV2(),ch->GetV1());
	g->SetMarkerColor(color);
	g->SetMarkerStyle(8);
	g->SetMarkerSize(0.5);
	g->SetLineColor(color);
	return g;
}

void summary(TString cut_base, TString fileName0, TString fileName1="", TString fileName2="", TString fileName3="", TString fileName4="", 
	     TString fileName5="", TString fileName6="", TString fileName7="",
	     TString fileName8="", TString fileName9="") {
	gStyle->SetOptStat(0);
	gStyle->SetOptTitle(0);
	gStyle->SetPadLeftMargin(0.13);
	gStyle->SetPadRightMargin(0.05);
	gStyle->SetTitleYOffset(1.7);
	gStyle->SetPalette(1);
	TChain ch("tree");
	ch.Add(fileName0);
	if(fileName1 != "") {
		ch.Add(fileName1);
	}
	if(fileName2 != "") {
		ch.Add(fileName2);
	}
	if(fileName3 != "") {
		ch.Add(fileName3);
	}
	if(fileName4 != "") {
		ch.Add(fileName4);
	}
	if(fileName4 != "") {
		ch.Add(fileName4);
	}
	if(fileName5 != "") {
		ch.Add(fileName5);
	}
	if(fileName6 != "") {
		ch.Add(fileName6);
	}
	if(fileName7 != "") {
		ch.Add(fileName7);
	}
	if(fileName8 != "") {
		ch.Add(fileName8);
	}
	if(fileName9 != "") {
		ch.Add(fileName9);
	}
	
	TCut c_base = cut_base.Data(); 
	TCut c_noSat = "Sat[0] == 0 && Sat[1] == 0";
	TCut c_energyWindow511 = "E[0] > 420 && E[0] < 600 && E[1] > 420 && E[1] < 600";
	TCut c_energyWindow202 = "E[0] > 150 && E[0] < 250 && E[1] > 150 && E[1] < 250";
	TCut c_energyWindow307 = "E[0] > 250 && E[0] < 350 && E[1] > 250 && E[1] < 350";
	
	TCanvas* c1 = new TCanvas("c1", "c1", 1800, 1000);
	c1->Divide(5,3);
	c1->cd(1);
	TGraph* gRateBoard1 = GetGraph(&ch, "RateBoard1 : Evt", c_base, kRed);
	TGraph* gRateBoard2 = GetGraph(&ch, "RateBoard2 : Evt", c_base, kGreen+3);
	TGraph* gRateBoard3 = GetGraph(&ch, "RateBoard3 : Evt", c_base, kBlue);
	TGraph* gRateBoard4 = GetGraph(&ch, "RateBoard4 : Evt", c_base, kMagenta);
	TGraph* gRateBoard5 = GetGraph(&ch, "RateBoard5 : Evt", c_base, kYellow);
	TGraph* gRateBoard6 = GetGraph(&ch, "RateBoard6 : Evt", c_base, kOrange);
	TGraph* gRateBoardsRight = GetGraph(&ch, "RateBoard1+RateBoard2+RateBoard3+RateBoard4+RateBoard5+RateBoard6 : Evt", c_base, kBlack);
	TMultiGraph* multi1 = new TMultiGraph();
	multi1->Add(gRateBoard1);
	multi1->Add(gRateBoard2);
	multi1->Add(gRateBoard3);
	multi1->Add(gRateBoard4);
	multi1->Add(gRateBoard5);
	multi1->Add(gRateBoard6);
	multi1->Add(gRateBoardsRight);
	multi1->Draw("apl");
	gPad->SaveAs("c1.png");
	c1->cd(2);
	TGraph* gRateBoard7 = GetGraph(&ch, "RateBoard7 : Evt", c_base, kRed);
	TGraph* gRateBoard8 = GetGraph(&ch, "RateBoard8 : Evt", c_base, kGreen+3);
	TGraph* gRateBoard9 = GetGraph(&ch, "RateBoard9 : Evt", c_base, kBlue);
	TGraph* gRateBoard10 = GetGraph(&ch, "RateBoard10 : Evt", c_base, kMagenta);
	TGraph* gRateBoard11 = GetGraph(&ch, "RateBoard11 : Evt", c_base, kYellow);
	TGraph* gRateBoard12 = GetGraph(&ch, "RateBoard12 : Evt", c_base, kOrange);
	TGraph* gRateBoardsLeft = GetGraph(&ch, "RateBoard7+RateBoard8+RateBoard9+RateBoard10+RateBoard11+RateBoard12 : Evt", c_base, kBlack);
	TMultiGraph* multi2 = new TMultiGraph();
	multi2->Add(gRateBoard7);
	multi2->Add(gRateBoard8);
	multi2->Add(gRateBoard9);
	multi2->Add(gRateBoard10);
	multi2->Add(gRateBoard11);
	multi2->Add(gRateBoard12);
	multi2->Add(gRateBoardsLeft);
	multi2->Draw("apl");
	c1->cd(3);
	TGraph* gRateLvsR1 = GetGraph(&ch, "RateLvsR1 : Evt", c_base, kRed);
	TGraph* gRateLvsR2 = GetGraph(&ch, "RateLvsR2 : Evt", c_base, kGreen+3);
	TGraph* gRateLvsR3 = GetGraph(&ch, "RateLvsR3 : Evt", c_base, kBlue);
	TGraph* gRateLvsR4 = GetGraph(&ch, "RateLvsR4 : Evt", c_base, kMagenta);
	TGraph* gRateLvsR5 = GetGraph(&ch, "RateLvsR5 : Evt", c_base, kYellow);
	TGraph* gRateLvsR6 = GetGraph(&ch, "RateLvsR6 : Evt", c_base, kOrange);
	TGraph* gRateLvsR7 = GetGraph(&ch, "RateLvsR7 : Evt", c_base, kOrange);
	TMultiGraph* multi3 = new TMultiGraph();
	multi3->Add(gRateLvsR1);
	multi3->Add(gRateLvsR2);
	multi3->Add(gRateLvsR3);
	multi3->Add(gRateLvsR4);
	multi3->Add(gRateLvsR5);
	multi3->Add(gRateLvsR6);
	multi3->Add(gRateLvsR7);
	multi3->Draw("apl");
	c1->cd(4);
	TGraph* gRateLvs3L1 = GetGraph(&ch, "RateLvs3L1 : Evt", c_base, kRed);
	TGraph* gRateLvs3L2 = GetGraph(&ch, "RateLvs3L2 : Evt", c_base, kGreen+3);
	TGraph* gRateLvs3L3 = GetGraph(&ch, "RateLvs3L3 : Evt", c_base, kBlue);
	TGraph* gRateLvs3L4 = GetGraph(&ch, "RateLvs3L4 : Evt", c_base, kMagenta);
	TGraph* gRateLvs3L5 = GetGraph(&ch, "RateLvs3L5 : Evt", c_base, kYellow);
	TGraph* gRateLvs3L6 = GetGraph(&ch, "RateLvs3L6 : Evt", c_base, kOrange);
	TGraph* gRateLvs3L7 = GetGraph(&ch, "RateLvs3L7 : Evt", c_base, kOrange);
	TMultiGraph* multi4 = new TMultiGraph();
	multi4->Add(gRateLvs3L1);
	multi4->Add(gRateLvs3L2);
	multi4->Add(gRateLvs3L3);
	multi4->Add(gRateLvs3L4);
	multi4->Add(gRateLvs3L5);
	multi4->Add(gRateLvs3L6);
	multi4->Add(gRateLvs3L7);
	multi4->Draw("apl");
	c1->cd(5);
	TGraph* gRateLvsL1 = GetGraph(&ch, "RateLvsL1 : Evt", c_base, kRed);
	TGraph* gRateLvsL2 = GetGraph(&ch, "RateLvsL2 : Evt", c_base, kGreen+3);
	TGraph* gRateLvsL3 = GetGraph(&ch, "RateLvsL3 : Evt", c_base, kBlue);
	TGraph* gRateLvsL4 = GetGraph(&ch, "RateLvsL4 : Evt", c_base, kMagenta);
	TGraph* gRateLvsL5 = GetGraph(&ch, "RateLvsL5 : Evt", c_base, kYellow);
	TGraph* gRateLvsL6 = GetGraph(&ch, "RateLvsL6 : Evt", c_base, kOrange);
	TGraph* gRateLvsL7 = GetGraph(&ch, "RateLvsL7 : Evt", c_base, kOrange);
	TMultiGraph* multi5 = new TMultiGraph();
	multi5->Add(gRateLvsL1);
	multi5->Add(gRateLvsL2);
	multi5->Add(gRateLvsL3);
	multi5->Add(gRateLvsL4);
	multi5->Add(gRateLvsL5);
	multi5->Add(gRateLvsL6);
	multi5->Add(gRateLvsL7);
	multi5->Draw("apl");
	c1->cd(6);
	ch.Draw("IChanAbs240", c_base);
	c1->cd(7);
	ch.Draw("IQuartetAbs60", c_base);
	c1->cd(8);
	ch.Draw("ILineAbs12", c_base);
	c1->cd(9);
	ch.Draw("IQuartetAbs60[1] : IQuartetAbs60[0]>>hQuartet1vsQuartet0(30,0,30,30,30,60)", c_base && c_noSat, "colz");
	TH1F* hQuartet1vsQuartet0 = (TH1F*) gDirectory->Get("hQuartet1vsQuartet0");
	hQuartet1vsQuartet0->GetXaxis()->SetTitle("IQuartetAbs60[0]");
	hQuartet1vsQuartet0->GetYaxis()->SetTitle("IQuartetAbs60[1]");
	c1->cd(10);
	ch.Draw("ILineAbs12[1] : ILineAbs12[0]>>hLine1vsLine0(6,0,6,6,6,12)", c_base && c_noSat, "colz");
	TH1F* hLine1vsLine0 = (TH1F*) gDirectory->Get("hLine1vsLine0");
	hLine1vsLine0->GetXaxis()->SetTitle("ILineAbs12[0]");
	hLine1vsLine0->GetYaxis()->SetTitle("ILineAbs12[1]");
	c1->cd(11);
	ch.Draw("E[1] : E[0]>>hE1vsE0(200,0,1022,200,0,1022)", c_base, "colz");
	TH1F* hE1vsE0 = (TH1F*) gDirectory->Get("hE1vsE0");
	hE1vsE0->GetXaxis()->SetTitle("E[0]");
	hE1vsE0->GetYaxis()->SetTitle("E[1]");
	c1->cd(12);
	ch.Draw("E[0]>>hE0(200,0,1100)", c_base);
	ch.Draw("E[0]>>hE0noSat(200,0,1100)", c_base && "Sat[0] == 0", "same");
	TH1F* hE0noSat = (TH1F*) gDirectory->Get("hE0noSat");
	hE0noSat->SetLineStyle(7);
	ch.Draw("E[1]>>hE1(200,0,1100)", c_base, "same");
	ch.Draw("E[1]>>hE1noSat(200,0,1100)", c_base && "Sat[1] == 0", "same");
	TH1F* hE1 = (TH1F*) gDirectory->Get("hE1");
	TH1F* hE1noSat = (TH1F*) gDirectory->Get("hE1noSat");
	hE1noSat->SetLineStyle(7);
	hE1->SetLineColor(kRed); // left
	hE1noSat->SetLineColor(kRed); //left
	c1->cd(13);
	gPad->SetLogy();
	TH1F* hE0 = (TH1F*) gDirectory->Get("hE0");
	hE0->Draw();
	hE0noSat->Draw("same");
	hE1->Draw("same");
	hE1noSat->Draw("same");
	c1->cd(14);
	ch.Draw("T30[0] - T30[1]>>hCRT(200,-30,30)", c_base);
	TH1F* hCRT = (TH1F*) gDirectory->Get("hCRT");
	hCRT->Fit("gaus");
	hCRT->SetStats(1);
	c1->cd(15);  
	ch.Draw("T30[0] - T30[1]>>hCRTcuts(200,-30,30)", c_base && c_noSat && c_energyWindow511);
	TH1F* hCRTcuts = (TH1F*) gDirectory->Get("hCRTcuts");
	hCRTcuts->Fit("gaus");
	hCRTcuts->SetStats(1);
}