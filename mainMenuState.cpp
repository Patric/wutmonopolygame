#include "mainMenuState.h"

//Initialisation
void mainMenuState::initBackground()
{
	this->background.setSize
	(
		sf::Vector2f
		(
			static_cast<float>(this->window->getSize().x),
			static_cast<float>(this->window->getSize().y)
		)
	);

	if (!this->backgroundTexture.loadFromFile("resources/images/menu/menuBackground.jpg")) 
	{
		//throw"ERROR::MAINMENUSTATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
	this->background.setTexture(&this->backgroundTexture);

}

void mainMenuState::initVariables()
{


}

void mainMenuState::initButtons()
{

	this->buttons["GAME_STATE_BTN"] = new gui::button
	(
		window->getSize().x / 2.f - window->getSize().x / 3.f,
		window->getSize().y / 2.f - 50, 
		250, //width
		75, //height
		&this->font,
		"New Game",
		sf::Color(70, 70, 70, 200), //idle
		sf::Color(150, 150, 150, 255), //hover
		sf::Color(70, 70, 70, 200) //pressed
	);

	this->buttons["SETTINGS_BTN"] = new gui::button
	(
		window->getSize().x / 2.f - window->getSize().x / 3.f, //x axis
		window->getSize().y / 2.f + 50, //y axis
		250,
		75,
		&this->font,
		"Settings",
		sf::Color(70, 70, 70, 200), //idle
		sf::Color(150, 150, 150, 255), //hover
		sf::Color(100, 100, 100, 200) //pressed
	);


	this->buttons["EXIT_STATE_BTN"] = new gui::button
	(
		window->getSize().x / 2.f - window->getSize().x / 3.f, //x axis
		window->getSize().y / 2.f + 150, //y axis
		250, 
		75, 
		&this->font,
		"Quit",
		sf::Color(70, 70, 70, 200), //idle
		sf::Color(150, 150, 150, 255), //hover
		sf::Color(100, 100, 100, 200) //pressed
	);

}

mainMenuState::mainMenuState(sf::RenderWindow* window, std::stack<state*>* states)
		: state(window, states)
	{
	//this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	//this->background.setFillColor(sf::Color::Magenta);

	this->initVariables();
	this->initBackground();
	this->initButtons();

	

	}



mainMenuState::~mainMenuState()
	{
	auto i = this->buttons.begin(); //puts iterator at the beggining

	for (i = this->buttons.begin(); i != this->buttons.end(); ++i) 
		{ //++i faster than i++

		delete i->second;

		}

	}


	void mainMenuState::updateInput(const float& dt)
	{
		//this->checkForQuit();

	}

	void mainMenuState::updateButtons(const float& dt)
	{
		/*updates all buttons and handles their functionality*/
		for (auto &i : this->buttons) 
		{
			i.second->update(this->mousePosView, dt);
		}


		//New game
		if (this->buttons["GAME_STATE_BTN"]->isPressed())
		{

			/*we push the state in stack from inside the stack since
			we're rendering the state on top of the stack. We need a pointer to itself*/
			//we send the stack to the next state we're pushing
			this->states->push(new gameState(this->window, this->states));
		}

		//Quit the game
		if (this->buttons["EXIT_STATE_BTN"]->isPressed())
		{
			this->endState();
		}

	}

	void mainMenuState::update(const float& dt)
	{
		this->updateMousePosition();
		this->updateInput(dt);

		this->updateButtons(dt);


	

		//std::cout << this->mousePosWindow.x << " " << this->mousePosWindow.y << "\n";
		//this->gamestate_btn->update(this->mousePosView);
	}

	void mainMenuState::render(sf::RenderTarget* target)
	{
		target->draw(this->background);

		this->renderButtons(target);


		//REMOVE LATER
		/*sf::Text mouseText;
		mouseText.setPosition(this->mousePosView.x - 25, this->mousePosView.y + 25);
		mouseText.setFont(this->font);
		mouseText.setCharacterSize(12);
		
		std::stringstream ss;
		ss << mousePosView.x << " " << this->mousePosView.y;;

		mouseText.setString(ss.str());

		target->draw(mouseText);*/
			//this->pawn.render(target);
	}

	void mainMenuState::renderButtons(sf::RenderTarget* target)
	{
		//this->gamestate_btn->render(target);
		for (auto& i : this->buttons)
		{
			i.second->render(target);

		}

		
	}
