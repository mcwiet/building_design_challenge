#include "Building.h"
#include "LevelOrder.h"
#include "Windows.h"
#include "WindowFactory.h"

using namespace BuildingChallenge;
using namespace LevelAddons;

int main() {
	// Create prompter
	// Create level builder
	// Start prompter
	// Get first level order
	// Build first level
	// Get remaining level orders
	//

	Level l;

	Windows::DoublePane d;

	try {
		l.AddOn(Windows::Create("double pane"));
		l.AddOn(Windows::Create("stained glass"));
	}
	catch (Windows::InvalidWindowException& e) {
		std::cout << "Error: " << e.what() << " ('" << e.get_type() << "')" << std::endl;
	}

	l.Build();

	return 0;
}