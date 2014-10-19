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

		std::stringstream file;
		file << "../res/";
		std::string temp;
		cin >> temp;
		file << temp << ".anf";

		app.setScene(new DemoScene(const_cast<char*>(file.str().c_str())));
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
