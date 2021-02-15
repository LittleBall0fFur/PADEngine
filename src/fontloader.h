/// @file fontloader.h
/// @brief Standalone header providing FontLoader functionality.
/// @author Sidney Dijkstra
/// @version 1.0.0
/// @date 02/01/2021

#ifndef FONTLOADER_CLASS
#define FONTLOADER_CLASS

#include <iostream>
#include <ft2build.h>
#include FT_FREETYPE_H  

/// @brief Class holding config information.
class FontLoader {
	public:
		/// @brief Init function for font loader, setup for instance of FreeType.
		static void init();
		/// @brief Function to load a font.
		/// @param _path Path to font file.
		/// @return Refrence of font face.
		static FT_Face& loadFont(const char* _path);

	private:
};
#endif