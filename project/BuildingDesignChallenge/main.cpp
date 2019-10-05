#include "CommandLineArchitect.h"
#include "Windows.h"
#include "WindowFactory.h"
#include <string>

using namespace BuildingChallenge;

int main() {
	// Create prompter
	// Create level builder
	// Start prompter
	// Get first level Blueprint
	// Build first level
	// Get remaining level Blueprints
	//

	auto b = LevelAddons::Windows::FactoryMap.at("double pane");
	b->Create()->Build();

	Architects::CommandLineArchitect arch;
	auto x = LevelAddons::Windows::FactoryMap;
	auto junk = arch.GetAddon(2, std::string("Window"), true, x);

	for (int num = junk.second; num > 0; --num)
		junk.first->Build();

	return 0;
}