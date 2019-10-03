#include "Building.h"
#include "Entrances.h"

using namespace BuildingChallenge;
using namespace Addons;

int main() {
	// Create prompter
	// Create level builder
	// Start prompter
	// Get first level order
	// Build first level
	// Get remaining level orders
	//

	Building b;
	Level l;
	Entrances::RevolvingDoor r(l);
	Entrances::GarageDoor g(r);

	b.AddLevel(g);

	b.Build();

	return 0;
}