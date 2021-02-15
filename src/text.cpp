#include "text.h"

Text::Text(const char* _msg, const char* _fontPath) : Entity() {
	this->_msg = _msg;
	this->_type = EntityType::TEXT;
	this->_buffer = ResourceManager::getInstance()->getFont(_fontPath);

	this->_vertexBuffers = std::vector<VertexBuffer*>();
}

void Text::setText(const char* _msg) {
	this->_msg = _msg;
}

std::string Text::getText() {
	return this->_msg;
}

std::vector<VertexBuffer*> Text::getBuffers() {
	return this->_vertexBuffers;
}

void Text::updateDescriptors(int _index) {
	this->setupVertex();
}

void Text::setupVertex() {
	this->clearVertex();

	std::string::const_iterator c;
	for (c = _msg.begin(); c != _msg.end(); c++) {
		Character ch = _buffer->getCharacter(*c);

		float xpos = position.x + ch.bearing.x * scale.x;
		float ypos = position.y - (ch.size.y - ch.bearing.y) * scale.y;

		float w = ch.size.x * scale.x;
		float h = ch.size.y * scale.y;

		std::vector<Vertex> vertices = {
			{{xpos, ypos + h    , 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
			{{xpos, ypos        , 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f}},
			{{xpos + w, ypos    , 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f}},

			{{xpos, ypos + h    , 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
			{{xpos + w, ypos    , 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f}},
			{{xpos + w, ypos + h, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f}},
		};

		VertexBuffer* vb = new VertexBuffer(vertices);
		_vertexBuffers.push_back(vb);
	}
}

void Text::clearVertex() {
	for (VertexBuffer* v : _vertexBuffers) {
		delete v;
	}
	_vertexBuffers.clear();
}

Text::~Text() {
	delete _buffer;
}
