/// @file text.h
/// @brief Standalone header providing Text functionality.
/// @author Sidney Dijkstra
/// @version 1.0.0
/// @date 02/01/2021

#ifndef TEXT_CLASS
#define TEXT_CLASS

#include "entity.h"
#include "fontbuffer.h"

/// @brief Class holding Text information.
class Text : public Entity {
	public:
		Text(const char* _msg = "", const char* _fontPath = "assets/vgafix.fon");
		~Text();

		void setText(const char* _msg);
		std::string getText();
		std::vector<VertexBuffer*> getBuffers();

		void updateDescriptors(int _index) override;

	private:
		FontBuffer* _buffer;
		std::vector<VertexBuffer*> _vertexBuffers;
		std::string _msg;

		void setupVertex();
		void clearVertex();
};
#endif