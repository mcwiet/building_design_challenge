#include "Building.h"
#include "LevelBlueprint.h"
#include "StandardBuildingBlueprint.h"
#include "WindowFactory.h"
#include "EntranceFactory.h"

using namespace BuildingChallenge;
using namespace LevelAddons;

int main() {
	// Create prompter
	// Create level builder
	// Start prompter
	// Get first level Blueprint
	// Build first level
	// Get remaining level Blueprints
	//

	Level l;
	auto first = std::make_shared<Blueprints::EntranceLevelBlueprint>();
	first->Windows = { std::make_shared<Windows::DoublePane>(), 10 };

	Blueprints::StandardBuildingBlueprint Blueprint(first);

	for (int i = Blueprint.GetFirstLevel()->Windows.second; i > 0; --i) {
		l.AddOn(Blueprint.GetFirstLevel()->Windows.first);
	}

	try {
		l.AddOn(Windows::Create("stained glass"));
		l.AddOn(Entrances::Create("double door"));
	}
	catch (Windows::InvalidWindowException& e) {
		std::cout << "Error: " << e.what() << " ('" << e.get_type() << "')" << std::endl;
	}

	l.Build();

	return 0;
}