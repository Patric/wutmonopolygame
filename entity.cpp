#include "entity.h"

void entity::initVariables()
{
	this->texture = NULL;
	this->sprite = NULL;
	this->movementSpeed = 300.f;
	this->loadTexture = true;
	if (!this->font.loadFromFile("fonts/MONOPOLY_INLINE.TTF"));
	{
		//throw("ERROR::BOARD::COULD NOT LOAD FONT"); //tells us what happened
	}

	//Default values
	fontSize[BIG_FONT] = 25; 
	fontSize[MEDIUM_FONT] = 15;
	fontSize[SMALL_FONT] = 9;



}

void entity::scaleFonts()
{



	fontSize[BIG_FONT] = ceil(this->defaultShape->getSize().y / 12); //scales fonts accordingly to entity
	fontSize[MEDIUM_FONT] = ceil(this->defaultShape->getSize().y / 17);
	fontSize[SMALL_FONT] = ceil(this->defaultShape->getSize().y / 26);


}

entity::entity(){

	this->initVariables();
}

entity::~entity(){

	//we don't delete texture since it's from outside
	delete this->sprite;
	delete this->defaultShape;
}


//Component functions
void entity::createSprite(sf::Texture* texture)
{
	this->texture = texture;
	this->sprite = new sf::Sprite(*this->texture);


}

void entity::createRect(float width, float height, sf::Color color, bool originInCenter)
{
	this->defaultShape = new sf::RectangleShape();
	this->defaultShape->setSize(sf::Vector2f(width, height));
	if (originInCenter)
	{
		this->setOriginInCenter();
	}
	this->defaultShape->setFillColor(color);
}




//Methods
void entity::setPosition(const float x, const float y)
{

	if (this->sprite)
	{
		this->sprite->setPosition(x, y);
	}
	else if (this->defaultShape)
	{
		this->defaultShape->setPosition(x, y);
	}
	

}

void entity::setOriginInCenter()
{
	this->defaultShape->setOrigin(
		this->defaultShape->getLocalBounds().left + this->defaultShape->getLocalBounds().width / 2.0f,
		this->defaultShape->getLocalBounds().top + this->defaultShape->getLocalBounds().height / 2.0f);

}



void entity::move(const float& dt, const float dir_x, const float dir_y)
{
	if (this->sprite)
	{
		this->sprite->move(dir_x * this->movementSpeed * dt, dir_y * this->movementSpeed * dt);
	}
}


void entity::update(const float& dt)

{

}

void entity::render(sf::RenderTarget* target)
{
	if (this->loadTexture && this->sprite)
	{
		target->draw(*this->sprite);
	}
	else
	{
		target->draw(*this->defaultShape);
	}

	

}
