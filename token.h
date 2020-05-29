#pragma once
#include "entity.h"

class token :
	public entity
{

private:
	//Variables


	//Initialisation methods
	void initVariables();
	void initComponents();



public:
	int currentFieldID;
	token(float x, float y, sf::Texture* texture);
	virtual ~token();

	void update(const float& dt);
	
	//Methods


};

