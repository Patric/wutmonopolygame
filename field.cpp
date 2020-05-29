#include "field.h"




field::field()
{
	this->loadTexture = false; //default variable
	if (!this->font.loadFromFile("fonts/MONOPOLY_INLINE.TTF"));
	{
		//throw("ERROR::BOARD::COULD NOT LOAD FONT"); //tells us what happened
	}

	fontSize[BIG_FONT] = 20; //scales fonts accordingly to board size. 
	fontSize[MEDIUM_FONT] = 14;
	fontSize[SMALL_FONT] = 9;
	this->cnt = 0;
}

field::~field()
{
	if(this->titleBar)
		delete this->titleBar;
	
}

void field::createAndSetTitleBar()
{
	this->titleBar = new sf::RectangleShape;
	this->titleBar->setSize
	(
		sf::Vector2f
		(
			static_cast<float>(this->defaultShape->getSize().x),
			static_cast<float>(this->defaultShape->getSize().y * 0.25)
		)
	);
	this->titleBar->setFillColor(this->color);
	this->titleBar->setPosition
	(
		this->defaultShape->getGlobalBounds().left,
		this->defaultShape->getGlobalBounds().top
	);
	this->titleBar->setOutlineColor(sf::Color(150, 149, 111, 200)); //defalt value
	this->titleBar->setOutlineThickness(1);
	

}

void field::setFieldText(sf::Text* fieldText, float x, float y, int rotation, sf::Font font, int fontSize, sf::Color color, std::string text)
{	

	fieldText->setString(text);
	fieldText->setFont(this->font);
	fieldText->setCharacterSize(fontSize);
	fieldText->setFillColor(color);

	if (rotation == 90)
	{
		fieldText->setPosition
		(
			sf::Vector2f
			(
				x,
				y + this->titleBar->getSize().x / 2.f - fieldText->getLocalBounds().width / 2.f
			)
		);

		this->defaultShape->setRotation(rotation);
		this->titleBar->setRotation(rotation);
		fieldText->setRotation(rotation);


	}
	else if (rotation == -90)
	{
		fieldText->setPosition
		(
			sf::Vector2f
			(
				x,
				y - this->titleBar->getSize().x / 2.f + fieldText->getLocalBounds().width / 2.f
			)
		);

		this->defaultShape->setRotation(rotation);
		this->titleBar->setRotation(rotation);
		fieldText->setRotation(rotation);


	}
	else
	{
		fieldText->setPosition
		(
			sf::Vector2f
			(
				x + this->titleBar->getSize().x / 2.f - fieldText->getLocalBounds().width / 2.0f,
				y + this->titleBar->getSize().y / 2.f - fieldText->getLocalBounds().height
			)
		);

	}
}

void field::chargePlayer(player* playerOnField, int sum)
{
	playerOnField->wallet = playerOnField->wallet - sum;

}

void field::initTokenSlots()
{
	//Center
	float x = this->defaultShape->getGlobalBounds().left + this->defaultShape->getSize().x / 2.f;
	float y = this->defaultShape->getGlobalBounds().top + this->defaultShape->getSize().x / 2.f; // 2.f + this->titleBar->getSize().y / 2.5;
	float k = 0.1;
	std::cout<< x << " " << y << " \n";
	//Central pos
	this->tokenSlots[0] = sf::Vector2f(x,y);
	//Right down
	this->tokenSlots[1] = sf::Vector2f(x + k * this->defaultShape->getSize().x, y + k* this->defaultShape->getSize().x);
	//Right up
	this->tokenSlots[2] = sf::Vector2f(x + k * this->defaultShape->getSize().x, y - k * this->defaultShape->getSize().x);
	//Left down
	this->tokenSlots[3] =  sf::Vector2f(x - k * this->defaultShape->getSize().x, y + k * this->defaultShape->getSize().x);
	//Left up
	this->tokenSlots[4] =  sf::Vector2f(x - k * this->defaultShape->getSize().x, y - k * this->defaultShape->getSize().x);
}

//Render

void field::render(sf::RenderTarget* target)
{
	if (this->loadTexture && this->sprite)
	{
		target->draw(*this->sprite);
	}
	else
	{
		target->draw(*this->defaultShape);
		if (this->titleBar)
		{
			target->draw(*this->titleBar);
		}
		target->draw(*this->fieldTitle);
		
	}
}


void field::update(const float& dt, sf::Vector2f mousePos)
{



}


//Modify later to avoid putting all tokens at one place
sf::Vector2f field::getTokenSlot()
{
	if (this->cnt >= 4)
	{
		std::cout << "cnt: " << cnt << "\n";
		this->cnt = 0;
		return this->tokenSlots[this->cnt + 4];

	}
	else
	{
		this->cnt++;
		std::cout << "cnt: " << cnt - 1 << "\n";
		return this->tokenSlots[this->cnt - 1];
	}


}
