#include "turn.h"

turn::turn(float x, float y, std::vector<player*>* players, std::vector<field*>* fields)
{
	this->fields = fields;
	this->players = players;
	this->moveAvailabe = false;
	this->initButtons();
	this->initDice();
	//for debug
	this->you = this->players->at(1);
	
	//this->queue.emplace_front(this->players->at(0));


}

turn::~turn()
{
	auto i = this->buttons.begin(); //puts iterator at the beggining

	for (i = this->buttons.begin(); i != this->buttons.end(); i++)
	{ //++i faster than i++

		delete i->second;

	}

}

void turn::passTurn()
{
	this->queue.emplace_front(this->queue.back());
	this->queue.pop_back();

	//for debug ---------- delete when network connection is established
	this->you = this->queue.front();
	this->moveAvailabe = true;
	//-------------
}


void turn::setQueue()
{
	//Setting place in the queue
	//To improve. Works with 2 players now

	if (this->queue.size() < this->players->size())
	{

		//actions to set queue

		//for debug
		this->queue.emplace_front(this->players->at(0));
		this->queue.emplace_front(this->players->at(1));
	
	}
}

void turn::updateYourTurn(const float& dt, sf::Vector2f mousePos)
{

	this->setQueue();
	this->updateButtons(mousePos, dt);
	if (this->queue.front() == this->you)
	{

		//time limit later


		

		
	
	}

}


void turn::waitForTurn()
{
	//listening for turn to come

	if (this->moveAvailabe)
	{
		this->buttons["ROLL_DICE_BTN"]->unblockButton();
	}


}

void turn::render(sf::RenderTarget* target)
{
	/*if (this->loadTexture && this->sprite)
	{
		target->draw(*this->sprite);
	}
	else
	{
		target->draw(*this->defaultShape);
	}*/
	this->renderButtons(target);
	this->renderDice(target);

}


void turn::update(const float& dt, sf::Vector2f mousePos)
{
	this->waitForTurn();
	this->updateYourTurn(dt, mousePos);
	//update other players turn -> info from network
	//update other actions that are not in this turn accepting offers etc.
}

void turn::initButtons()
{
	this->buttons["ROLL_DICE_BTN"] = new gui::button
	(
		150,
		150,
		250, //width
		75, //height
		&this->font,
		"ROLL DICE",
		sf::Color(70, 70, 70, 200), //idle
		sf::Color(150, 150, 150, 255), //hover
		sf::Color(70, 70, 70, 200) //pressed
	);

	this->buttons["END_TURN_BTN"] = new gui::button
	(
		150, //x axis
		300, //y axis
		250,
		75,
		&this->font,
		"END TURN",
		sf::Color(70, 70, 70, 200), //idle
		sf::Color(150, 150, 150, 255), //hover
		sf::Color(100, 100, 100, 200) //pressed
	);


}

void turn::initDice()
{
	this->dots.setString("Waiting for players...");
	this->dots.setFont(this->font);
	this->dots.setCharacterSize(40);
	this->dots.setPosition(150, 50);

}

void  turn::updateButtons(sf::Vector2f mousePosView, const float& dt)
{
	/*updates all buttons and handles their functionality*/
	for (auto& i : this->buttons)
	{
		i.second->update(mousePosView, dt);
	}

	
	
	if (this->buttons["ROLL_DICE_BTN"]->isPressed())
	{
		this->buttons["ROLL_DICE_BTN"]->blockButton();
		this->updateDice();

		if (this->queue.size() == this->players->size()) //move only when the queue is already set
		{
			this->moveToken(this->you->playerToken, dice);
			this->fields->at(this->you->playerToken->currentFieldID)->onStepAction(this->you); //Field action on Player
			
		}
		//automatically block button
		this->buttons["END_TURN_BTN"]->unblockButton();
		this->moveAvailabe = false;
	}

	if (this->buttons["END_TURN_BTN"]->isPressed())
	{
		this->buttons["END_TURN_BTN"]->blockButton();
		this->passTurn();
	
	
	}


}

void  turn::renderButtons(sf::RenderTarget* target)
{
	//this->gamestate_btn->render(target);
	for (auto& i : this->buttons)
	{
		i.second->render(target);

	}


}

void turn::renderTurnInfo(sf::RenderTarget* target)
{


}

void turn::updateTurnInfo(const float& dt)
{


}


void turn::renderDice(sf::RenderTarget* target)
{
	std::stringstream ss;
	ss << this->dice;
	this->dots.setString(ss.str());

	target->draw(this->dots);
}

void turn::updateDice()
{
	srand(time(NULL));
	//Generating random number form 1 to 6
	this->dice = rand() % 6 + 1;
	//this->activePlayer->lastDice = this->dice;
}

//tokentomove will be be this->Player_id->token->mmoveToID
void turn::moveTokenToID(token* tokenToMove, int fieldID)
{


	tokenToMove->setPosition(
		this->fields->at(fieldID)->getTokenSlot().x,
		this->fields->at(fieldID)->getTokenSlot().y
	);
	tokenToMove->currentFieldID = fieldID;

}

void turn::moveToken(token* tokenToMove, int numOfFields)
{
	auto i = 0;
	for (i = 0; i < abs(numOfFields); i++)
	{


		if (tokenToMove->currentFieldID + (numOfFields / numOfFields) > 39)
		{
			tokenToMove->setPosition
			(
				this->fields->at(0)->getTokenSlot().x,
				this->fields->at(0)->getTokenSlot().y
			);

			tokenToMove->currentFieldID = 0;


		}
		else if ((tokenToMove->currentFieldID + (numOfFields / numOfFields) < 0))
		{

			tokenToMove->setPosition
			(
				this->fields->at(39)->getTokenSlot().x,
				this->fields->at(39)->getTokenSlot().y
			);

			tokenToMove->currentFieldID = 40;
		}
		else
		{
			tokenToMove->setPosition
			(
				this->fields->at(tokenToMove->currentFieldID + (numOfFields / numOfFields))->getTokenSlot().x,
				this->fields->at(tokenToMove->currentFieldID + (numOfFields / numOfFields))->getTokenSlot().y
			);
			tokenToMove->currentFieldID = tokenToMove->currentFieldID + (numOfFields / numOfFields);
			
		}

	}



}
