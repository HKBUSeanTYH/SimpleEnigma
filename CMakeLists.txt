cmake_minimum_required(VERSION 3.0.0)
project(SimpleEnigma VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include(CTest)
# enable_testing()

include_directories(include)
set(source_files src/CipherMap.cpp src/Enigma.cpp src/Main.cpp src/Plugboard.cpp src/Reflector.cpp src/Rotor.cpp src/StringUtil.cpp)

# Loop through each source file
foreach(source_file IN LISTS source_files)
    # Get the name of the file without the extension (e.g. 'a' from src/a.cpp'
    get_filename_component(target_name ${source_file} NAME_WE)
    
    # Create an executable with the above name, building the above source
    add_executable("${target_name}" "${source_file}")
endforeach()