.PHONY = all clean
CXX = g++
CXXFLAGS = -Wall -Wextra -g -static
LIBNAME = raylibWindowsO2
LIBPATH = E:\Users\Harri\Documents\GitProjects\raylib
INCLUDEPATH = E:\Users\Harri\Documents\GitProjects\raylib\src

all: GalacticBlobs.exe

GalacticBlobs.exe: main.o game.o input.o libraryWrapper.o
	$(CXX) $(CXXFLAGS) -o GalacticBlobs.exe -L$(LIBPATH) main.o game.o input.o libraryWrapper.o -l$(LIBNAME) -lopengl32 -lgdi32 -lwinmm

main.o: main.cpp game.h input.h libraryWrapper.h
	$(CXX) $(CXXFLAGS) -o main.o -c main.cpp

libraryWrapper.o: libraryWrapper.cpp libraryWrapper.h
	$(CXX) $(CXXFLAGS) -I$(INCLUDEPATH) -o libraryWrapper.o -c libraryWrapper.cpp

game.o: game.cpp game.h input.h libraryWrapper.h
	$(CXX) $(CXXFLAGS) -o game.o -c game.cpp

input.o: input.cpp input.h game.h libraryWrapper.h
	$(CXX) $(CXXFLAGS) -o input.o -c input.cpp

clean:
	del GalacticBlobs.exe main.o libraryWrapper.o game.o input.o
