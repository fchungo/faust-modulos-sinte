import("stdfaust.lib");

/*	############
	 Modulo LFO
	############
	
	Entradas:
		
		1) x_lfo_in_frec1: frecuencia (para modular)
		2) x_lfo_in_frec2: frecuencia (para modular)
		3) x_lfo_in_pw: ancho de pulso (para modular)
		
	Controles:
		
		1) x_lfo_att_freq0: atenuador de la modulacion
		2) x_lfo_att_freq1: atenuador de la modulacion
		3) x_lfo_att_pw: atenuador de la modulacion pw
		4) x_lfo_shape: forma de onda
		5) x_lfo_freq: frecuencia
		6) x_lfo_offset: desvío de frecuencia
		7) pw: ancho de pulso
		8) on-off ¿funciona como en Pd?
		
	Salidas:
	
		1) audio: en la API debe ser algo como 'x_vco_out'

*/

// Se utilizan generadores sustractivos mediante el método polyblep

x_lfo_freq = hslider ("freq", 10, 0.1, 200, 0.01) : si.smooth (0.999); // Parámetro frecuencia

// A: aplica el sustractivo para frecuencias < 500 Hz
// B: aplica el sustractivo para frecuencias > 500 Hz
A = fc>x_lfo_freq;
B = fc<x_lfo_freq;

// Entradas
x_lfo_in_frec1 = 0.00001;
x_lfo_in_frec2 = 0.00001;
x_lfo_in_pw = 0.00001;

// Modulacion de frecuencia (a partir de input_frec, att_freq y freq)
x_lfo_gain = hslider ("gain", 0.5, 0, 1, 0.01) : si.smooth (0.999); // Parámetro de ganancia
x_lfo_gate = checkbox ("gate") : si.smooth (0.999); // Parámetro gate (on - off)

// #### Signal flow para señales de entrada del VCO ####

// Modulacion de frecuencia (a partir de input_frec, att_freq y freq)
x_lfo_att_freq0 = hslider ("att_freq0", 0, 0, 100, 1) : si.smooth (0.999); // control att_freq0
x_lfo_att_freq1 = hslider ("att_freq1", 0, 0, 100, 1) : si.smooth (0.999); // control att_freq1
x_lfo_modf = ((0.01 * x_lfo_att_freq0 * x_lfo_in_frec1) + (0.01 * x_lfo_att_freq1 * x_lfo_in_frec2)) * 60;

// Modulacion de amplitud
x_lfo_pw = hslider ("pw", 50, 0, 100, 1) : si.smooth (0.999); // control pw
x_lfo_att_pw = hslider ("att_pw", 0, 0, 100, 1) : si.smooth (0.999); // control att pw
x_lfo_duty = (x_lfo_att_pw * 0.01 * x_lfo_in_pw * 0.5) + x_lfo_pw * 0.01;

// Sine - senoidal

out_sine = os.osc(x_lfo_freq + x_lfo_modf);

// Sawtooth - diente de sierra

out_sawtooth = os.saw1(x_lfo_freq + x_lfo_modf);
out_sawtooth_inv = -out_sawtooth;

// Triangle - triangular

lf_trianglewave(x_lfo_freq) = 2*os.lf_trianglepos(x_lfo_freq) - 1;
out_triangle = lf_trianglewave(x_lfo_freq);

// Square - cuadrada

out_square = os.lf_squarewave(x_lfo_freq);

x_lfo_shape = hslider("[0] signal [style:menu{'Sine':0; 'Sawtooth':1; 'Sawtooth inv':2; 'Triangle':3; 'Square':4}]", 0, 0, 4, 1);

signal= out_sine, out_sawtooth, out_sawtooth_inv, out_triangle, out_square: ba.selectn(5, x_lfo_shape);

process = vgroup("output", signal * x_lfo_gate * x_lfo_gain);