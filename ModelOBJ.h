#pragma once

// stl include
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// GLEW include
#include <GL/glew.h>

// GLM include files
#define GLM_FORCE_INLINE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


// local
#include "VertexBuffers.h"			// create vertex buffer object
#include "ShaderProgram.h"			// create a shader program



using namespace std;


namespace cs557
{

	class OBJModel {
	
	public:
		/*
		Load an OBJ model from file
		@param path_and_filename - number of rows
		@param shader_program - overwrite the default shader program by passing a hander to the constructor
		*/
		vector<glm::vec3> create(string path_and_filename, int shader_program = -1);


		/*
		Draw the obj model
		@param viewMatrix - a view matrix object
		@param modelMatrix - a model matrix object.
		*/
		void draw(glm::mat4 projectionMatrix, glm::mat4 viewMatrix, glm::mat4 modelMatrix);


		/*
		Return the shader program
		@return - int containing the shader program
		*/
		int getProgram(void) { return program; };

		//Ray Intersection Testing
		int _I; // number indices
		std::vector<std::pair<glm::vec3, glm::vec2> > points; // points and texture coordinates
		std::vector<int> indices;

	private:


		int vaoID[1]; // Our Vertex Array Object
		int vboID[2]; // Our Vertex Buffer Object
		int iboID[1]; // Our Index  Object
		int program;
		int program_backup;

		int viewMatrixLocation;
		int modelMatrixLocation;
		int projMatrixLocation;

	
		int _N; // number of vertices
		//int _I; // number indices
	};
}