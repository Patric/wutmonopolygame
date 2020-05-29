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


//main menu state, different textures, managing resources and memory
class state
{

private:

	
	
	
	

protected:
	//attributes
	sf::RenderWindow* window;
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	std::stack<state*>* states; //a pointer to a stack full of state pointers
	//which is in game.h and is our main stack of states this allows us to
	//get to the stack of states from every single state of that stack

	//Resources
	std::map<std::string, sf::Texture> textures;





	//	std::vector<sf::Texture*> textures;


	bool quit; //we need to be able to quit every state from its class(child class) level
	sf::Font font;
	virtual void initFonts(); 
	virtual sf::Texture loadTexture(std::string location);//every state has initiated fonts but not every states has buttons since
	//most probably we'll be printing some texts rather than blank pages

public:
	//state() {}

	state(sf::RenderWindow* window, std::stack<state*>* states);
	virtual ~state();

	const bool& getQuit() const;
	virtual void endState();
	virtual void updateInput(const float& dt) = 0;
	virtual void updateMousePosition();
	virtual void update(const float& dt) = 0; //purely virtual //menu for example will have to define these methods if it inherits from it
	virtual void render(sf::RenderTarget* target = nullptr) = 0; //purely virtual

};

