import ("filters.lib");
import ("oscillators.lib");
import ("stdfaust.lib");
import ("maths.lib");
import ("signals.lib");

// 2 entradas: Señal y LFO
// Control de seleccion de filtro, frecuencia de corte, resonancia, cantidad de modulacion (LFO) y ganancia de salida

input = no.noise ; 																							 // señal de entrada

ctrl_input = 0;       																			 	 		 //señal de entrada de control (de -1 a 1)(LFO)

filter_type = hslider("[0] Filtro [style:knob][style : menu{'Pasabajo':0;'Pasabanda':1;'Pasaalto':2}]",0,0,2,1);		 	 // seleccion de filtro

fc = hslider ("[1] Frecuencia de corte [unit:Hz] [style:knob] [scale:log10]", 440, 50, 20000, 0.1) : smooth (0.999);		 // frecuencia de corte

ctrl_input_level = hslider ("[3] Cantidad de modulación [style:knob] ", 1, 0, 1, 0.01) : smooth (0.999); 	 // slider de influencia del input de control sobre la frecuencia de corte (0 a 1)

Q = hslider ("[2] Q [style:knob]", 1, 0.1, 30, 0.01) : smooth (0.999); 										 // reso del filtro

gain = hslider ("[4] gain [style:knob]", 0.5, 0, 1, 0.01) : smooth (0.999);									 // ganancia de salida

gate = checkbox ("[5] gate") : smooth (0.999); 																 // on off para testing

//diseño de filtros

frecmod = fc + 60*ctrl_input_level*ctrl_input;															 	 // frecuencia de corte + 60*(nivel de entrada del ctrl_input)*(control sobre ctrl input) en su maximo llega a 6000Hz

lp = resonlp(frecmod,Q,gain);																				 

hp = resonhp(frecmod,Q,gain);

bp = resonbp(frecmod,Q,gain);

// filtrado																			

out_lp = input:lp;

out_hp = input:hp;

out_bp = input:bp;

signal = out_lp, out_bp, out_hp: select3(filter_type);

process = vgroup ("LPF", signal*gain*gate);
