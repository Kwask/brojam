CC = g++

# compiler flags
CFLAGS = -std=c++11 -Wall

# the different directories
IDIR = ./include
ODIR = ./obj
DDIR = ./doc
BDIR = ./bin

# top level files
SRC = main.cpp 

# all .h files without directory
_DEPH = 
# all .cpp files without directory
_DEPSRC = $(_DEPH:.h=.cpp)

# all .h files with directory
DEPH = $(patsubst %,$(IDIR)/%,$(_DEPH))
# all .cpp files with directory
DEPSRC = $(patsubst %,$(IDIR)/%,$(_DEPSRC))

# all source files without directory and all header files with directory
_FILES = $(SRC) $(_DEPSRC) $(DEPH)
# all files with directory
FILES = $(SRC) $(DEPSRC) $(DEPH)

# .o filenames with directory
OBJS = $(_FILES:.cpp=.o)

# the linker flags for the compiler
LINKER_FLAGS = -lGLEW -lglfw3 -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread

# the output file
LINUX_BIN = wildlife.out
ERRORS_FILE = errors.txt

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
	@$(CC) $(CFLAGS) -c $(FILES) 
	@echo "Object compilation complete"
	@$(CC) $(CFLAGS) $(OBJS) -o $(BDIR)/$(LINUX_BIN) $(LINKER_FLAGS)
	@echo "Binary file generated"

clean:
	$(RM) -r *.o *~ *.gch *.out

travis:
	@echo "Generating Travis CI build"
	@echo "--------------------"
	@echo "Environment: `uname -a`"
	@echo "Compiler: `$(CXX) --version`"
	@echo "--------------------"
	@$(CXX) $(CFLAGS) -c $(FILES) 
	@echo "Object compilation complete"
	@$(CXX) $(CFLAGS) $(OBJS) -o $(BDIR)/$(LINUX_BIN) $(LINKER_FLAGS)
	@echo "Binary file generated"