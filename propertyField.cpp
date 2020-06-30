#include "propertyField.h"

propertyField::propertyField(
	std::string fieldTitle,
	std::string fieldDescription,
	float x,
	float y,
	float width,
	float height,
	int rotation,
	sf::Color color,
	float price,
	float mortgage,
	int dLevelPrice,
	//std::map<int, int>* incomePerLevel
	int dIncome
	
	//Part of those methods move to field class later
)
{
	//Initiating variables
	//this->initVariables();

		/*!
* Tworzy pole w danym miejscu z domyœlnymi parametrami. 
	*/
	this->currentUpgradeLevel = 0;
	this->numOfUpgrades = 6;
	this->owner = NULL;
	this->color = color;
	this->mortgage = mortgage;
	this->dLevelPrice = dLevelPrice;
	this->dIncome = dIncome;

	//Creating rectangles and changing defaults
	this->createRect(width, height, sf::Color(252, 250, 187, 255), 0);
	this->defaultShape->setPosition(x, y);
	this->defaultShape->setOutlineColor(sf::Color(150, 149, 111, 200));
	this->defaultShape->setOutlineThickness(1);
	

	//Creating titleBar and changing defaults
	this->createAndSetTitleBar();
	this->titleBar->setOutlineColor(sf::Color(150, 149, 111, 200)); //changing default value



	//Setting Text
	this->scaleFonts();
	//default not rendered in field card
	//this->fieldType = new sf::Text;
	//this->setFieldText(this->fieldType, x, y, rotation, this->font, this->fontSize[SMALL_FONT], sf::Color::Black, "Property field");



	this->fieldTitle = new sf::Text;
	this->setFieldText(this->fieldTitle, x, y, rotation, this->font, this->fontSize[BIG_FONT], sf::Color::Black, fieldTitle);
	

	//this->fieldDescription = new sf::Text;
	//this->setFieldText(this->fieldTitle, x, y, rotation, this->font, this->fontSize[MEDIUM_FONT], sf::Color::Black, fieldTitle);




		
}


propertyField::~propertyField()
{
	delete this->fieldTitle;
	if (this->menu)
		delete(this->menu);
//	delete this->fieldType;
	//delete this->fieldType;
	//delete this->fieldDescription;
}

//Init methods
void propertyField::initVariables()
{
	this->currentUpgradeLevel = 0;
	this->numOfUpgrades = 6;
	this->owner = NULL;
	this->color = color;
	this->mortgage = mortgage;
	this->dLevelPrice = dLevelPrice;
	this->dIncome = dIncome;
}

//Update

void propertyField::update(const float& dt, sf::Vector2f mousePos)
{
	//if "leave" is clicked charge
	//delete menu after button is clicked
	if (this->menu) 
	{
		this->updateMenu(dt, mousePos);
	}
	
}

void propertyField::updateMenu(const float& dt, sf::Vector2f mousePos)
{
	/*!
* Aktualizuje stan menu dla danego pola. Usuwa menu w momencie wciœniêcia przycisku Leave. Ustawia w³aœciciela w momencie wciœniêcia "Buy".
	*/
	this->menu->update(mousePos, dt);

	for (auto i: this->menu->buttons) 
	{
		if (i->isPressed()) 
		{
			//Owner's menu
			if (i->text.getString() == "Upgrade") 
			{

			}
			else if (i->text.getString() == "Sell") 
			{

			}
			else if (i->text.getString() == "Mortgage")
			{

			}
			//Buyer's menu
			else if(i->text.getString() == "Buy")
			{
				this->buyField(this->playerOnField);
				i->blockButton();
				this->onStepAction(this->playerOnField);
			}
			else if (i->text.getString() == "Leave")
			{
				if (this->playerOnField != this->owner) {
					this->chargePlayer(this->playerOnField, this->dIncome);
				}

				delete this->menu;
				this->menu = nullptr;
				break;

			}
			else
			{
				
			}

		}
		else if (this->playerOnField->playerToken->currentFieldID != this->ID)
		{
			delete this->menu;
			this->menu = nullptr;
			break;
		}

	}



}

void propertyField::onStepAction(player* playerOnField)
{
	/*!
* W zale¿noœci od tego, czy gracz jest w³aœcicielem, potencjalnym nabywc¹, czy klientem przeprowadza ró¿ne akcje.
Wyœwietla ró¿ne menu dla kupuj¹cego, lub w³aœciciela, a dla ¿adnego z nich wywo³uje metodê chargePlayer pobieraj¹c op³atê równ¹ atrybutowi income.
	*/
	this->playerOnField = playerOnField;

	if (playerOnField == this->owner)
	{
		//show owner's menu
		this->showOwnersMenu();
	}
	else if (this->owner == NULL)
	{
		//show buyer's menu
		//ask to buy this field or leave
		this->showBuyersMenu();
	}
	else
	{
		this->chargePlayer(playerOnField, dIncome);
		if (this->owner)
			this->owner->wallet = this->owner->wallet + dIncome;
		//don't show menu
	}

	//std::cout << "Stepped on field " << this->ID << " !" << "\n";

}

void propertyField::showOwnersMenu() 
{
	/*!
* Wyœwietla opcje w³aœciciela.
	*/

	this->menu = new gui::menu(
		1700,
		500,
		std::vector<std::string>{ "Upgrade", "Sell", "Mortgage", "Leave"},
		&this->font
	);
}



void propertyField::showBuyersMenu()
{
	/*!
* Wyœwietla opcje kupowania.
	*/
	this->menu = new gui::menu(
		1700,
		500,
		std::vector<std::string>{ "Buy", "Leave"},
		&this->font
	);



}

void propertyField::buyField(player* newOwner)
{
	/*!
* Zmienia w³aœciciela niezakupionego pola i pobiera op³atê.
	*/
	this->owner = newOwner;
	this->chargePlayer(this->owner, this->price);
}



//Render

void propertyField::render(sf::RenderTarget* target)
{		/*!
* Jeœli istnieje menu to renderuje menu i pole. Jeœli nie to tylko pole.
	*/

	//Calling base class method
	this->field::render(target);
	if (this->menu) 
	{
		this->menu->render(target);
	}
	
	
}

//Render
//
//{
//	if (this->loadTexture && this->sprite)
//	{
//		target->draw(*this->sprite);
//	}
//	else
//	{
//		target->draw(*this->defaultShape);
//		target->draw(this->fieldTitle);
//
//	}

	







