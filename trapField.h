#pragma once
#include "field.h"
class trapField :
    public field
	/*!
* Pole pu�apka. Pobiera pieni�dze od gracza po wst�pieniu na nie. Atrybut tax okre�la wielko�� kary pieni�nej.
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

