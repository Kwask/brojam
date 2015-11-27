SRC += include/Atom.cpp \
	   include/Coord.cpp \
	   include/Engine.cpp \
	   include/EngineFSM.cpp \
	   include/EngineStates.cpp \
	   include/Rect.cpp \
	   include/Mob.cpp \
	   include/Planet.cpp \
	   include/Gravity.cpp \
	   include/Creature.cpp \
	   include/PlayerCommands.cpp \
	   include/CommandHandler.cpp 

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


