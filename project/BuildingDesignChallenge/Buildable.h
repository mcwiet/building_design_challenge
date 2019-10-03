#pragma once
#include <string>
#include <iostream>

namespace BuildingChallenge {
	class Buildable {
	public:
		Buildable(const std::string&);
		std::string GetName();
		void Build();
	protected:
		virtual std::string OnGetName();
		virtual void OnBuild();
		virtual void OnBeforeBuild() = 0;

		std::string name_;
	};
}
