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
	
	//std::map<enum font_sizes, int>* fontSize;
	//std::map<unsigned short, int>* fontSize;



	
	virtual void createAndSetTitleBar();
	virtual void setFieldText(sf::Text* fieldText, float x, float y, int rotation, sf::Font font, int fontSize, sf::Color color, std::string text);

	//virtual void 


public:
	unsigned int ID;
	std::map<int, sf::Vector2f> tokenSlots;
	virtual void initTokenSlots();
	sf::Text fieldType;
	sf::Text fieldDescription;

	field();
	virtual ~field();

	//Render
	virtual void render(sf::RenderTarget* target); 
	virtual void update(const float& dt, sf::Vector2f mousePos);
	virtual sf::Vector2f getTokenSlot();



};

