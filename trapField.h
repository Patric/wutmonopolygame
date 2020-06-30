#pragma once
#include "field.h"
class trapField :
    public field
	/*!
* Pole pu³apka. Pobiera pieni¹dze od gracza po wst¹pieniu na nie. Atrybut tax okreœla wielkoœæ kary pieniê¿nej.
	*/
{	

private:
	float tax;


public:
	trapField
	(
		std::string fieldTitle,
		std::string fieldDescription,
		float x,
		float y,
		float width,
		float height,
		int rotation,
		sf::Color color,
		float tax
	);
	virtual ~trapField();

	void onStepAction(player* playerOnField);

	//void update(const float& dt);


};

