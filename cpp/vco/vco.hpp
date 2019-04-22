#ifndef FAUSTAPI_PATCHS_VCO_H_
#define FAUSTAPI_PATCHS_VCO_H_

#include "../patch.hpp"

namespace faust
{

class Vco : public Patch
{
public:

    ~Vco() {}

    static Patch* Create();

    virtual std::string GetCode();

    virtual int GetNumInputs();

    virtual int GetNumOutputs();

    virtual int GetInputRate(int channel);

    virtual int GetOutputRate(int channel);

    virtual void ClassInit(int samplingFreq);

    virtual void InstanceConstants(int samplingFreq);

    virtual void InstanceResetUserInterface();

    virtual void InstanceClear();

    virtual std::pair<std::string, float*>* GetParameterList(int* num_parameters);

    virtual void Compute(int count);

private:

	FAUSTFLOAT fHslider0;
	int iVec0[4];
	float fRec0[2];
	FAUSTFLOAT fCheckbox0;
	float fRec1[2];
	FAUSTFLOAT fVslider0;
	int fSamplingFreq;
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
};
}

#endif // FAUSTAPI_PATCHS_VCO_H_
