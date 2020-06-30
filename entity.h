#pragma once
#include<vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream> //for reading .ini config file
#include <sstream>zz
#include <stack>
#include <map>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

enum font_sizes { BIG_FONT, MEDIUM_FONT, SMALL_FONT };

class entity
	/*!
* Klasa abstrakcyjna okreœlaj¹ca ka¿dy element znajduj¹cy siê na planszy, maj¹cy graficzne przedstawienie.
	*/
{


private:
	void initVariables();

protected: 
	/*it's pointer because we're not going to load a new texture for each of these entities
	every time we create them. We're going to point it out to gamestate or whatever. A point
	to a texture that has been loaded before since loading textures takes a lot of time and space
	

	*/

	sf::Texture* texture; 
	sf::Font font;
	sf::RectangleShape* defaultShape;
	std::map<unsigned short, int> fontSize;
	bool loadTexture;
	//sf::RectangleShape* defaultShape;
		//we can acces from the childclass without getters
	//sf::RectangleShape shape; //Placeholder
	float movementSpeed;


	virtual void scaleFonts();
public:
	sf::Sprite* sprite;//for debug Move to protected later

	entity();

	virtual ~entity();

	//Component functions
	void createSprite(sf::Texture* texture);
	void createRect(float width, float height, sf::Color color, bool originInCenter);
	void setOriginInCenter();

	//Methods
	virtual void setPosition(const float x, const float y);
	
	virtual void move(const float& dt, const float dir_x, const float dir_y);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
};

