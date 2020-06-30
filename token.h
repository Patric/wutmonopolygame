#pragma once
#include "entity.h"

class token :
	public entity
	/*!
* Klasa tokena gracza. Zwi�zana z graczem. Podklasa entity, kt�ra wykorzystuj� cz�� encji zwi�zan� z tekstur�.
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

