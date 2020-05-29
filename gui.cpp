#include "gui.h"

gui::button::button
(
	float x,
	float y,
	float width, 
	float height, 
	sf::Font* font,
	std::string text,
	sf::Color idleColor, 
	sf::Color hoverColor, 
	sf::Color pressedColor
) : keyTimeMax(1.f), keyTime(keyTimeMax)
{

	this->blocked = false; //default button state
	this->buttonState = BTN_IDLE; //default button state

	
	
	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setOrigin(
		this->shape.getLocalBounds().left + this->shape.getLocalBounds().width / 2.0f,
		this->shape.getLocalBounds().top + this->shape.getLocalBounds().height / 2.0f);
	this->shape.setPosition(sf::Vector2f(x, y));


	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(20);

	//float xPos = (pos.x + button.getLocalBounds().width / 2);
	//float yPos = (pos.y + button.getLocalBounds().height / 2)


	this->text.setOrigin(
		this->text.getLocalBounds().left + this->text.getLocalBounds().width / 2.0f,
		this->text.getLocalBounds().top + this->text.getLocalBounds().height / 2.0f);
	
	this->text.setPosition(
		this->shape.getPosition().x,
		this->shape.getPosition().y
	);
	
	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->pressedColor = pressedColor;

	this->shape.setFillColor(this->idleColor);

}

gui::button::~button() 
{


}


//Accesors
const bool gui::button::isPressed() const
{
	if (this->buttonState == BTN_PRESSED)
		return true;
	
	return false;
}

void gui::button::blockButton()
{
	this->blocked = true;
}

void gui::button::unblockButton()
{
	this->blocked = false;

}

const bool gui::button::getKeyTime()
{

	if (this->keyTime >= this->keyTimeMax)
	{
		this->keyTime = 0.f;
		return true;
	}

	return false;
}

void gui::button::updateKeyTime(const float& dt)
{
	if (this->keyTime < this->keyTimeMax)
	{
		this->keyTime += 10.f * dt;
	}

}





//Methods


void gui::button::update(const sf::Vector2f mousePos, const float& dt)
{
	/*update the booleans for hover and pressed*/

	//Idle
	this->updateKeyTime(dt);
	this->buttonState = BTN_IDLE;
	//Hover
	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = BTN_HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->getKeyTime() && !this->blocked)
		{
			//PRESSED
			this->buttonState = BTN_PRESSED;
		}

	}

	switch (this->buttonState)
	{
	case BTN_IDLE:
		this->shape.setFillColor(this->idleColor);
		break;

	case BTN_HOVER:
		this->shape.setFillColor(this->hoverColor);
		break;

	case BTN_PRESSED:
		this->shape.setFillColor(this->pressedColor);
		break;

	default:
		this->shape.setFillColor(sf::Color::Red);
		break;
	}


}

void gui::button::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->text);
}
