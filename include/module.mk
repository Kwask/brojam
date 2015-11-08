SRC += include/Atom.cpp \
	   include/Client.cpp \
	   include/Coord.cpp \
	   include/Engine.cpp \
	   include/EngineFSM.cpp \
	   include/EngineStates.cpp \
	   include/Rect.cpp

LIBS += -lGLEW \
		-lglfw3 \
		-lGL \
		-lX11 \
		-lXi \
		-lXrandr \
		-lXxf86vm \
		-lXinerama \
		-lXcursor \
		-lrt \
		-lm \
		-pthread 


