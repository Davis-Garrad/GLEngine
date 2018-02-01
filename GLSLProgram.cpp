#include "GLSLProgram.h"
#include <fstream>
#include <vector>

#include "GLEngineErrors.h"
#include "GLEngineErrors.h"

namespace GLEngine {
	
	GLSLProgram::GLSLProgram() :
			m_programID(0), m_vertexShaderID(0), m_fragmentShaderID(0), m_numAttributes(0) {

	}
	
	GLSLProgram::~GLSLProgram() {

	}
	
	void GLSLProgram::compileShaders(const std::string &vertexShaderFilePath, const std::string &fragmentShaderFilePath) {

		m_programID = glCreateProgram();

		m_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);

		if (m_vertexShaderID == 0) {
			fatalError("Could not create vertex shader.");
		}

		m_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

		if (m_fragmentShaderID == 0) {
			fatalError("Could not create fragment shader.");
		}

		compileShader(vertexShaderFilePath, m_vertexShaderID);
		compileShader(fragmentShaderFilePath, m_fragmentShaderID);

	}
	
	void GLSLProgram::linkShaders() {

		//Vertex and fragment shaders are successfully compiled.
		//Now time to link them together into a program.
		//Get a program object.

		//Attach our shaders to our program
		glAttachShader(m_programID, m_vertexShaderID);
		glAttachShader(m_programID, m_fragmentShaderID);

		//Link our program
		glLinkProgram(m_programID);

		//Note the different functions here: glGetProgram* instead of glGetShader*.
		GLint isLinked = 0;
		glGetProgramiv(m_programID, GL_LINK_STATUS, (int *) &isLinked);
		if (isLinked == GL_FALSE) {
			GLint maxLength = 0;
			glGetProgramiv(m_programID, GL_INFO_LOG_LENGTH, &maxLength);

			//The maxLength includes the NULL character
			std::vector<char> errorLog(maxLength);
			glGetProgramInfoLog(m_programID, maxLength, &maxLength, &errorLog[0]);

			//We don't need the program anymore.
			glDeleteProgram(m_programID);
			//Don't leak shaders either.
			glDeleteShader(m_vertexShaderID);
			glDeleteShader(m_fragmentShaderID);

			std::printf("%s\n", &(errorLog[0]));
			fatalError("Could not link shaders.");
		}
		
		//Always detach shaders after a successful link.
		glDetachShader(m_programID, m_vertexShaderID);
		glDetachShader(m_programID, m_fragmentShaderID);
		
		glDeleteShader(m_vertexShaderID);
		glDeleteShader(m_fragmentShaderID);
		
	}
	
	void GLSLProgram::compileShader(const std::string filePath, GLuint shaderID) {

		std::ifstream shaderFile(filePath);

		if (shaderFile.fail()) {
			perror(filePath.c_str());
			fatalError("Could not load " + filePath);
		}

		std::string fileContents = "";
		std::string line = "";

		while (std::getline(shaderFile, line)) {
			fileContents += line + "\n";
		}
		
		const char* contentPointer = fileContents.c_str();
		
		shaderFile.close();
		glShaderSource(shaderID, 1, &contentPointer, nullptr);
		glCompileShader(shaderID);
		
		GLint success = 0;
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
		
		if (success == GL_FALSE) {

			GLint maxLength = 0;
			glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> errorLog(maxLength);
			glGetShaderInfoLog(shaderID, maxLength, &maxLength, &errorLog[0]);

			// Provide the infolog in whatever manor you deem best.
			// Exit with failure.
			glDeleteShader(shaderID); // Don't leak the shader.

			std::printf("%s\n", &(errorLog[0]));

			fatalError("Could not compile shader at: " + filePath);

		}
		
	}
	
	void GLSLProgram::addAttribute(const std::string &attributeName) {

		glBindAttribLocation(m_programID, m_numAttributes++, attributeName.c_str());

	}
	
	void GLSLProgram::use() {

		glUseProgram(m_programID);

		for (int i = 0; i < m_numAttributes; i++) {
			glEnableVertexAttribArray(i);
		}

	}
	
	void GLSLProgram::unuse() {

		glUseProgram(0);

		for (int i = 0; i < m_numAttributes; i++) {
			glDisableVertexAttribArray(i);
		}

	}
	
	GLint GLSLProgram::getUniformLocation(std::string uniformName) {

		GLuint location = glGetUniformLocation(m_programID, uniformName.c_str());

		if (location == GL_INVALID_INDEX) {

			fatalError("Uniform " + uniformName + " not found in shader.");

		}
		
		return location;
		
	}

}

