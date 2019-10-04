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
				for (auto it : LookupTable) {
					auto window = it.second;
					if (!_strcmpi(name.c_str(), window->GetName().c_str())) {
						return window;
					}
				}
				throw InvalidWindowException(name);
			}
		}
	}
}