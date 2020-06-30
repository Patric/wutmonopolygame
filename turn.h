#pragma once
#include <list>
#include "propertyField.h"
#include "trapField.h"
#include "gui.h"


class turn :
	public entity
	/*!
* klasa tury. Zawiera listê graczy oraz kolejkê, a tak¿e wskaŸnik na gracza na jego komputerze. Zawiera najwa¿niejsz¹ czêœæ logiki.
	*/
{
private:

	std::map<std::string, gui::button*> buttons;
	std::vector<player*>* players;
	
	bool moveAvailabe;

	std::vector<field*>* fields;
	sf::Int64 dice;
	sf::Text dots;


	std::list<player*> queue;

	void initButtons();
	void initDice();

public:
	player* you;
	turn(float x, float y, std::vector<player*>* players, std::vector<field*>* fields);
	virtual ~turn();


	void passTurn();
	void setQueue();

	void updateYourTurn(const float& dt, sf::Vector2f mousePos);
	void waitForTurn();


	void updateButtons(sf::Vector2f mousePosView, const float& dt);
	void renderButtons(sf::RenderTarget* target);

	
	void renderTurnInfo(sf::RenderTarget* target);
	void updateTurnInfo(const float& dt);

	void renderDice(sf::RenderTarget* target);
	void updateDice();

	void moveTokenToID(token* tokenToMove, int fieldID);
	void moveToken(token* tokenToMove, int numOfFields);

	void render(sf::RenderTarget* target);
	void update(const float& dt, sf::Vector2f mousePos);

};

