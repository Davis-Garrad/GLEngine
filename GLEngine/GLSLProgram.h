#pragma once

#include <string>
#include <GL/glew.h>

namespace GLEngine {

	class GLSLProgram {

		public:
			GLSLProgram();
			~GLSLProgram();

			// Pass them by reference to stop from copying them each time they need to be used but keep them constant to make sure
			// we don't change them
			void compileShaders(const std::string &vertexShaderFilePath, const std::string &fragmentShaderFilePath);
			void linkShaders();
			void addAttribute(const std::string &attributeName);
			void use();
			void unuse();

			GLint getUniformLocation(std::string uniformName);

		private:
			GLuint m_programID;

			GLuint m_vertexShaderID;
			GLuint m_fragmentShaderID;

			int m_numAttributes;

			void compileShader(const std::string filePath, GLuint shaderID);

	};

}
