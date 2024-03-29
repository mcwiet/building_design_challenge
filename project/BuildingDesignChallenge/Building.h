#pragma once
#include "Buildable.h"
#include "Level.h"
#include <vector>

namespace BuildingChallenge {
	class Building : public Buildable {
	public:
		Building();
		virtual void OnAfterBuild() override;
		void AddLevel(std::unique_ptr<Level>);

	private:
		std::vector<std::unique_ptr<Level>> levels_;
	};
}
