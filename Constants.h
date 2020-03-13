#include <TMath.h>

const Char_t *path="/mnt/pool/rhic/1/demanov/cherenkov";

const int nBinCent = 9;
const int nBinVtxZ_Hadrons = 2;
const int nBinVtxZ_PID = 10;

// eta-gap значения
const int nEtaGap=1;
const int nEtaGapHadrons=1;

const Char_t *particles[] = {"Pion","Kaon","Proton"};
const Char_t *particlesSign[] = {"Pos","Neg"};
const Char_t *partLateX[] = {"#pi^{+}","pi^{-}","K^{+}","K^{-}","p","#bar{p}"};

//Double_t pt_min[3] = {0.2,0.2,0.5};
//Double_t pt_max[3] = {1.5,1.5,2.0};

const std::vector<const Char_t *> NameEtaHadrons = {"Eta15","Eta04","Eta07","Eta10"};
const std::vector<Double_t> EtaVecHadrons = {0.075, 0.2, 0.35, 0.5};

const std::vector<const Char_t *> NameEtaPID = {"Eta01","Eta04","Eta07","Eta10"};
const std::vector<Double_t> EtaVecPID = {0.05, 0.2, 0.35, 0.5};

//RunId range from energy = 7.7 | 11.5 | 14.5 | 19.6 | 27.0 | 39.0 | 62.4 |  GeV
const std::map<const Int_t, Int_t> RunIdMin = {{7, 11110000}, {11, 11145000}, {14, 15045000}, {19, 12110000}, {27, 12171000}, {39, 11095000}, {62, 11077023}};
const std::map<const Int_t, Int_t> RunIdMax = {{7, 11150000}, {11, 11165000}, {14, 15075000}, {19, 12123000}, {27, 12180000}, {39, 11115000}, {62, 11098060}};

//Event cut
const std::map<const Int_t, Double_t> CutVtxZ = {{7, 70.}, {11, 50.}, {14, 70.}, {19, 70.}, {27, 70.}, {39, 40.}, {62, 40.}};
const std::map<const Int_t, Double_t> CutVtxR = {{7, 2.}, {11, 2.}, {14, 1.}, {19, 2.}, {27, 2.}, {39, 2.}, {62, 2.}};
const std::map<const Int_t, Double_t> CutDeltaVtxY = {{7, 0.}, {11, 0.}, {14, 0.8847}, {19, 0.}, {27, 0.}, {39, 0.}, {62, 0.}};

//Track cut
const std::map<const Int_t, Double_t> CutDCAHadronsEP = {{7, 2.}, {11, 2.}, {14, 2.}, {19, 2.}, {27, 2.}, {39, 2.}, {62, 2.}};
const std::map<const Int_t, Double_t> CutDCAHadronsFlow = {{7, 2.}, {11, 2.}, {14, 3.}, {19, 2.}, {27, 2.}, {39, 2.}, {62, 2.}};

//Track cut
const std::map<const Int_t, Double_t> CutDCApidEP = {{7, 1.}, {11, 1.}, {14, 2.}, {19, 1.}, {27, 1.}, {39, 1.}, {62, 1.}};
const std::map<const Int_t, Double_t> CutDCApidFlow = {{7, 1.}, {11, 1.}, {14, 3.}, {19, 1.}, {27, 1.}, {39, 1.}, {62, 1.}};

const int CutnHits = 15;
const double CutnHitsRatio = 0.52;

const double CutPtotMin = 0.15;
const double CutPtotMax = 10.0;

const double CutPtEPMin_Hadrons = 0.2;
const double CutPtEPMax_Hadrons = 2.0;
const double CutPtFlowMax_Hadrons = 10.0;

const double CutPtotEPMin_PID = 0.15;
const double CutPtotEPMax_PID = 5.0;
const double CutPtotFlowMin_PID = 0.1;
const double CutPtotFlowMax_PID = 10.0;

const Char_t *resol[] = {"ew","e","w"};
const Char_t *direction[] = {"East","West"};

//Масса и квадрат массы частиц
const Float_t electron_mass = 0.0005485799;
const Float_t pion_mass = 0.13957061;
const Float_t kaon_mass = 0.493677;
const Float_t proton_mass = 0.9382720813;

const Float_t electron_mass_sqr = 0.000000301;
const Float_t pion_mass_sqr = 0.019479955;
const Float_t kaon_mass_sqr = 0.24371698;
const Float_t proton_mass_sqr = 0.880354499;

