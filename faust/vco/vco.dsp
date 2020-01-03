import ("stdfaust.lib");
import ("lfo.dsp");

/*	############
	 VCO module
	############
	
	Input:
		
		1) mod_freq1: frequency (for modulation)
		2) mod_freq2: frecuencia (for modulation)
		3) mod_pw: pulse width (for modulation)
		
	Control:
		
		1) mod_attenuator_freq1: modulation attenuator
		2) mod_attenuator_freq2: modulation attenuator
		3) vco_att_pw: pw modulation attenuator
		4) vco_shape: wave shape (sine, tri, saw, rect)
		5) vco_freq: oscillation frequency
		6) vco_pw: pulse width
		
	Output:
	
		1) audio: en la API debe ser algo como 'vco_out'

*/

// Subtractive generation is applied by Se utilizan generadores sustractivos mediante el método polyblep
// Se aplica un polinomio para frecuencias menores a 500 Hz y otro para frecuencias mayores a 500 Hz

fc = 500;
// A: applies subtractive for frequencies < 500 Hz
// B: applies subtractive for frequencies > 500 Hz
A = fc>vco_freq;
B = fc<vco_freq;

vco_freq = hslider ("freq", 440, 50, 4000, 0.01) : si.smooth (0.999); // Frequency control

// Modulation 1 mode
vco_modulation1 = checkbox("LFO AMP MOD") : si.smooth (0.999);

// Modulation 2 mode
vco_modulation2 = checkbox("LFO FREQ MOD") : si.smooth (0.999);

// #### Inputs ####
vco_in_frec1 = lfo_out * vco_modulation2;
vco_in_frec2 = 0.00001;
vco_in_pw = 0.00001;

// #### Signal flow for input signals ####

// Frequency modulation (from vco_frec, mod_freq1 and mod_freq2)
mod_attenuator_freq1 = hslider ("mod_freq1", 0, 0, 100, 1) : si.smooth (0.999); // control att_freq0
mod_attenuator_freq2 = hslider ("mod_freq2", 0, 0, 100, 1) : si.smooth (0.999); // control att_freq1
vco_modf = ((0.01 * mod_attenuator_freq1 * vco_in_frec1) + (0.01 * mod_attenuator_freq2 * vco_in_frec2)) * 60;

// Modulacion de amplitud
vco_pw = hslider ("pw", 50, 0, 100, 1) : si.smooth (0.999); // control pw
vco_att_pw = hslider ("att_pw", 0, 0, 100, 1) : si.smooth (0.999); // control att pw
vco_duty = (vco_att_pw * 0.01 * vco_in_pw * 0.5) + vco_pw * 0.01;

vco_gain = hslider ("gain", 0.5, 0, 1, 0.01) : si.smooth (0.999); // Parámetro de ganancia
vco_gate = button ("gate") : si.smooth (0.999); // Parámetro gate (on - off)

// Sine - senoidal

out_sine = (0.5 * vco_modf +1) * os.osc(vco_freq + vco_modf);

// Sawtooth - diente de sierra

out1 = (os.saw2(vco_freq + vco_modf)*A);
out2 = (os.saw5(vco_freq + vco_modf)*B);

// Triangle - triangular

out5 = (os.triangleN(2, vco_freq + vco_modf)*A);
out6 = (os.triangleN(5, vco_freq + vco_modf)*B);

// Pulse - rectangular

out7 = (os.pulsetrainN(2, vco_freq + vco_modf, vco_duty))*A;
out8 = (os.pulsetrainN(5, vco_freq + vco_modf, vco_duty))*B;

// Salidas
out_sawtooth = out1+out2;
out_sawtooth_inv = -out_sawtooth;
out_triangle = out5+out6;
out_square = out7+out8;

vco_shape = vslider("[0] signal [style:menu{'Sine':0; 'Sawtooth':1; 'Sawtooth inv':2; 'Triangle':3; 'Square':4}]", 0, 0, 4, 1);

signal= out_sine, out_sawtooth, out_sawtooth_inv, out_triangle, out_square: ba.selectn(5, vco_shape) : _;


process = vgroup ("output", signal * vco_gain * vco_gate);

