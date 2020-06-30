#include "trapField.h"

trapField::trapField
(
	std::string fieldTitle, 
	std::string fieldDescription, 
	float x, float y, 
	float width, float height, 
	int rotation, 
	sf::Color color, 
	float tax
)
{
	//Initiating variables
	this->color = color;
	this->tax = tax;

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

trapField::~trapField()
{
	delete this->fieldTitle;
}

void trapField::onStepAction(player* playerOnField)
{
	this->chargePlayer(playerOnField, this->tax);
	//std::cout << "Player" << playerOnField->playerId << " charged" << "\n";
}

//void trapField::update(const float& dt)
//{
//}
