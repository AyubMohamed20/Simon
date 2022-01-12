# CMakeList.txt : CMake project for FinalCPPProject, include source and define
# project specific logic here.

cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (FinalCPPProject "FinalCPPProject.cpp" "FinalCPPProject.h")

# TODO: Add tests and install targets if needed.
target_include_directories(FinalCPPProject PUBLIC "C:\\Users\\AyubM\\Downloads\\nana_1.7.4\\include") 
target_link_directories(FinalCPPProject PUBLIC "C:\\Users\\AyubM\\Downloads\\nana_1.7.4\\build\\bin")
add_definitions(-D_SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING)
add_definitions(-DNANA_ENABLE_AUDIO) 
target_link_libraries(FinalCPPProject "nana_v142_Debug_x64") 