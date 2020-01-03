/* ------------------------------------------------------------
name: "vco"
Code generated with Faust 2.20.2 (https://faust.grame.fr)
Compilation options: -lang cpp -scal -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

/************************************************************************
 IMPORTANT NOTE : this file contains two clearly delimited sections :
 the ARCHITECTURE section (in two parts) and the USER section. Each section
 is governed by its own copyright and license. Please check individually
 each section for license and copyright information.
 *************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2019 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 
 ************************************************************************
 ************************************************************************/

#include <libgen.h>
#include <stdlib.h>
#include <iostream>
#include <list>

#include "faust/dsp/timed-dsp.h"
#include "faust/gui/PathBuilder.h"
#include "faust/gui/FUI.h"
#include "faust/gui/JSONUI.h"
#include "faust/misc.h"
#include "faust/gui/GTKUI.h"
#include "faust/audio/alsa-dsp.h"

#ifdef OSCCTRL
#include "faust/gui/OSCUI.h"
#endif

#ifdef HTTPCTRL
#include "faust/gui/httpdUI.h"
#endif

// Always include this file, otherwise -nvoices only mode does not compile....
#include "faust/gui/MidiUI.h"

#ifdef MIDICTRL
#include "faust/midi/rt-midi.h"
#include "faust/midi/RtMidi.cpp"
#endif

/******************************************************************************
 *******************************************************************************
 
 VECTOR INTRINSICS
 
 *******************************************************************************
 *******************************************************************************/


/********************END ARCHITECTURE SECTION (part 1/2)****************/

/**************************BEGIN USER SECTION **************************/

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <math.h>

class mydspSIG0 {
	
  private:
	
