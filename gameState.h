#pragma once
#include "state.h"
#include "board.h"
#include "player.h"

class gameState :
	public state
	/*!
* Klasa odpowiedzalna za ekran gry, stan gry. Przechowuje informacje dotycz¹ce graczy.
	*/
{	
	
private:
	//token* token1;
	//board* gameStateBoard;
	board* gameStateBoard;
	std::vector<player*> players;
	unsigned int numOfPlayers;
	sf::RectangleShape background;
	sf::Texture backgroundTexture;

	void initBackground();
	void initTextures();
	void initBoard();
	void initPlayers();
public:
	gameState(sf::RenderWindow* window, std::stack<state*>* states);
	virtual ~gameState();

	//methods
	


	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr); //nullptr - default value for the parameter

};

