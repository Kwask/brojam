# compiler
CXX := g++
# compiler flags
CFLAGS := -std=c++11
# libraries
LIBS :=
# all of the .cpp files
SRC := main.cpp

# All of the folders with a module.mk file
MODULES := include include/helpers include/patterns

# Includes all of the module's module.mk files
include $(patsubst %, %/_module.mk, $(MODULES))

BINARY := brojam.out

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
	# TODO: Object compilation
	@echo "Object compilation complete"
	@$(CXX) $(CFLAGS) $(SRC) -o $(BINARY) $(LIBS)
	@echo "Binary file generated"

clean:
	$(RM) -r *.o *~ *.gch *.out

travis:
	@echo "Generating Travis CI build"
	@echo "--------------------"
	@echo "Environment: `uname -a`"
	@echo "Compiler: `$(CXX) --version`"
	@echo "--------------------"
	# TODO: Object compilation
	@echo "Object compilation complete"
	@$(CXX) $(CFLAGS) $(OBJS) -o $(BINARY) $(LIBS)
	@echo "Binary file generated"
