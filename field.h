#pragma once
#include "entity.h"
#include "player.h"


class field :
	public entity
{
private:
	




protected:
	//bool loadTexture;
	sf::Text* fieldTitle;
	sf::Font font;
	sf::Color color;
	sf::RectangleShape* titleBar;
	int cnt;
	

	virtual void createAndSetTitleBar();
	virtual void setFieldText(sf::Text* fieldText, float x, float y, int rotation, sf::Font font, int fontSize, sf::Color color, std::string text);

	//field actions
	
	virtual void chargePlayer(player* playerOnField, int sum);
	//virtual void 


public:
	unsigned int ID;
	std::map<int, sf::Vector2f> tokenSlots;
	sf::Text fieldType;
	sf::Text fieldDescription;

	field();
	virtual ~field();
	virtual void initTokenSlots();

	//public field actions
	virtual void onStepAction(player* playerOnField) = 0;

	//Render
	virtual void render(sf::RenderTarget* target); 
	virtual void update(const float& dt, sf::Vector2f mousePos);
	virtual sf::Vector2f getTokenSlot();



};

