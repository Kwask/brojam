# compiler
CXX = g++
# compiler flags
CFLAGS = -std=c++11
# linker flags 
LFLAGS :=
MODULES := include include/helpers include/patterns include/RakNet

LIBS :=
SRC := main.cpp

include $(patsubst %, %/module.mk, $(MODULES))

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

	@echo "Object compilation complete"
	@$(CXX) $(CFLAGS) $(OBJS) -o $(BINARY) $(LIBS)
	@echo "Binary file generated"
