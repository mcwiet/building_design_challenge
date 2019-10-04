#include "Building.h"
#include "LevelOrder.h"
#include "StandardBuildingOrder.h"
#include "WindowFactory.h"
#include "EntranceFactory.h"

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
	auto first = std::make_shared<Orders::EntranceLevelOrder>();
	first->WindowOrder = { std::make_shared<Windows::DoublePane>(), 10 };

	Orders::StandardBuildingOrder order(first);

	for (int i = order.GetFirstLevel()->WindowOrder.second; i > 0; --i) {
		l.AddOn(order.GetFirstLevel()->WindowOrder.first);
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