/* 
 * G0_Base: projeto inicial de LAIG
 * 
 */

#include <iostream>
#include <exception>
#include <sstream>

#include "CGFapplication.h"
#include "DemoScene.h"
#include "TPinterface.h"
#include "XMLScene.h"

using std::cout;
using std::exception;

int main(int argc, char* argv[]) {

	CGFapplication app = CGFapplication();

	try {
		app.init(&argc, argv);

		std::stringstream filename;
		filename << "../res/";
		std::cout << endl << "Introduza o nome do ficheiro da cena\npresente em /res, incluindo a extensao: ";
		std::string temp;
		getline(std::cin, temp);
		std::cout << endl;
		filename << temp;

		app.setScene(new DemoScene(const_cast<char*>(filename.str().c_str())));
		app.setInterface(new TPinterface());
		
		app.run();
	}
	catch (GLexception& ex) {
		cout << "Error: " << ex.what();
		return -1;
	}
	catch (exception& ex) {
		cout << "Unexpected error: " << ex.what();
		return -1;
	}

	return 0;
}
