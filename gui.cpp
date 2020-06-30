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
	/*!
* Tworzy przycisk z zadanych parametrów. Domyœlnie nie jest zablokowany.
	*/

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
{	/*!
* Sprawdza stan wciœniêcia przycisku.
	*/
	if (this->buttonState == BTN_PRESSED)
		return true;
	
	return false;
}

void gui::button::blockButton()
{
	/*!
* Blokuje przycisk, zmieniaj¹c flagê blocked na true
	*/
	this->blocked = true;
}

void gui::button::unblockButton()
{
	/*!
* IOdblokowuje przycisk poprzez zmianê flagi blocked na false.
	*/
	this->blocked = false;

}

const bool gui::button::getKeyTime()
{
	/*!
* Pobiera aktualny czas przycisku.
	*/

	if (this->keyTime >= this->keyTimeMax)
	{
		this->keyTime = 0.f;
		return true;
	}

	return false;
}

void gui::button::updateKeyTime(const float& dt)
{
	/*!
* Aktualizuje czas przycisku. Pozwala na unikniêcie wielokliku przy d³u¿szym przytrzymaniu myszy.
	*/
	if (this->keyTime < this->keyTimeMax)
	{
		this->keyTime += 10.f * dt;
	}

}

//Methods
void gui::button::update(const sf::Vector2f mousePos, const float& dt)
{
	/*!
* IAktualizuje stan przycisku. Sprawdza, czy kursor jest nad przyciskiem, czy jest wciœniêty, zablokowany.
	*/

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


//----------------------------------------------------
gui::infoBar::infoBar(float x, float y, float width, float height, sf::Color color, sf::Font* font)
{
	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setFillColor(color);
	this->font = font;
	this->initPositions();

}

gui::infoBar::~infoBar()
{
	auto i = 0;
	for (i = 0 ; i < this->infos.size(); i++)
	{
		delete this->infos.back();
		this->infos.pop_back();
	}

}

void gui::infoBar::initPositions()
{
	/*!
* Inicjalizuje sloty dla informacji. Trzy mo¿liwoœci: lewo, œrodek, prawo.
	*/
	this->positions["Left"] = sf::Vector2f
	(
		this->shape.getGlobalBounds().left + 0.2 * this->shape.getSize().x,
		this->shape.getGlobalBounds().top + 0.5 * this->shape.getGlobalBounds().height //+ 0.2 * this->shape.getSize().y
	);

	this->positions["Center"] = sf::Vector2f
	(
		this->shape.getGlobalBounds().left + 0.5 * this->shape.getSize().x,
		this->shape.getGlobalBounds().top + 0.5 * this->shape.getGlobalBounds().height
	);

	this->positions["Right"] = sf::Vector2f
	(
		this->shape.getGlobalBounds().left + 0.8 * this->shape.getSize().x,
		this->shape.getGlobalBounds().top + 0.5 * this->shape.getGlobalBounds().height
	);


}

void gui::infoBar::addInfo(std::string position_name, std::string text)
{
	/*!
* Dodaje now¹ informacjê do przycisku do nastêpnego wolnego slotu na danej pozycji.
	*/
	this->infos.push_back(new sf::Text);
	this->infos.back()->setString(text);
	this->infos.back()->setFont(*this->font);
	this->infos.back()->setOrigin(
		this->infos.back()->getLocalBounds().left + this->infos.back()->getLocalBounds().width / 2.0f,
		this->infos.back()->getLocalBounds().top + this->infos.back()->getLocalBounds().height / 2.0f);

	this->infos.back()->setPosition(this->positions[position_name]);
	this->positions[position_name] = sf::Vector2f
	(
		this->positions[position_name].x,
		this->positions[position_name].y + this->shape.getSize().y * 0.1
	);

}

void gui::infoBar::updateInfo(std::string text, unsigned int index)
{
	this->infos.at(index)->setString(text);

}


void gui::infoBar::render(sf::RenderTarget* target)
{
	target->draw(this->shape);

	auto i = 0;
	for(i = 0; i < this->infos.size(); i++)
	{
		target->draw(*this->infos.at(i));
	}


	/*sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x - 25, this->mousePosView.y + 25);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(12);

	std::stringstream ss;
	ss << mousePosView.x << " " << this->mousePosView.y;;

	mouseText.setString(ss.str());

	target->draw(mouseText);*/






}

//----------------------------------------------------

gui::menu::menu(float x, float y, std::vector<std::string> buttonNames, sf::Font* font)
{
	/*!
* Tworzy przyciski z podanego wektora nazw przycisków. Umieszcza je jeden pod drugim.
	*/
	for (auto i = 0; i < buttonNames.size(); i++)
	{

		float width = 200;
		float height = 70;

		this->buttons.push_front(new button
		(
			x,
			y,
			width,
			height,
			font,
			buttonNames[i],
			sf::Color(70, 70, 70, 200), //idle
			sf::Color(150, 150, 150, 255), //hover
			sf::Color(70, 70, 70, 200) //pressed
		));
		y += height;

	}

}

gui::menu::~menu()
{

	for (auto i = 0; !this->buttons.empty(); i++)
	{
		delete this->buttons.front();
		this->buttons.pop_front();
	}


}

void gui::menu::update(sf::Vector2f mousePos, const float& dt)
{
	for (auto i : this->buttons)
	{
		i->update(mousePos, dt);
	}
}

void gui::menu::render(sf::RenderTarget* target)
{
	for (auto i : this->buttons)
	{
		i->render(target);
	}
}
