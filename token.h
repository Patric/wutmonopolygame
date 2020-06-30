#pragma once
#include "entity.h"

class token :
	public entity
	/*!
* Klasa tokena gracza. Zwi¹zana z graczem. Podklasa entity, która wykorzystujê czêœæ encji zwi¹zan¹ z tekstur¹.
	*/
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

