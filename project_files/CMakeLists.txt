cmake_minimum_required(VERSION 2.8.9)
project(kpfn_project)
 
#Bring the headers, such as Student.h into the project
include_directories(include)
 
#Can manually add the sources using the set command as follows:
set(SOURCES src/killPart/kill.c src/main/main.c src/readDirs/readAllDirs.c)
 
#However, the file(GLOB...) allows for wildcard additions:
#file(GLOB SOURCES "src/*.c")
 
add_executable(kpfn ${SOURCES})
