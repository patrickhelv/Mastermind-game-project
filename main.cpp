#include "std_lib_facilities.h"
#include "masterVisual.h"
#include "test.h"
#include "Graph.h"
#include "Simple_window.h"
#include <locale>

using namespace Graph_lib;

int main(){
	setlocale(LC_ALL, "Norwegian");

	playMasterMind();
	return gui_main();

	keep_window_open();
}



