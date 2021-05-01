cmake_minimum_required(VERSION 3.12)

project(cses VERSION 0.1.0)

FILE(GLOB srcFiles src/*.cpp)

#message(${srcFiles})
#add_library(csesLib ${srcFiles})
foreach (MYFILE ${srcFiles})
	#string(REGEX REPLACE "\\.[^.]*$" "" MYFILE_WITHOUT_EXT ${MYFILE})
	string(REGEX REPLACE "\\.cpp$" "" MYFILE_WITHOUT_EXT ${MYFILE})
	string(REGEX REPLACE "^.*src/" "" name ${MYFILE_WITHOUT_EXT})
	#message(${name})
	#message(${name} " Samar " ${MYFILE})
	add_executable(${name} ${MYFILE})
endforeach(MYFILE)

