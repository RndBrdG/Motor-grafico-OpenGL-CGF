#include "TPinterface.h"
#include "DemoScene.h"

TPinterface::TPinterface()
{
	testVar = 0;
}


void TPinterface::processKeyboard(unsigned char key, int x, int y)
{
	// Uncomment below if you would like to process the default keys (e.g. 's' for snapshot, 'Esc' for exiting, ...)
	CGFinterface::processKeyboard(key, x, y);

	switch (key)
	{
	case 'a':
	{
		// This is an example of accessing the associated scene
		// To test, create the function toggleSomething in your scene to activate/deactivate something
		//((DemoScene *)scene)->toggleSomething();
		break;
	}
	}
}

void alternarRelogio(int arg) {

}

void TPinterface::initGUI()
{
	/*
	// Check CGFinterface.h and GLUI documentation for the types of controls available
	GLUI_Panel *varPanel = addPanel("Group", 1);
	addSpinnerToPanel(varPanel, "Val 1(interface)", 2, &testVar, 1);

	// You could also pass a reference to a variable from the scene class, if public
	addSpinnerToPanel(varPanel, "Val 2(scene)", 2, &(((DemoScene*)scene)->sceneVar), 2);
	*/
	GLUI_Panel* panelLuzes = addPanel("Luzes");
	for (auto it = static_cast<DemoScene*>(scene)->getLights().cbegin(); it != static_cast<DemoScene*>(scene)->getLights().cend(); it++) {
		addCheckboxToPanel(panelLuzes, "Luz", &(**it).onOff, 1);
	}
}

void TPinterface::processGUI(GLUI_Control *ctrl)
{
	printf("GUI control id: %d\n", ctrl->user_id);
	switch (ctrl->user_id) {
	}
}
