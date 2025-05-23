#include "materialmanager.h"

namespace pad {

static MaterialManager* _instance;

MaterialManager::MaterialManager() {
	_materials = std::map<std::string, MaterialBuffer*>();
}

MaterialManager* MaterialManager::getInstance() {
	if (!_instance) {
		_instance = new MaterialManager();
	}
	return _instance;
}

void MaterialManager::deleteInstance() {
	delete _instance;
	_instance = nullptr;
}

void MaterialManager::loadMaterial(MaterialData _data) {
	MaterialBuffer* t = new MaterialBuffer(_data);
	std::cout << _data.name << " => " << " -> material loaded" << '\n';

	_materials[_data.name] = t;
}

MaterialBuffer* MaterialManager::getMaterial(const char* _name) {
	if (auto it = _materials.find(_name); it != _materials.end()) {
		return it->second;
	}
	return nullptr;
}

void MaterialManager::recreateAll() {
	std::map<std::string, MaterialBuffer*>::iterator mat_it;
	for (mat_it = _materials.begin(); mat_it != _materials.end(); ++mat_it) {
		if (mat_it->second != NULL) {
			mat_it->second->getShaderPass()->recreate();
		}
	}
}

MaterialManager::~MaterialManager() {
	std::map<std::string, MaterialBuffer*>::iterator mat_it;
	for (mat_it = _materials.begin(); mat_it != _materials.end(); ++mat_it) {
		if (mat_it->second != NULL) {
			delete mat_it->second;
		}
	}
	_materials.clear();
}

}