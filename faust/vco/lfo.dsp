/*
	############
	 LFO module
	############

	Controls:
		
		1) lfo_shape: forma de onda
		2) lfo_freq: frecuencia
		3) lfo_offset: desvío de frecuencia
		4) pw: ancho de pulso
		5) on-off
*/

lfo_freq = hslider ("low freq", 10, 0.1, 200, 0.01) : si.smooth (0.999); // Frequency control

// Modulacion de frecuencia (a partir de input_frec, att_freq y freq)
lfo_gain = hslider ("low gain", 0.5, 0, 1, 0.01) : si.smooth (0.999); // Parámetro de ganancia
lfo_gate = checkbox ("low gate") : si.smooth (0.999); // Parámetro gate (on - off)

// Sine - senoidal

lfo_out_sine = os.osc(lfo_freq);

// Sawtooth - diente de sierra

lfo_out_sawtooth = os.saw1(lfo_freq);
lfo_out_sawtooth_inv = -lfo_out_sawtooth;

// Triangle - triangular

lf_trianglewave(lfo_freq) = 2*os.lf_trianglepos(lfo_freq) - 1;
lfo_out_triangle = lf_trianglewave(lfo_freq);

// Square - cuadrada

lfo_out_square = os.lf_squarewave(lfo_freq);

lfo_shape = hslider("[0] lfo_signal [style:menu{'Sine':0; 'Sawtooth':1; 'Sawtooth inv':2; 'Triangle':3; 'Square':4}]", 0, 0, 4, 1);

lfo_signal= lfo_out_sine, lfo_out_sawtooth, lfo_out_sawtooth_inv, lfo_out_triangle, lfo_out_square: ba.selectn(5, lfo_shape);

lfo_out = lfo_signal * lfo_gain * lfo_gate;