#pragma once
#include "field.h"


class propertyField :
	public field
{
private:
	float price;
	float mortgage;
	std::string info;
	int numOfUpgrades;
	//std::map<int, int>* levelPrices; //irregular level prices <level, price>
	//std::map<int, int>* incomePerLevel; //first income then level
	int dIncome;
	int currentUpgradeLevel;
	int dLevelPrice; //delta level price

public:
	//player* owner;

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


	//update methods

	void update(const float& dt);



	//render methods

	virtual ~propertyField();
};

