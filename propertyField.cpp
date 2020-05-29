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
//	delete this->fieldType;
	//delete this->fieldType;
	//delete this->fieldDescription;
}

//Init methods
void propertyField::initVariables()
{
	this->currentUpgradeLevel = 0;
	this->numOfUpgrades = 6;


}

//Update

void propertyField::update(const float& dt)
{




}


//Render
//void propertyField::render(sf::RenderTarget* target)
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

	







