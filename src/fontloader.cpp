#include "fontloader.h"

static FT_Library ftInstance;

void FontLoader::init() {
    if (FT_Init_FreeType(&ftInstance)) {
        std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl; // DEBUG
    }else {
        std::cout << "ERROR::FREETYPE: Succes init FreeType Library" << std::endl; // DEBUG
    }
}

FT_Face& FontLoader::loadFont(const char* _path) {
    FT_Face face = NULL;
    if (FT_New_Face(ftInstance, _path, 0, &face)) {
        std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
    }else {
        std::cout << "ERROR::FREETYPE: Loaded font at path " << _path << std::endl; // DEBUG
    }
    return face;
}
