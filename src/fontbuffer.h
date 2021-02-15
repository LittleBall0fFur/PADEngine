/// @file fontbuffer.h
/// @brief Standalone header providing FontBuffer functionality.
/// @author Sidney Dijkstra
/// @version 1.0.0
/// @date 02/01/2021

#ifndef FONTBUFFER_CLASS
#define FONTBUFFER_CLASS

#include "texturebuffer.h"
#include "fontloader.h"
#include <map>
#include <glm.hpp>

/// @brief Strukt holding Character information.
struct Character {
	TextureBuffer* textureBuffer; // ID handle of the glyph texture
	glm::ivec2 size; // Size of glyph
	glm::ivec2 bearing; // Offset from baseline to left/top of glyph
	unsigned int advance; // Offset to advance to next glyph
};

/// @brief Class holding FontBuffer information.
class FontBuffer {
	public:
		FontBuffer(const char* _path);
		~FontBuffer();

		Character getCharacter(char _char);

	private:
		FT_Face _fontFace;
		std::map<char, Character> _characters;

		void setup();
};
#endif