#pragma once
#include "field.h"
#include "gui.h"

class propertyField :
	public field
	/*!
* Pole w³asnoœci mo¿liwej do nabycia. Zawiera definicjê onStepAction wyœwietlaj¹c¹ panel z opcjami dotycz¹cymi pola.
	*/
{

private:
	float price;
	float mortgage;
	std::string info;
	int numOfUpgrades;
	//std::map<int, int>* levelPrices; //irregular level prices <level, price>
	//std::map<int, int>* incomePerLevel; //first income then level
	player* owner;
	int dIncome;
	int currentUpgradeLevel;
	int dLevelPrice; //delta level price
	gui::menu* menu;

	
	void showOwnersMenu();
	void showBuyersMenu();
	void updateMenu(const float& dt, sf::Vector2f mousePos);
public:

	propertyField
	(
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
	);

	//Init methods
	void initVariables();


	//Field actions
	void onStepAction(player* playerOnField);
	void buyField(player* newOwner);
	

	//update methods

	void update(const float& dt, sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);


	//render methods

	virtual ~propertyField();
};

