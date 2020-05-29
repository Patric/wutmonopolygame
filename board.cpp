#include "board.h"


//Init methods


void board::initVariables()
{
	this->loadTexture = false; //to change
	
	

}

void board::initTurns() 
{
	this->cTurn = new turn(155,155,this->players, &this->fields);
}

void board::initComponents()
{



}

void board::initTextures()
{

	//should be throw
	sf::Texture temp;
	bool isLoaded;
	isLoaded = temp.loadFromFile("resources/images/sprites/tokens/token.png");
	//std::cout << temp.loadFromFile("resources/images/sprites/tokens/index.jpg") << "\n";
	this->textures["TOKEN_1"] = temp;

}




void board::initFields()
{	
//calculating fields size
	this->corner_f_size = this->defaultShape->getGlobalBounds().height / 7;
	float field_size_x = (this->defaultShape->getSize().x - 2 * corner_f_size) / this->numOfFieldsH;
	float field_size_y = corner_f_size;


	//Right bottom
	this->fields.push_back
	(
		new propertyField
		(
			"Pole naro¿nikowe",
			"To jest opis tego pola",
			static_cast<float>(this->defaultShape->getGlobalBounds().left + this->defaultShape->getGlobalBounds().width - corner_f_size),
			static_cast<float>(this->defaultShape->getGlobalBounds().top + this->defaultShape->getGlobalBounds().height - corner_f_size),
			this->corner_f_size,
			this->corner_f_size,
			0,
			sf::Color::Blue,
			1000.f,
			3000.f,
			200.f,
			//std::map<int, int>* incomePerLevel
			100.f

		)
	);
	this->fields[this->fields.size() - 1]->ID = this->fields.size();


	//bottom
	for (auto i = 0; i < this->numOfFieldsH; i++)
	{
		this->fields.push_back
		(
			new propertyField
			(
				"Pole testowe",
				"To jest opis tego pola",
				static_cast<float>(this->defaultShape->getGlobalBounds().left + this->defaultShape->getGlobalBounds().width - corner_f_size - field_size_x - i * field_size_x),
				static_cast<float>(this->defaultShape->getGlobalBounds().top + this->defaultShape->getSize().y - field_size_y),
				field_size_x,
				field_size_y,
				0,
				sf::Color::Magenta,
				1000.f,
				3000.f,
				200.f,
				//std::map<int, int>* incomePerLevel
				100.f

			)
		);
		this->fields[this->fields.size() - 1]->ID = this->fields.size();
	}

	//Left bottom
	this->fields.push_back
	(
		new propertyField
		(
			"Pole naro¿nikowe",
			"To jest opis tego pola",
			static_cast<float>(this->defaultShape->getGlobalBounds().left),
			static_cast<float>(this->defaultShape->getGlobalBounds().top + this->defaultShape->getGlobalBounds().height - corner_f_size),
			this->corner_f_size,
			this->corner_f_size,
			0,
			sf::Color::Blue,
			1000.f,
			3000.f,
			200.f,
			//std::map<int, int>* incomePerLevel
			100.f

		)
	);
	this->fields[this->fields.size() - 1]->ID = this->fields.size();

	//Left column
	for (unsigned int i = 0; i < this->numOfFieldsV; i++)
	{

		this->fields.push_back
		(
			new propertyField
			(
				"Pole testowe",
				"To jest opis tego pola",
				static_cast<float>(this->defaultShape->getGlobalBounds().left + field_size_y),
				static_cast<float>(this->defaultShape->getGlobalBounds().top + this->defaultShape->getGlobalBounds().height - corner_f_size - field_size_x - i * field_size_x),
				field_size_x,
				field_size_y,
				90,
				sf::Color::Magenta,
				1000.f,
				3000.f,
				200.f,
				//std::map<int, int>* incomePerLevel
				100.f
			)
		);
		this->fields[this->fields.size() - 1]->ID = this->fields.size();
		//std::cout << this->fields.at(3)->ID << "\n";
	}
	


	//Left top
	this->fields.push_back
	(
		new propertyField
		(
			"Pole naro¿nikowe",
			"To jest opis tego pola",
			static_cast<float>(this->defaultShape->getGlobalBounds().left),
			static_cast<float>(this->defaultShape->getGlobalBounds().top),
			this->corner_f_size,
			this->corner_f_size,
			0,
			sf::Color::Blue,
			1000.f,
			3000.f,
			200.f,
			//std::map<int, int>* incomePerLevel
			100.f

		)
	);
	this->fields[this->fields.size()-1]->ID = this->fields.size();


	//top
	for (auto i = 0; i < this->numOfFieldsH; i++)
	{
		this->fields.push_back
		(
			new propertyField
			(
				"Pole testowe",
				"To jest opis tego pola",
				static_cast<float>(this->defaultShape->getGlobalBounds().left + corner_f_size + i * field_size_x),
				static_cast<float>(this->defaultShape->getGlobalBounds().top),
				field_size_x,
				field_size_y,
				0,
				sf::Color::Magenta,
				1000.f,
				3000.f,
				200.f,
				//std::map<int, int>* incomePerLevel
				100.f

			)
		);
		this->fields[this->fields.size() - 1]->ID = this->fields.size();
	}




	//Right top
	this->fields.push_back
	(
		new propertyField
		(
			"Pole naro¿nikowe",
			"To jest opis tego pola",
			static_cast<float>(this->defaultShape->getGlobalBounds().left + this->defaultShape->getGlobalBounds().width - corner_f_size),
			static_cast<float>(this->defaultShape->getGlobalBounds().top),
			this->corner_f_size,
			this->corner_f_size,
			0,
			sf::Color::Blue,
			1000.f,
			3000.f,
			200.f,
			//std::map<int, int>* incomePerLevel
			100.f

		)
	);
	this->fields[this->fields.size() - 1]->ID = this->fields.size();

	//Right column

	for (auto i = 0; i < this->numOfFieldsV; i++)
	{
		this->fields.push_back
		(
			new propertyField
			(
				"Pole testowe",
				"To jest opis tego pola",
				static_cast<float>(this->defaultShape->getGlobalBounds().left + this->defaultShape->getSize().x - field_size_y),
				static_cast<float>(this->defaultShape->getGlobalBounds().top + corner_f_size + field_size_x + i * field_size_x),
				field_size_x,
				field_size_y,
				-90,
				sf::Color::Magenta,
				1000.f,
				3000.f,
				200.f,
				//std::map<int, int>* incomePerLevel
				100.f

			)
		);
		this->fields[this->fields.size() - 1]->ID = this->fields.size();
	}
	

	////Rtight column
	for (auto &it : this->fields)
	{
		std::cout << it->ID << "\n";
		it->initTokenSlots();
	};
	std::cout << this->fields.at(3)->ID << "\n";
}

