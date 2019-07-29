import("stdfaust.lib");
import ("maths.lib");
import ("signals.lib");
import ("envelopes.lib");

signal = no.noise ; 																							 // señal de entrada

a = hslider("[1] Attack",0.00, 0, 2, 0.001): si.polySmooth (gate,0.999,1);									// Control de ataque -> ver valor de hasta donde llegar con el fader, es en segundos

d = hslider("[2] Decay",0.00, 0, 2, 0.001): si.polySmooth (gate,0.999,1);									//control de decay	-> ver valor de hasta donde llegar con el fader, es en segundos

s = hslider("[3] Sustain",0.00, 0, 1, 0.001): si.polySmooth (gate,0.999,1);									//control de sustain (entre 0 y 1)

r = hslider("[4] Release",0.00, 0, 2, 0.001): si.polySmooth (gate,0.999,1);									//.... es en segundos
  
gain = vslider ("gain", 0.5, 0, 2, 0.01) : smooth (0.999);													// control de ganancia

gate = button ("gate");
  
eg = en.adsr(a,d,s,r,gate);																					//funcion que devuelve adsr*input


process = vgroup("EG",signal*gain*eg);
			