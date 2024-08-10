cmake_minimum_required(VERSION 3.30)
project(datrueone)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS ON)

file(GLOB datrueoneFiles "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
foreach(sourcefile ${datrueoneFiles})
	get_filename_component(executable ${sourcefile} NAME_WE)
	add_executable(${executable} ${sourcefile})
endforeach(sourcefile ${datrueoneFiles})
