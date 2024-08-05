cmake_minimum_required(VERSION 3.0.0)
project(SimpleEnigma VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include(CTest)
# enable_testing()

add_library(SimpleEnigma STATIC src/CipherMap.cpp src/Enigma.cpp src/Plugboard.cpp src/Reflector.cpp src/Rotor.cpp src/StringUtil.cpp)
target_include_directories(SimpleEnigma PUBLIC include)
target_compile_features(SimpleEnigma PUBLIC cxx_std_17)


file(COPY resources DESTINATION .)

add_executable(main src/Main.cpp)
target_link_libraries(main PUBLIC SimpleEnigma)