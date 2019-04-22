#include "../patch.hpp"
#include "vco.hpp"

std::string faust::Vco::GetCode()
{
    return "vco";
}

faust::Patch* faust::Vco::Create()
{
    return new Vco;
}

int faust::Vco::GetNumInputs()
{
    return 0;
}

int faust::Vco::GetNumOutputs()
{
    return 1;
}

int faust::Vco::GetInputRate(int channel)
{
    int rate;
    switch (channel)
    {
    default:
    {
        rate = -1;
        break;
    }

    }
    return rate;

}
int faust::Vco::GetOutputRate(int channel)
{
    int rate;
    switch (channel)
    {
        case 0:
        {
            rate = 1;
            break;
        }
        default:
        {
            rate = -1;
            break;
        }
    }
    return rate;

}

void faust::Vco::ClassInit(int samplingFreq)
{
    mydspSIG0* sig0 = newmydspSIG0();
    sig0->instanceInitmydspSIG0(samplingFreq);
    sig0->fillmydspSIG0(65536, ftbl0mydspSIG0);
    deletemydspSIG0(sig0);
}

void faust::Vco::InstanceConstants(int samplingFreq)
{
    fSamplingFreq = samplingFreq;
    fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSamplingFreq)));
    fConst1 = (1.0f / fConst0);
    fConst2 = (0.00520833349f * mydsp_faustpower3_f(fConst0));
    fConst3 = (4.0f / fConst0);
    fConst4 = (0.25f * fConst0);
    fConst5 = (0.5f * fConst0);
    fConst6 = (0.00520833349f * mydsp_faustpower2_f(fConst0));
}

void faust::Vco::InstanceResetUserInterface()
{
    fHslider0 = FAUSTFLOAT(0.5f);
    fCheckbox0 = FAUSTFLOAT(0.0f);
    fVslider0 = FAUSTFLOAT(0.0f);
    fHslider1 = FAUSTFLOAT(440.0f);
    fHslider2 = FAUSTFLOAT(0.0f);
    fHslider3 = FAUSTFLOAT(0.0f);
    fHslider4 = FAUSTFLOAT(0.0f);
    fHslider5 = FAUSTFLOAT(50.0f);
}

void faust::Vco::InstanceClear()
{
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

std::pair<std::string, float*>* faust::Vco::GetParameterList(int* num_parameters)
{
    *num_parameters = 8;
    std::pair<std::string, float*>* parameter_list = new std::pair<std::string, float*>[*num_parameters];
    std::pair<std::string, float*> parameter;
    parameter.first = "freq";
    parameter.second = &fHslider1;
    parameter_list[0] = parameter;
    parameter.first = "gain";
    parameter.second = &fHslider0;
    parameter_list[1] = parameter;
    parameter.first = "gate";
    parameter.second = &fCheckbox0;
    parameter_list[2] = parameter;
    parameter.first = "signal";
    parameter.second = &fVslider0;
    parameter_list[3] = parameter;
    parameter.first = "att_freq0";
    parameter.second = &fHslider2;
    parameter_list[4] = parameter;
    parameter.first = "att_freq1";
    parameter.second = &fHslider3;
    parameter_list[5] = parameter;
    parameter.first = "att_pw";
    parameter.second = &fHslider4;
    parameter_list[6] = parameter;
    parameter.first = "pw";
    parameter.second = &fHslider5;
    parameter_list[7] = parameter;

    return parameter_list;
}

void faust::Vco::Compute(int count)
{
    FAUSTFLOAT* output0 = outputs[0];
    float fSlow0 = (0.00100000005f * float(fHslider0));
    float fSlow1 = (0.00100000005f * float(fCheckbox0));
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
        fRec7[0] = (iTemp7?fTemp5:fTemp6);
        float fRec8 = (iTemp7?fTemp5:(fTemp5 + (fTemp6 * (1.0f - (fConst0 / fTemp4)))));
        float fTemp8 = float(iVec0[3]);
        float fTemp9 = float((500.0f < fRec4[0]));
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
        float fTemp31 = ((fTemp8 * (fTemp30 - fVec10[1])) / fTemp18);
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
        output0[i] = FAUSTFLOAT(((fRec0[0] * fRec1[0]) * (iSlow3?(iSlow9?(fConst0 * ((0.25f * (fTemp2 * ((fTemp21 - (fVec7[((IOTA - iTemp33) & 4095)] * fTemp35)) - (fTemp36 * fVec7[((IOTA - iTemp37) & 4095)])))) + (fConst6 * (fTemp9 * ((fTemp31 - (fTemp35 * fVec11[((IOTA - iTemp33) & 4095)])) - (fTemp36 * fVec11[((IOTA - iTemp37) & 4095)])))))):(fConst3 * (fTemp0 * ((fRec10[0] * fTemp2) + (fRec12[0] * fTemp9))))):(iSlow4?(-1.0f * fTemp16):(iSlow5?fTemp16:ftbl0mydspSIG0[int((65536.0f * fRec3[0]))])))));
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
