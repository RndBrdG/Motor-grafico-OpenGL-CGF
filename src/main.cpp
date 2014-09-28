/* 
 * G0_Base: projeto inicial de LAIG
 * 
 */

#include <iostream>
#include <exception>

#include "CGFapplication.h"
#include "DemoScene.h"
#include "XMLScene.h"

using std::cout;
using std::exception;

int main(int argc, char* argv[]) {

	CGFapplication app = CGFapplication();

	try {
		app.init(&argc, argv);

		new XMLScene("demograph.xml");
		app.setScene(new DemoScene());
		app.setInterface(new CGFinterface());
		
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
