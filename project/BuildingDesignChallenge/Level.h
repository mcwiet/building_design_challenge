#pragma once
#include "Buildable.h"
#include "LevelAddon.h"
#include <memory>
#include <vector>
namespace BuildingChallenge {
	class Level : public Buildable {
	public:
		Level();
		void AddOn(std::unique_ptr<LevelAddons::LevelAddon>);
	private:
		virtual void OnAfterBuild() override;

		std::vector<std::unique_ptr<LevelAddons::LevelAddon>> addons_;
	};
}