const std::map<const Int_t, std::vector<Int_t> > BadRuns = {
	{7,  {11110000, 11110001}}, 
	{11, {11148001, 11148008, 11148009, 11148010, 11148036, 
		  11148055, 11149017, 11149018, 11149040, 11149043, 
		  11150017, 11150029, 11151051, 11151057, 11153045, 
		  11154026, 11154040, 11154059, 11156036, 11156043, 
		  11156044, 11156045, 11157039}}, 
	{14, {15053027, 15053028, 15053029, 15053034, 15053035, 
		  15053048, 15053052, 15053053, 15053054, 15053055, 
		  15053056, 15053057, 15054019, 15054053, 15054054, 
		  15055018, 15055131, 15055133, 15055134, 15055135, 
		  15055136, 15055137, 15055138, 15055139, 15055140, 
		  15055141, 15056001, 15056002, 15056003, 15056004, 
		  15056005, 15056006, 15056007, 15056008, 15056009, 
		  15056113, 15056114, 15056116, 15056117, 15056124, 
		  15056125, 15057001, 15057003, 15057004, 15057006, 
		  15057007, 15057010, 15057011, 15057013, 15057014, 
		  15057018, 15057055, 15057059, 15058006, 15058011, 
		  15058018, 15060061, 15060069, 15061001, 15061002, 
		  15062006, 15065012, 15065014, 15066008, 15066013, 
		  15066017, 15068013, 15068014, 15068016, 15069034, 
		  15069036, 15070009, 15070010}}, 
	{19, {12113081, 12113084, 12114077, 12114079, 12114085, 
	 	  12114088, 12114089, 12114091, 12114094, 12114095, 
	 	  12114097, 12114098, 12114099, 12114100, 12114101, 
	 	  12114102, 12114103, 12114104, 12114110, 12115025, 
	 	  12115026, 12116015, 12116016, 12116063, 12116084, 
	 	  12117009, 12118045, 12119008, 12119009, 12119011, 
	 	  12119015, 12119016, 12119017, 12119019, 12119020, 
	 	  12119021, 12119022, 12119023, 12119024, 12119025, 
	 	  12119027, 12119028, 12119029, 12119030, 12119032, 
	 	  12119035, 12119036, 12119039, 12120018, 12120073}}, 
	{27, {12172049, 12172056, 12173009, 12173018, 12173026, 
		  12173053, 12173054, 12173055, 12173056, 12173057, 
		  12173072, 12174077, 12174096, 12174109, 12175007, 
		  12175030, 12175089, 12176046, 12176047, 12176067, 
		  12176069, 12176104, 12178051, 12178093, 12179068, 
		  12179083, 12179084, 12179085, 12179086}}, 
	{39, {11099102, 11099103, 11099104, 11099106, 11099107, 
	      11099125, 11100004, 11100005, 11100008, 11100010, 
	      11100011, 11100016, 11100020, 11100071, 11101014, 
	      11101104, 11102098, 11103009, 11103047, 11103065, 
	      11105011, 11105029, 11106026, 11106027, 11106028, 
	      11106029, 11106030, 11106040, 11106041, 11107008, 
	      11107046, 11107083, 11108040, 11108053, 11108065, 
	      11108075, 11109092, 11109102, 11109105, 11109104, 
	      11110005, 11110041, 11110042, 11110086}}, 
	{62, {11080057,11080060,11080061,11080062,11080069,
          11081002,11081026,11081034,11081037,11081052,
          11082017,11084010,11085013,11085050,11085051,
          11085053,11085054,11086001,11086002,11086006,
          11086019,11087057,11087058,11087059,11088003,
          11089048,11089070,11091045,11091067,11091068,
          11091068,11092013,11092014,11092015,11092016,
          11092024,11092025,11092031,11092055,11092065,
          11092066,11092068,11092069,11092070,11092071,
          11092073,11092075,11092077,11092086,11092087,
          11092089,11092090,11093024,11093042,11093080,
          11095029,11095029,11095041,11095049,11095065,
          11095066,11095069,11095070,11095077,11095078,
          11095089,11096005,11096006,11096007,11096008,
          11096010,11096011,11096012,11096014,11096015,
          11096016,11096017,11096018,11096023,11096045,
          11096057,11096093,11096110}}
};

const std::map<const Int_t, std::vector< Double_t > > VtxZarray = {
	{7,  {-70.,0.,70.}}, 
	{11, {-50.,0.,50.}}, 
	{14, {-70.,0.,70.}}, 
	{19, {-70.,0.,70.}}, 
	{27, {-70.,0.,70.}}, 
	{39, {-40.,-32.,-24.,-16.,-8.,0.,8.,16.,24.,32.,40.}}, 
	{62, {-40.,0.,40.}}
};

/// PID ////
const Double_t ptUpTPC[3] = {0.6,0.5,1.1};
const Double_t ptDownTPC[3] = {0.2,0.2,0.4};
const Double_t SqMdown[3] = {-0.04, 0.16, 0.49};
const Double_t SqMup[3] = {0.09, 0.36, 1.44};
const std::map<const Int_t, Double_t> nSigmaTofTpc = {{7, 3.}, {11, 3.}, {14, 3.}, {19, 3.}, {27, 1.5}, {39, 3.}, {62, 1.5}};
const std::map<const Int_t, Double_t> nSigmaTpc = {{7, 2.}, {11, 2.}, {14, 2.}, {19, 2.}, {27, 1.}, {39, 2.}, {62, 1.}};