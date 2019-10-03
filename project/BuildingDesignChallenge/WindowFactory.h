#pragma once
#include "Windows.h"
namespace BuildingChallenge {
	namespace LevelAddons {
		namespace Windows {
			class InvalidWindowException : public std::exception {
			public:
				InvalidWindowException(const std::string& type) :
					type_(type) {};
				const char* what() const throw() {
					return "Invalid window type";
				}
				const char* get_type() {
					return type_.c_str();
				}
			private:
				std::string type_;
			};

			std::shared_ptr<LevelAddon> Create(const std::string& name) {
				if (!_strcmpi(name.c_str(), DoublePane().GetName().c_str())) {
					return std::make_shared<DoublePane>();
				}
				else if (!_strcmpi(name.c_str(), SinglePane().GetName().c_str())) {
					return std::make_shared<SinglePane>();
				}
				else if (!_strcmpi(name.c_str(), EnergyEfficient().GetName().c_str())) {
					return std::make_shared<EnergyEfficient>();
				}
				else if (!_strcmpi(name.c_str(), StainedGlass().GetName().c_str())) {
					return std::make_shared<StainedGlass>();
				}
				else {
					throw InvalidWindowException(name);
				}

				DoublePane d;
				return std::make_shared<DoublePane>(d);
			}
		}
	}
}