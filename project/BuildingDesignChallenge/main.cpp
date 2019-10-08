#include "CommandLineArchitect.h"
#include "StandardBuildingBuilder.h"

using namespace BuildingChallenge;

class Base {
public:
	virtual ~Base() = default;
	virtual void func() = 0;
};

class Derived : public Base {
public:
	virtual void func() override { ; }
};

int main() {
	auto bp = Architects::CommandLineArchitect().DesignStandardBuilding();
	auto bldg = Builders::StandardBuildingBuilder().Build(bp);

	return 0;
}