# compiler
CXX = g++
# compiler flags
CFLAGS = -std=c++11 -Wall
# linker flags 
LFLAGS = -lGLEW -lglfw3 -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread 

# compiling list of object files
MAIN_SRC = $(*.cpp)
MAIN_OBJ = $(MAIN_SRC:.cpp=.o)

INCLUDE_SRC = $(wildcard include/*.cpp)
RAKNET_SRC = $(wildcard include/RakNet/*.cpp)
HELPERS_SRC = $(wildcard include/helpers/*.cpp)
PATTERNS_SRC = $(wildcard include/patterns/*.cpp)

SRCS = $(MAIN_SRC) $(INCLUDE_SRC) $(RAKNET_SRC) $(HELPERS_SRC) $(PATTERNS_SRC) 

OBJS = $(SRCS:.cpp=.o)

BINARY = brojam.out

.PHONY: clean
.PHONY: travis

#Compile(output into error.txt if there is an error), link, then run
# CXX defined in .travis.yml and build.sh
linux: 
	@echo "Generating Linux build"
	@echo "--------------------"
	@echo "Environment: `uname -a`"
	@echo "Compiler: `$(CXX) --version`"
	@echo "--------------------"

	@echo "Compiling objects in include/"
	@make -f include/Makefile
	@echo "Compiling objects in include/helpers"
	@make -f include/helpers/Makefile
	@echo "Compiling objects in include/patterns"
	@make -f include/patterns/Makefile
	@echo "Compiling objects in include/RakNet"
	@make -f include/RakNet/Makefile

	@echo "Object compilation complete"
	@$(CXX) $(CFLAGS) $(OBJS) -o $(BINARY) $(LFLAGS)
	@echo "Binary file generated"

clean:
	$(RM) -r *.o *~ *.gch *.out

travis:
	@echo "Generating Travis CI build"
	@echo "--------------------"
	@echo "Environment: `uname -a`"
	@echo "Compiler: `$(CXX) --version`"
	@echo "--------------------"

	@make -f include/Makefile
	@make -f include/helpers/Makefile
	@make -f include/patterns/Makefile
	@make -f include/RakNet/Makefile

	@echo "Object compilation complete"
	@$(CXX) $(CFLAGS) $(OBJS) -o $(BINARY) $(LFLAGS)
	@echo "Binary file generated"
