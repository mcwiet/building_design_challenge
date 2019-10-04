#pragma once
#include "Buildable.h"
#include "LevelAddon.h"
#include <memory>
#include <vector>
namespace BuildingChallenge {
	class Level : public Buildable {
	public:
		Level();
		void AddOn(std::shared_ptr<Addons::LevelAddon>);
		virtual void OnAfterBuild() override;
	private:
		std::vector<std::shared_ptr<Addons::LevelAddon>> addons_;
	};
}
