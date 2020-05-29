#include "token.h"

//Initialisation methods
void token::initVariables()
{


}

void token::initComponents()
{
	//this->createSprite(this->texture);

}



//Constructors / Destructors
token::token(float x, float y, sf::Texture* texture)
{	
	this->initVariables();
	this->initComponents();

	this->createSprite(texture);
	this->setPosition(x, y);
}

token::~token()
{


}

void token::update(const float& dt)
{

}
