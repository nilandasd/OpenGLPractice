#include "shader.hpp"

Shader::Shader(const std::string& fp): filepath(fp), renderID(0) {
  ShaderProgramSource source = ParseShader();

  std::cout << "VERTEX" << std::endl << source.VertexSource << std::endl;
  std::cout << "FRAGMENT" << std::endl << source.FragmentSource << std::endl;

  renderID = CreateShader(source.VertexSource, source.FragmentSource);
}

Shader::~Shader() {
	glCall( glDeleteProgram(renderID) );
}

void Shader::Bind() const {
  glCall( glUseProgram(renderID) );
}

void Shader::Unbind() const {
  glCall( glUseProgram(0) );
}

int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
  glCall(unsigned int program = glCreateProgram());
  unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
  unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

  glCall( glAttachShader(program, vs) );
  glCall( glAttachShader(program, fs) );
  glCall( glLinkProgram(program) );

  GLint program_linked;

  glCall( glGetProgramiv(program, GL_LINK_STATUS, &program_linked) );
  std::cout << "Program link status: " << program_linked << std::endl;
  if (program_linked != GL_TRUE) {
    GLsizei log_length = 0;
    GLchar message[1024];
    glCall( glGetProgramInfoLog(program, 1024, &log_length, message) );
    std::cout << "Failed to link program" << std::endl;
    std::cout << message << std::endl;
  }

  glCall( glValidateProgram(program) );
  glCall( glDeleteShader(vs) );
  glCall( glDeleteShader(fs) );

  return program;
}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source) {
  glCall( unsigned int id = glCreateShader(type) );
  const char* src = source.c_str();
  glCall( glShaderSource(id, 1, &src, nullptr) );
  glCall( glCompileShader(id) );

  // Error handling
  int result;
  glCall( glGetShaderiv(id, GL_COMPILE_STATUS, &result) );
  std::cout << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader compile status: " << result << std::endl;
  if ( result == GL_FALSE ) {
    int length;
    glCall( glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length) );
    char* message = (char*) alloca(length * sizeof(char));
    glCall( glGetShaderInfoLog(id, length, &length, message) );
    std::cout 
      << "Failed to compile "
      << (type == GL_VERTEX_SHADER ? "vertex" : "fragment")
      << " shader"
      << std::endl;
    std::cout << message << std::endl;
    glCall( glDeleteShader(id) );
    return 0;
  }

  return id;
}

 ShaderProgramSource Shader::ParseShader() {
  enum class ShaderType {
    NONE = -1, VERTEX = 0, FRAGMENT = 1
  };

  std::ifstream stream(filepath);
  std::string line;
  std::stringstream ss[2];
  ShaderType type = ShaderType::NONE;

  while (getline(stream, line)) {
    if (line.find("#shader") != std::string::npos) {
      if (line.find("vertex") != std::string::npos)
        type = ShaderType::VERTEX;
      else if (line.find("fragment") != std::string::npos)
        type = ShaderType::FRAGMENT;
    } else {
      ss[(int)type] << line << '\n';
    }
  }

  return { ss[0].str(), ss[1].str() };
}

void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3) {
  glCall( glUniform4f(GetUniformLocation(name), v0, v1, v2, v3) );
}

void Shader::SetUniform1i(const std::string& name, int v0) {
  glCall( glUniform1i(GetUniformLocation(name), v0) );
}

void Shader::SetUniformMat4f(const std::string& name, const glm::mat4& matrix) {
  glCall( glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]) );
}

unsigned int Shader::GetUniformLocation(const std::string& name) {
  if (uniform_location_cache.find(name) != uniform_location_cache.end())
    return uniform_location_cache[name];

  glCall( int location = glGetUniformLocation(renderID, name.c_str()) );
  if (location == -1)
    std::cout << "WARNING: uniform" << name << " does not exist." << std::endl;
  else
    uniform_location_cache[name] = location;

  return location;
}
