#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <filesystem>
#include <string>
#include <fstream>

#define MAJOR_VERSION 0
#define MINOR_VERSION 1
#define PATCH 0

void python(char* name) {
  std::cout << "Creating a Python project \n";

  std::filesystem::create_directory(name);
  std::ofstream main(std::string(name) + "/main.py");
  if(!main.is_open()) {
    std::cout << "Failed to create main.py file" << std::endl;
  }

  main << "print(\"Hello, world!\\n\") \n";
  std::ofstream requirements(std::string(name) + "/requirements.txt");
  if(!requirements.is_open()) {
    std::cout << "Failed to create requirements.txt";
  }
}

void C(char* name) {
  std::string srcPath = (std::string)name + "/src";
  std::string includePath = (std::string)name + "/include";
  std::string buildPath = (std::string)name + "/build";
  std::string cmakePath = (std::string)name + "/CMakeLists.txt";
  std::string HLPath = srcPath + "/main.c";

  std::cout << "Creating a C project \n";

  std::filesystem::create_directory(name);
  std::filesystem::create_directories(srcPath);
  std::filesystem::create_directories(includePath);
  std::filesystem::create_directories(buildPath);

  std::ofstream main(HLPath);
  if(!main.is_open()) {
    std::cout << "Failed to create main.c file" << std::endl;
  }

  main << "#include <stdio.h>\n\n";
  main << "int main() {\n";
  main << " printf(\"Hello, world!\\n\");\n";
  main << " return 0;\n";
  main << "}\n";

  std::ofstream cmake(cmakePath);
  if(!cmake.is_open()) {
    std::cout << "Failed to create CMake file" << std::endl;
    return;
  }
  cmake << "cmake_minimum_required(VERSION 3.10) \n";
  cmake << "project(" << name << ") \n";
  cmake << "add_executable(" << name << " src/main.c) \n";
} 
void CPP(char* name) {
  std::string srcPath = (std::string)name + "/src";
  std::string includePath = (std::string)name + "/include";
  std::string buildPath = (std::string)name + "/build";
  std::string cmakePath = (std::string)name + "/CMakeLists.txt";
  std::string HLPath = srcPath + "/main.cpp";

  std::cout << "Creating a C++ project \n";

  std::filesystem::create_directory(name);
  std::filesystem::create_directories(srcPath);
  std::filesystem::create_directories(includePath);
  std::filesystem::create_directories(buildPath);
  std::ofstream main(HLPath);
  if(!main.is_open()) {
    std::cout << "Failed to create main.cpp file" << std::endl;
  }

  main << "#include <iostream>\n\n";
  main << "int main() {\n";
  main << " std::cout << \"Hello, world!\\n\";\n";
  main << " return 0;\n";
  main << "}\n";

  std::ofstream cmake(cmakePath);
  if(!cmake.is_open()) {
    std::cout << "Failed to create CMake file" << std::endl;
    return;
  }
  cmake << "cmake_minimum_required(VERSION 3.10) \n";
  cmake << "project(" << name << ") \n";
  cmake << "add_executable(" << name << " src/main.cpp) \n";
}
void args(int argc, char* argv[]) {
  if (argc == 2 &&
      (strcmp(argv[1], "-v") == 0 ||
       strcmp(argv[1], "--version") == 0)) {

    std::cout << "mkpr version "
      << MAJOR_VERSION << "."
      << MINOR_VERSION << "."
      << PATCH << "\n";
    return;
  }

  if (argc < 4) {
    std::cerr << "Usage: mkpr <name> -lang <language>\n";
    exit(EXIT_FAILURE);
  }

  if(std::filesystem::exists(argv[1])) {
    std::cout << "The directory: " << argv[1] << " already exists" << std::endl;
    return;
  }

  if (strcmp(argv[2], "-lang") == 0) {

    if (strcmp(argv[3], "C") == 0 ||
        strcmp(argv[3], "c") == 0) {

      C(argv[1]);

    } else if (strcmp(argv[3], "C++") == 0 ||
        strcmp(argv[3], "cpp") == 0) {

      CPP(argv[1]);

    } else if(strcmp(argv[3], "Python") == 0 ||
        strcmp(argv[3], "python") == 0 ||
        strcmp(argv[3], "py") == 0 ||
        strcmp(argv[3], "PY") == 0) {

      python(argv[1]);

    } else {
      std::cerr << "Invalid language\n";
      exit(EXIT_FAILURE);
    }
  }
}


int main(int argc, char* argv[]) {
  if(argc <= 1) {
    std::cerr << "No arguments provided \n";
    std::cout << "Usage: mkpr <name> -lang <language>" << std::endl;
    return EXIT_FAILURE;
  }
  args(argc, argv);

  return EXIT_SUCCESS;  
}
