#pragma once
#include "state.h"
#include "gui.h"
#include "gameState.h"

class mainMenuState :
	public state


{
private:
	sf::RectangleShape background;
	sf::Texture backgroundTexture; //18


	void initBackground();
	void initVariables();

protected:
	//attributes


	//button *gamestate_btn;
	void initButtons();
	std::map<std::string, gui::button*> buttons;

public:
	mainMenuState(sf::RenderWindow* window, std::stack<state*>* states);
	virtual ~mainMenuState();

	//methods


	//update

	void updateInput(const float& dt);
	void updateButtons(const float& dt);
	void update(const float& dt);

	//Render

	void render(sf::RenderTarget* target = nullptr); //nullptr - default value for the parameter
	void renderButtons(sf::RenderTarget* target = nullptr);
};



