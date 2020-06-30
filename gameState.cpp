#include "gameState.h"


//Initialisation methods

void gameState::initBackground()
{
	/*!
* Metoda odpowiadaj¹ca za inicjaliacjê t³a.
	*/
	this->background.setSize
	(
		sf::Vector2f
		(
			static_cast<float>(this->window->getSize().x),
			static_cast<float>(this->window->getSize().y)
		)
	);

	if (!this->backgroundTexture.loadFromFile("resources/images/gameState/gameStateBackground.jpg"))
	{
		this->background.setFillColor(sf::Color(163, 5, 60, 255));
	}
	else
	{
		this->background.setTexture(&this->backgroundTexture);
	}



}


void gameState::initTextures()
{
	//should be throw
	sf::Texture temp;
	bool isLoaded;
	//isLoaded = temp.loadFromFile("resources/images/sprites/tokens/token.png");
	//std::cout << temp.loadFromFile("resources/images/sprites/tokens/index.jpg") << "\n";
	//this->textures["TOKEN_IDLE"] = temp;
}


void gameState::initBoard()
{
	/*!
* Inicjalizujê planszê. Ustala rozmiar w zale¿noœci od rozdzielczoœci oraz tworzy obiekt planszy.
	*/
	float board_height = this->window->getSize().y * 0.98;
	float board_width = this->window->getSize().y * 0.98;
	

	this->gameStateBoard = new board
	(
		static_cast<float>(this->window->getSize().x  / 2.f - board_width / 2.f), //pos x
		static_cast<float>(this->window->getSize().y / 2.f - board_height / 2.f), //pos y
		static_cast<float>(board_width), //x 
		static_cast<float>(board_height), //y
		&this->players,
		sf::Color::White 	
	);
	
}


void gameState::initPlayers()
{
	/*!
* Inicjalizuje graczy.
	*/

	//for tests
	this->numOfPlayers = 2;
	sf::IpAddress testIP = "127.0.0.1";
	auto i = 0;
	for(i = 0; i < this->numOfPlayers; i++)
	{
		this->players.push_back(new player(testIP, i, sf::Color::Green));
	//this->players->push_back(new player(testIP, unsigned int playerId, sf::Color color));
	}
}


//Constructors / Desturctors
gameState::gameState(sf::RenderWindow* window, std::stack<state*>* states)
	: state(window, states)
{
	this->initBackground();
	this->initTextures();
	this->initPlayers();
	this->initBoard();
}



gameState::~gameState()
{
	
	delete this->gameStateBoard;
	for (auto i = 0; i < this->numOfPlayers; i++)
	{
		delete this->players.at(i);
		//this->players->push_back(new player(testIP, unsigned int playerId, sf::Color color));
	}
}


//Methods


void gameState::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->endState();
	}

}

void gameState::update(const float& dt)
{
	/*!
* Odœwie¿a stan gry co 16.6 milisekund, aktualizuje stan gameStateBoard, czyli planszy oraz wciœniête klawisze.
	*/
	sf::Time t2 = sf::milliseconds(16.6);
	sf::sleep(t2);
	this->updateMousePosition();
	this->updateInput(dt);
	//if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		//std::cout << "gameState updated\n";
	//this->pawn.update(dt);
	//std::cout << this->mousePosWindow.x << " " << this->mousePosWindow.y << "\n";
	this->gameStateBoard->update(dt, this->mousePosView);
	//this->token1->update(dt);
}

void gameState::render(sf::RenderTarget* target)
{
	/*!
* W wersji debug zawiera pozycjê kursora myszy. Wyœwietla planszê gry i elementy z ni¹ zwi¹zane.
	*/


	target->draw(this->background);
	this->gameStateBoard->render(target);
		//this->pawn.render(target);
	//this->token1->render(target);
	//REMOVE LATER
	sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x - 25, this->mousePosView.y + 25);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(12);

	std::stringstream ss;
	ss << mousePosView.x << " " << this->mousePosView.y;;

	mouseText.setString(ss.str());

	target->draw(mouseText);
	//this->pawn.render(target);


	
}
