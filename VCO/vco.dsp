import ("stdfaust.lib");
import ("oscillators.lib");
import ("filters.lib");
import ("signals.lib");

/*	############
	 Modulo VCO
	############
	
	Entradas:
		
		1) x_vco_in_frec1: frecuencia (para modular)
		2) x_vco_in_frec2: frecuencia (para modular)
		3) x_vco_in_pw: ancho de pulso (para modular)
		
	Controles:
		
		1) x_vco_att_freq0: atenuador de la modulacion
		2) x_vco_att_freq1: atenuador de la modulacion
		3) x_vco_att_pw: atenuador de la modulacion pw
		4) x_vco_shape: forma de onda
		5) x_vco_freq: frecuencia
		6) x_vco_offset: desvío de frecuencia
		7) x_vco_pw: ancho de pulso
		8) x_vco_on-off ¿funciona como en Pd?
		
	Salidas:
	
		1) audio: en la API debe ser algo como 'x_vco_out'

*/

// Se utilizan generadores sustractivos mediante el método polyblep
// Se aplica un polinomio para frecuencias menores a 500 Hz y otro para frecuencias mayores a 500 Hz

fc = 500;
// A: aplica el sustractivo para frecuencias < 500 Hz
// B: aplica el sustractivo para frecuencias > 500 Hz
A = fc>x_vco_freq;
B = fc<x_vco_freq;

x_vco_freq = hslider ("freq", 440, 50, 4000, 0.01) : smooth (0.999); // Parámetro frecuencia

// #### Entradas ####

x_vco_in_frec1 = 0;
x_vco_in_frec2 = 0;
x_vco_in_pw = 0;

// #### Signal flow para señales de entrada del VCO ####

// Modulacion de frecuencia (a partir de input_frec, att_freq y freq)
x_vco_att_freq0 = hslider ("att_freq0", 0, 0, 100, 1) : smooth (0.999); // control att_freq0
x_vco_att_freq1 = hslider ("att_freq1", 0, 0, 100, 1) : smooth (0.999); // control att_freq1
x_vco_modf = ((0.01 * x_vco_att_freq0 * x_vco_in_frec1) + (0.01 * x_vco_att_freq1 * x_vco_in_frec2)) * 60;


// Modulacion de amplitud
x_vco_pw = hslider ("pw", 50, 0, 100, 1) : smooth (0.999); // control pw
x_vco_att_pw = hslider ("att_pw", 0, 0, 100, 1) : smooth (0.999); // control att pw
x_vco_duty = (x_vco_att_pw * 0.01 * x_vco_in_pw * 0.5) + x_vco_pw * 0.01;

x_vco_gain = hslider ("gain", 0.5, 0, 1, 0.01) : smooth (0.999); // Parámetro de ganancia
x_vco_gate = checkbox ("gate") : smooth (0.999); // Parámetro gate (on - off)

// Sine - senoidal

out_sine = osc(x_vco_freq + x_vco_modf);

// Sawtooth - diente de sierra

out1 = (saw2(x_vco_freq + x_vco_modf)*A);
out2 = (saw5(x_vco_freq + x_vco_modf)*B);

// Triangle - triangular

out5 = (triangleN(2, x_vco_freq + x_vco_modf)*A);
out6 = (triangleN(5, x_vco_freq + x_vco_modf)*B);

// Pulse - rectangular

out7 = (pulsetrainN(2, x_vco_freq + x_vco_modf, x_vco_duty))*A;
out8 = (pulsetrainN(5, x_vco_freq + x_vco_modf, x_vco_duty))*B;

// Salidas
out_sawtooth = out1+out2;
out_sawtooth_inv = -out_sawtooth;
out_triangle = out5+out6;
out_square = out7+out8;

x_vco_shape = vslider("[0] signal [style:menu{'Sine':0; 'Sawtooth':1; 'Sawtooth inv':2; 'Triangle':3; 'Square':4}]", 0, 0, 4, 1);

signal= out_sine, out_sawtooth, out_sawtooth_inv, out_triangle, out_square: selectn(5, x_vco_shape) : _;

process = vgroup ("output", signal*x_vco_gain*x_vco_gate);

