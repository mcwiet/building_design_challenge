#include "CommandLineArchitect.h"
#include "StandardBuildingBuilder.h"

using namespace BuildingChallenge;

int main() {
	auto bp = Architects::CommandLineArchitect().DesignStandardBuilding();
	auto bldg = Builders::StandardBuildingBuilder().Build(bp);

	return 0;
}