	int iRec2[2];
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
	}
	int getNumOutputsmydspSIG0() {
		return 1;
	}
	int getInputRatemydspSIG0(int channel) {
		int rate;
		switch ((channel)) {
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	int getOutputRatemydspSIG0(int channel) {
		int rate;
		switch ((channel)) {
			case 0: {
				rate = 0;
				break;
			}
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	
	void instanceInitmydspSIG0(int sample_rate) {
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			iRec2[l3] = 0;
		}
	}
	
	void fillmydspSIG0(int count, float* table) {
		for (int i = 0; (i < count); i = (i + 1)) {
			iRec2[0] = (iRec2[1] + 1);
			table[i] = std::sin((9.58738019e-05f * float((iRec2[0] + -1))));
			iRec2[1] = iRec2[0];
		}
	}

};

static mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
static void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

static float ftbl0mydspSIG0[65536];
static float mydsp_faustpower3_f(float value) {
	return ((value * value) * value);
}
static float mydsp_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class mydsp : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int iVec0[4];
	float fRec0[2];
	FAUSTFLOAT fButton0;
	float fRec1[2];
	FAUSTFLOAT fVslider0;
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider1;
	float fRec4[2];
	FAUSTFLOAT fHslider2;
	float fRec5[2];
	FAUSTFLOAT fHslider3;
	float fRec6[2];
	float fRec3[2];
	float fRec7[2];
	float fConst2;
	float fVec1[2];
	float fRec9[2];
	float fVec2[2];
	float fVec3[2];
	float fVec4[2];
	float fConst3;
	float fConst4;
	float fVec5[2];
	float fRec11[2];
	float fVec6[2];
	int IOTA;
	float fVec7[4096];
	float fConst5;
	float fRec10[2];
	float fVec8[2];
	float fVec9[2];
	float fVec10[2];
	float fVec11[4096];
	float fRec12[2];
	FAUSTFLOAT fHslider4;
	float fRec13[2];
	FAUSTFLOAT fHslider5;
	float fRec14[2];
	float fConst6;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.1");
		m->declare("filename", "vco.dsp");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("name", "vco");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.0");
	}

	virtual int getNumInputs() {
		return 0;
	}
	virtual int getNumOutputs() {
		return 1;
	}
	virtual int getInputRate(int channel) {
		int rate;
		switch ((channel)) {
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	virtual int getOutputRate(int channel) {
		int rate;
		switch ((channel)) {
			case 0: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	
	static void classInit(int sample_rate) {
		mydspSIG0* sig0 = newmydspSIG0();
		sig0->instanceInitmydspSIG0(sample_rate);
		sig0->fillmydspSIG0(65536, ftbl0mydspSIG0);
		deletemydspSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = (1.0f / fConst0);
		fConst2 = (0.00520833349f * mydsp_faustpower3_f(fConst0));
		fConst3 = (4.0f / fConst0);
		fConst4 = (0.25f * fConst0);
		fConst5 = (0.5f * fConst0);
		fConst6 = (0.00520833349f * mydsp_faustpower2_f(fConst0));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fButton0 = FAUSTFLOAT(0.0f);
		fVslider0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(440.0f);
		fHslider2 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.0f);
		fHslider4 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(50.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 4); l0 = (l0 + 1)) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec0[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec1[l2] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec4[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec5[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec6[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec3[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec7[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fVec1[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec9[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fVec2[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fVec3[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fVec4[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fVec5[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec11[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fVec6[l16] = 0.0f;
		}
		IOTA = 0;
		for (int l17 = 0; (l17 < 4096); l17 = (l17 + 1)) {
			fVec7[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec10[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fVec8[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fVec9[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fVec10[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 4096); l22 = (l22 + 1)) {
			fVec11[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec12[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec13[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec14[l25] = 0.0f;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("output");
		ui_interface->declare(&fVslider0, "0", "");
		ui_interface->declare(&fVslider0, "style", "menu{'Sine':0; 'Sawtooth':1; 'Sawtooth inv':2; 'Triangle':3; 'Square':4}");
		ui_interface->addVerticalSlider("signal", &fVslider0, 0.0f, 0.0f, 4.0f, 1.0f);
		ui_interface->addHorizontalSlider("att_pw", &fHslider4, 0.0f, 0.0f, 100.0f, 1.0f);
		ui_interface->addHorizontalSlider("freq", &fHslider1, 440.0f, 50.0f, 4000.0f, 0.00999999978f);
		ui_interface->addHorizontalSlider("gain", &fHslider0, 0.5f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->addButton("gate", &fButton0);
		ui_interface->addHorizontalSlider("mod_freq1", &fHslider2, 0.0f, 0.0f, 100.0f, 1.0f);
		ui_interface->addHorizontalSlider("mod_freq2", &fHslider3, 0.0f, 0.0f, 100.0f, 1.0f);
		ui_interface->addHorizontalSlider("pw", &fHslider5, 50.0f, 0.0f, 100.0f, 1.0f);
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (0.00100000005f * float(fHslider0));
		float fSlow1 = (0.00100000005f * float(fButton0));
		float fSlow2 = float(fVslider0);
		int iSlow3 = (fSlow2 >= 3.0f);
		int iSlow4 = (fSlow2 >= 2.0f);
		int iSlow5 = (fSlow2 >= 1.0f);
		float fSlow6 = (0.00100000005f * float(fHslider1));
		float fSlow7 = (0.00100000005f * float(fHslider2));
		float fSlow8 = (0.00100000005f * float(fHslider3));
		int iSlow9 = (fSlow2 >= 4.0f);
		float fSlow10 = (0.00100000005f * float(fHslider4));
		float fSlow11 = (0.00100000005f * float(fHslider5));
		for (int i = 0; (i < count); i = (i + 1)) {
			iVec0[0] = 1;
			fRec0[0] = (fSlow0 + (0.999000013f * fRec0[1]));
			fRec1[0] = (fSlow1 + (0.999000013f * fRec1[1]));
			fRec4[0] = (fSlow6 + (0.999000013f * fRec4[1]));
			fRec5[0] = (fSlow7 + (0.999000013f * fRec5[1]));
			fRec6[0] = (fSlow8 + (0.999000013f * fRec6[1]));
			float fTemp0 = (fRec4[0] + (6.00000021e-06f * (fRec5[0] + fRec6[0])));
			float fTemp1 = (fRec3[1] + (fConst1 * fTemp0));
			fRec3[0] = (fTemp1 - std::floor(fTemp1));
			float fTemp2 = float((500.0f > fRec4[0]));
			float fTemp3 = std::fabs(fTemp0);
			float fTemp4 = std::max<float>(1.00000001e-07f, fTemp3);
			float fTemp5 = (fRec7[1] + (fConst1 * fTemp4));
			float fTemp6 = (fTemp5 + -1.0f);
			int iTemp7 = (fTemp6 < 0.0f);
			fRec7[0] = (iTemp7 ? fTemp5 : fTemp6);
			float fRec8 = (iTemp7 ? fTemp5 : (fTemp5 + (fTemp6 * (1.0f - (fConst0 / fTemp4)))));
			float fTemp8 = float((500.0f < fRec4[0]));
			float fTemp9 = float(iVec0[3]);
			float fTemp10 = std::max<float>(20.0f, fTemp3);
			fVec1[0] = fTemp10;
			float fTemp11 = (fRec9[1] + (fConst1 * fVec1[1]));
			fRec9[0] = (fTemp11 - std::floor(fTemp11));
			float fTemp12 = mydsp_faustpower2_f(((2.0f * fRec9[0]) + -1.0f));
			float fTemp13 = (fTemp12 * (fTemp12 + -2.0f));
			fVec2[0] = fTemp13;
			float fTemp14 = ((fTemp13 - fVec2[1]) / fTemp10);
			fVec3[0] = fTemp14;
			float fTemp15 = ((fTemp14 - fVec3[1]) / fTemp10);
			fVec4[0] = fTemp15;
			float fTemp16 = ((fTemp2 * ((2.0f * fRec8) + -1.0f)) + (fConst2 * (((fTemp8 * fTemp9) * (fTemp15 - fVec4[1])) / fTemp10)));
			float fTemp17 = std::max<float>(fTemp0, 23.4489498f);
			float fTemp18 = std::max<float>(20.0f, std::fabs(fTemp17));
			fVec5[0] = fTemp18;
			float fTemp19 = (fRec11[1] + (fConst1 * fVec5[1]));
			fRec11[0] = (fTemp19 - std::floor(fTemp19));
			float fTemp20 = mydsp_faustpower2_f(((2.0f * fRec11[0]) + -1.0f));
			fVec6[0] = fTemp20;
			float fTemp21 = ((float(iVec0[1]) * (fTemp20 - fVec6[1])) / fTemp18);
			fVec7[(IOTA & 4095)] = fTemp21;
			float fTemp22 = std::max<float>(0.0f, std::min<float>(2047.0f, (fConst5 / fTemp17)));
			int iTemp23 = int(fTemp22);
			float fTemp24 = std::floor(fTemp22);
			float fTemp25 = (fTemp24 + (1.0f - fTemp22));
			float fTemp26 = (fTemp22 - fTemp24);
			int iTemp27 = (iTemp23 + 1);
			fRec10[0] = ((0.999000013f * fRec10[1]) + (fConst4 * ((fTemp21 - (fVec7[((IOTA - iTemp23) & 4095)] * fTemp25)) - (fTemp26 * fVec7[((IOTA - iTemp27) & 4095)]))));
			float fTemp28 = (fTemp20 * (fTemp20 + -2.0f));
			fVec8[0] = fTemp28;
			float fTemp29 = ((fTemp28 - fVec8[1]) / fTemp18);
			fVec9[0] = fTemp29;
			float fTemp30 = ((fTemp29 - fVec9[1]) / fTemp18);
			fVec10[0] = fTemp30;
			float fTemp31 = ((fTemp9 * (fTemp30 - fVec10[1])) / fTemp18);
			fVec11[(IOTA & 4095)] = fTemp31;
			fRec12[0] = ((0.999000013f * fRec12[1]) + (fConst2 * ((fTemp31 - (fTemp25 * fVec11[((IOTA - iTemp23) & 4095)])) - (fTemp26 * fVec11[((IOTA - iTemp27) & 4095)]))));
			fRec13[0] = (fSlow10 + (0.999000013f * fRec13[1]));
			fRec14[0] = (fSlow11 + (0.999000013f * fRec14[1]));
			float fTemp32 = std::max<float>(0.0f, std::min<float>(2047.0f, (fConst0 * (((5.00000006e-08f * fRec13[0]) + (0.00999999978f * fRec14[0])) / fTemp17))));
			int iTemp33 = int(fTemp32);
			float fTemp34 = std::floor(fTemp32);
			float fTemp35 = (fTemp34 + (1.0f - fTemp32));
			float fTemp36 = (fTemp32 - fTemp34);
			int iTemp37 = (iTemp33 + 1);
			output0[i] = FAUSTFLOAT(((fRec0[0] * fRec1[0]) * (iSlow3 ? (iSlow9 ? (fConst0 * ((0.25f * (fTemp2 * ((fTemp21 - (fVec7[((IOTA - iTemp33) & 4095)] * fTemp35)) - (fTemp36 * fVec7[((IOTA - iTemp37) & 4095)])))) + (fConst6 * (fTemp8 * ((fTemp31 - (fTemp35 * fVec11[((IOTA - iTemp33) & 4095)])) - (fTemp36 * fVec11[((IOTA - iTemp37) & 4095)])))))) : (fConst3 * (fTemp0 * ((fRec10[0] * fTemp2) + (fRec12[0] * fTemp8))))) : (iSlow4 ? (-1.0f * fTemp16) : (iSlow5 ? fTemp16 : ftbl0mydspSIG0[int((65536.0f * fRec3[0]))])))));
			for (int j0 = 3; (j0 > 0); j0 = (j0 - 1)) {
				iVec0[j0] = iVec0[(j0 - 1)];
			}
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec3[1] = fRec3[0];
			fRec7[1] = fRec7[0];
			fVec1[1] = fVec1[0];
			fRec9[1] = fRec9[0];
			fVec2[1] = fVec2[0];
			fVec3[1] = fVec3[0];
			fVec4[1] = fVec4[0];
			fVec5[1] = fVec5[0];
			fRec11[1] = fRec11[0];
			fVec6[1] = fVec6[0];
			IOTA = (IOTA + 1);
			fRec10[1] = fRec10[0];
			fVec8[1] = fVec8[0];
			fVec9[1] = fVec9[0];
			fVec10[1] = fVec10[0];
			fRec12[1] = fRec12[0];
			fRec13[1] = fRec13[0];
			fRec14[1] = fRec14[0];
		}
	}

};

/***************************END USER SECTION ***************************/

/*******************BEGIN ARCHITECTURE SECTION (part 2/2)***************/

#include "faust/dsp/poly-dsp.h"

dsp* DSP;

std::list<GUI*> GUI::fGuiList;
ztimedmap GUI::gTimedZoneMap;

static bool hasMIDISync()
{
    JSONUI jsonui;
    mydsp* tmp_dsp = new mydsp();
    tmp_dsp->buildUserInterface(&jsonui);
    std::string json = jsonui.JSON();
    delete tmp_dsp;
    
    return ((json.find("midi") != std::string::npos) &&
            ((json.find("start") != std::string::npos) ||
            (json.find("stop") != std::string::npos) ||
            (json.find("clock") != std::string::npos)));
}

//-------------------------------------------------------------------------
//                                     MAIN
//-------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    char name[256];
    char rcfilename[256];
    char* home = getenv("HOME");
    mydsp_poly* dsp_poly = NULL;

    snprintf(name, 256, "%s", basename(argv[0]));
    snprintf(rcfilename, 256, "%s/.%src", home, name);

#ifdef POLY
    int poly = lopt(argv, "--poly", 4);
    int group = lopt(argv, "--group", 1);
    dsp_poly = new mydsp_poly(new mydsp(), poly, true, group);

#if MIDICTRL
    if (hasMIDISync()) {
        DSP = new timed_dsp(dsp_poly);
    } else {
        DSP = dsp_poly;
    }
#else
    DSP = dsp_poly;
#endif

#else

#if MIDICTRL
    if (hasMIDISync()) {
        DSP = new timed_dsp(new mydsp());
    } else {
        DSP = new mydsp();
    }
#else
    DSP = new mydsp();
#endif

#endif
     
    if (DSP == 0) {
        std::cerr << "Unable to allocate Faust DSP object" << std::endl;
        exit(1);
    }

    GUI* interface = new GTKUI(name, &argc, &argv);
    FUI* finterface = new FUI();
    DSP->buildUserInterface(interface);
    DSP->buildUserInterface(finterface);

#ifdef MIDICTRL
    rt_midi midi_handler(name);
    midi_handler.addMidiIn(dsp_poly);
    MidiUI midiinterface(&midi_handler);
    DSP->buildUserInterface(&midiinterface);
    std::cout << "MIDI is on" << std::endl;
#endif

#ifdef HTTPCTRL
    httpdUI* httpdinterface = new httpdUI(name, DSP->getNumInputs(), DSP->getNumOutputs(), argc, argv);
    DSP->buildUserInterface(httpdinterface);
    std::cout << "HTTPD is on" << std::endl;
#endif

#ifdef OSCCTRL
    GUI* oscinterface = new OSCUI(name, argc, argv);
    DSP->buildUserInterface(oscinterface);
#endif

    alsaaudio audio(argc, argv, DSP);
    audio.init(name, DSP);
    finterface->recallState(rcfilename);	
    audio.start();

#ifdef HTTPCTRL
    httpdinterface->run();
#endif

#ifdef OSCCTRL
    oscinterface->run();
#endif
#ifdef MIDICTRL
    if (!midiinterface.run()) {
        std::cerr << "MidiUI run error\n";
    }
#endif
    interface->run();

#ifdef MIDICTRL
    midiinterface.stop();
#endif

    audio.stop();
    finterface->saveState(rcfilename);

    // desallocation
    delete interface;
    delete finterface;
#ifdef HTTPCTRL
    delete httpdinterface;
#endif
#ifdef OSCCTRL
    delete oscinterface;
#endif

    return 0;
}

/********************END ARCHITECTURE SECTION (part 2/2)****************/


#endif
