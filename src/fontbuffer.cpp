#include "fontbuffer.h"

FontBuffer::FontBuffer(const char* _path) {
	_fontFace = FontLoader::loadFont(_path);
}

FontBuffer::~FontBuffer() {
}

Character FontBuffer::getCharacter(char _char) {
	return this->_characters[_char];
}

void FontBuffer::setup() {
    for (unsigned char c = 0; c < 128; c++) {
        // load character glyph 
        if (FT_Load_Char(_fontFace, c, FT_LOAD_RENDER)) {
            std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
            continue;
        }

        // generate texture
        TextureBuffer* t = new TextureBuffer(_fontFace->glyph->bitmap.buffer, _fontFace->glyph->bitmap.width, _fontFace->glyph->bitmap.rows);

        // now store character for later use
        Character character = {
            t,
            glm::ivec2(_fontFace->glyph->bitmap.width, _fontFace->glyph->bitmap.rows),
            glm::ivec2(_fontFace->glyph->bitmap_left, _fontFace->glyph->bitmap_top),
            _fontFace->glyph->advance.x
        };
        _characters.insert(std::pair<char, Character>(c, character));
    }
}
