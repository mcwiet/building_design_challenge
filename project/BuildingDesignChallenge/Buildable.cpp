#include "Buildable.h"

namespace BuildingChallenge {
	Buildable::Buildable(const std::string& name) :
		name_(name) {}
	std::string Buildable::GetName() {
		return OnGetName();
	}
	void Buildable::Build() {
		OnBeforeBuild();
		OnBuild();
	}
	std::string Buildable::OnGetName() {
		return name_;
	}
	void Buildable::OnBuild() {
		std::cout << "Building " << name_ << "..." << std::endl;
	}
}