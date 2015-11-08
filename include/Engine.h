#ifndef ENGINE_H
#define ENGINE_H

class Engine
{
private:
	Engine();

	static Engine* instance;

public:
	static Engine* getInstance();
	static void	resetInstance();

	virtual ~Engine();

	void handle();

	bool shouldStop();

};

#endif
