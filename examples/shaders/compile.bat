glslc vertex_shader.vert -o vert.spv
glslc fragment_shader.frag -o frag.spv
glslc vertex_shader_custom.vert -o vert_custom.spv
glslc fragment_shader_custom.frag -o frag_custom.spv
glslc vertex_shader_text.vert -o vert_text.spv
glslc fragment_shader_text.frag -o frag_text.spv
cd ../../_build
cmake ..
PAUSE