void board::initTokens()
{

	/*this->tokenTest = new token
	(
		this->fields.at(0)->tokenSlots[1].x, 
		this->fields.at(0)->tokenSlots[1].y, 
		&this->textures["TOKEN_1"]
	);*/

	//this->tokenTest->currentFieldID = 1;


	auto i = 0;
	for (i = 0; i < this->players->size(); i++)
	{
		this->players->at(i)->createToken
		(
			this->fields.at(0)->getTokenSlot().x,
			this->fields.at(0)->getTokenSlot().y,
			&this->textures["TOKEN_1"]
		);
		//this->players->push_back(new player(testIP, unsigned int playerId, sf::Color color));
	}


}

sf::Texture board::loadBTexture(std::string location)
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







board::board(float x, float y, float width, float height, std::vector<player*>* players, sf::Color boardColor)
{
	this->initTextures();
	this->initVariables();
	this->createRect(width, height, boardColor, 0);
	this->setPosition(x, y);
	this->initFields();
	this->players = players;
	this->initTokens();
	this->initTurns();


	//this->players->at(0)->isActive = true;//for debug
}



board::~board()
{
	for (auto i = 0; i < this->numOfFields; i++)
	{
		delete this->fields[i];

	}
	delete this->cTurn;
	

}

void board::render(sf::RenderTarget* target)
{
	if (this->loadTexture && this->sprite)
	{
		target->draw(*this->sprite);
	}
	else
	{
		target->draw(*this->defaultShape);
	}

	
	for (auto i = 0; i < this->numOfFields; i++)
	{
		this->fields[i]->render(target);

	}

	//Rendering tokens
	sf::Text tokenText; //Debug
	for (auto i = 0; i < this->players->size(); i++)
	{
		this->players->at(i)->playerToken->render(target);


		tokenText.setPosition(this->players->at(i)->playerToken->sprite->getPosition().x - 30, this->players->at(i)->playerToken->sprite->getPosition().y + 35);
		tokenText.setFont(this->font);
		tokenText.setCharacterSize(13);
		tokenText.setFillColor(sf::Color::Black);

		std::stringstream ss;
		ss << "Field ID " << this->players->at(i)->playerToken->currentFieldID;

		tokenText.setString(ss.str());

		target->draw(tokenText);
		this->cTurn->render(target);


	}

	





}

void board::update(const float& dt, sf::Vector2f mousePos)
{
	//this->tokenTest->update(dt);
	this->cTurn->update(dt, mousePos);
	
	//FOR DEBUG
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->cTurn->moveToken(this->players->at(0)->playerToken,1);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->cTurn->moveToken(this->players->at(0)->playerToken, -1);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->cTurn->moveToken(this->players->at(1)->playerToken, 1);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->cTurn->moveTokenToID(this->players->at(1)->playerToken, 15);





}


