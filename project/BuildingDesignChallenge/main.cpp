#include "CommandLineArchitect.h"
#include "StandardBuildingBuilder.h"
#include "AddonQuestionnaire.h"
#include "Room.h"
#include "Window.h"
#include "Entrance.h"
#include <vector>

using namespace BuildingChallenge;
using namespace LevelAddons;

template <typename T>
Architects::AddonMap<T> MakeMap(std::vector<std::string> names) {
	Architects::AddonMap<T> map;
	for (auto name : names) {
		T addon = T(name);
		map.insert({ addon.GetName(), std::make_shared<T>(addon) });
	}
	return map;
}

int main() {
	std::vector<std::string> entrances = { "Single Door", "Double Door", "Revolving Door", "Garage Door", "ULTIMATE MIKE DOOR" };
	std::vector<std::string> windows = { "Single Pane", "Double Pane", "Stained Glass", "Energy Efficient" };
	std::vector<std::string> rooms = { "Gym", "Office", "Storage", "Suite" };

	auto entrance_map = MakeMap<Entrance>(entrances);
	auto window_map = MakeMap<Window>(windows);
	auto room_map = MakeMap<Room>(rooms);

	auto eq = Architects::AddonQuestionnaire<Entrance>(Entrance().GetName(), entrance_map, Architects::Minimum::One);
	auto wq = Architects::AddonQuestionnaire<Window>(Window().GetName(), window_map, Architects::Minimum::Zero);
	auto rq = Architects::AddonQuestionnaire<Room>(Room().GetName(), room_map, Architects::Minimum::One);

	auto bp = Architects::CommandLineArchitect().DesignStandardBuilding(eq, wq, rq);

	Builders::StandardBuildingBuilder().Build(bp);

	return 0;
}