import ("filters.lib");
import ("oscillators.lib");
import ("stdfaust.lib");
import ("maths.lib");


input = no.noise ; 															 // señal de entrada

ctrl_input = os.saw3;       												 //señal de control (de -1 a 1)

filter_type = hslider("Tipo de filtro",0,0,2,1);							 // seleccion de filtro

fc = hslider ("Cutoff", 440, 50, 20000, 0.1) : smooth (0.999);					 // frecuencia de corte

ctrl_input_level = hslider("Cantidad de modulación", 1, 0, 1, 0.01) : smooth (0.999); 	 // slider de influencia del input de control sobre la frecuencia de corte (0 a 1)

frecmod = fc + 60*ctrl_input_level*ctrl_input;								// frecuencia de corte + 60*(nivel de entrada del ctrl_input)*(control sobre ctrl input) en su maximo llega a 6000Hz

Q = hslider ("Q", 1, 0.1, 30, 0.01) : smooth (0.999); 						// reso del filtro
  
  //////////////////////////////

gain = hslider ("gain", 0.5, 0, 1, 0.01) : smooth(0.999); // Llamar a este slider desde afuera
gate = checkbox ("gate") : smooth (0.999); // Llamar a este gate desde afuera

//Filtro
lp = resonlp(fc,Q,gain);


// Salida
out_lp = input:lp;


//filter = vslider("[0] filter [style:menu{'Lowpass':0;'Highpass':1;'Bandpass':2}]", 0, 0, 2, 1);

//signal = out_lp, out_hp, out_bp: select3(filter);

process = vgroup ("LPF", out_lp*gain*gate);
