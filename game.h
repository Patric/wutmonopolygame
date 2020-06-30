#pragma once
#include "gameState.h"
#include "mainMenuState.h"



class game
	/*!
* Glowna klasa gry. Zmiana ekranów dzialania na zasadzie maszyny stanow. Klasa zawiera stos wskaznikow na stany. Odswiezanie odbywa sie synchronicznie
z zadanym okresem czasu.
	*/
{

private:
	//Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;
	std::vector<sf::VideoMode> videoModes;
	sf::ContextSettings windowSettings;
	bool fullscreen;

	sf::Clock dtClock;

	float dt; //keeps track for how long to do one update and one render, a few milisecond each frame.


	//any time we push a state on here it starts updating the new state on the screen
	std::stack<state*> states; /* is an abstract class, we can't create objects of stare, we can only create pointer of state
	the stack will keep all the states with the active state on top of that							*/
	//Initialisation

	void initStates();
	void initWindow();
	void initVariables();


public:
	//Constructors/Destructors
	game();
	virtual ~game();

	//Methods
	

	//Regular
	void endApplication();


	//Update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//Render
	void render();

	//Core
	void run();
};

