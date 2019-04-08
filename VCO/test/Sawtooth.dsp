import ("stdfaust.lib");
import ("oscillators.lib");
import ("filters.lib");
import("signals.lib");

// Filtros	
fc = 500;

freq = hslider ("freq", 440, 50, 4000, 0.01) : smooth (0.999); // Sacar este slider. Hacer que llame a la frecuencia desde Android.
 
A = fc>freq;
B = fc<freq;

gain = hslider ("gain", 0.5, 0, 1, 0.01) : smooth (0.999); // Llamar a este slider desde afuera.
gate = checkbox ("gate") : smooth (0.999); // Llamar a este gate desde afuera

// Sawtooth

out1 = (saw2(freq)*A);
out2 = (saw5(freq)*B);

// Salida
out_sawtooth = out1+out2;
 
//wave = vslider("[0] signal [style:menu{'Sawtooth':0;'Square':1;'Triangle':2}]", 0, 0, 2, 1);

//signal= out_sawtooth, out_square, out_triangle: select3(wave);

process = vgroup ("Sawtooth", out_sawtooth*gain*gate);

