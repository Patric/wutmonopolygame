#include "state.h"
void state::initFonts()
{
	if (!this->font.loadFromFile("fonts/MONOPOLY_INLINE.TTF"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT"); //tells us what happened
	}

}

sf::Texture state::loadTexture(std::string location)
{
	sf::Texture temp;
	bool is_Loaded = false;
	is_Loaded = temp.loadFromFile(location);
	if (!is_Loaded) 
	{
		temp.loadFromFile("resources/images/errors/none.png");
	}
	return temp;
}


state::state(sf::RenderWindow* window, std::stack<state*>* states)
{
	this->initFonts();
	this->window = window;
	this->states = states; //each state will get a pointer to the stack

	this->quit = false;
}



state::~state()
{
	

}

const bool& state::getQuit() const
{
	return this->quit;
	// TODO: insert return statement here
}



void state::endState()
{
	this->quit = true;
}

void state::updateMousePosition()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
