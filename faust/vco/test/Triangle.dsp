import("stdfaust.lib");
import("signals.lib");
import ("oscillators.lib");
import ("filters.lib");

// Filtros	
fc = 500;

freq = hslider ("freq", 440, 50, 4000, 0.01) : smooth (0.999); // Llamar a este slider desde afuera

A = fc>freq;
B = fc<freq;

gain = hslider ("gain", 0.5, 0, 1, 0.01) : smooth (0.999); // Llamar a este slider desde afuera.
gate = checkbox ("gate") : smooth (0.999); // Llamar a este gate desde afuera

// Triangle Wave

out5 = (triangleN(2,freq)*A);
out6 = (triangleN(5,freq)*B);

// Salidas

out_triangle = out5+out6;

//wave = vslider("[0] signal [style:menu{'Sawtooth':0;'Square':1;'Triangle':2}]", 0, 0, 2, 1);

//signal= out_sawtooth, out_square, out_triangle: select3(wave);

process = vgroup ("Triangle", out_triangle*gain*gate);


