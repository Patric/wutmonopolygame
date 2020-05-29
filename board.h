#pragma once
#include "turn.h"
#include "player.h"

class board :
	public entity
{
private:
	
	//std::vector<field*> propertyFields;
	std::vector<field*> fields;
	//token* tokenTest;
	turn* cTurn;
	std::map<std::string, sf::Texture> textures;
	std::vector<player*>* players;

	int numOfFieldsH = 9;
	int numOfFieldsV = 9;
	int numOfFields = (numOfFieldsH + numOfFieldsV) * 2 + 4;
	int numOfTokens;
	float corner_f_size; //for clarity


	//Initialisation methods
	void initVariables(); //
	void initComponents(); //will init all board components
	void initTextures();
	void initFields();
	void initTokens();
	void initTurns();



	//Board textures
	sf::Texture loadBTexture(std::string location);
	//void calculateSlots(int numOfFieldsV, int numOffieldH);

protected:
	


public:
	
	//void moveTokenToID(token* tokenToMove, int fieldID);
	//void moveToken(token* tokenToMove, int numOfFields);

	board(float x, float y, float width, float height, std::vector<player*>* players, const sf::Color boardColor);
	//board(sf::Texture* texture); textures later
	
	
	virtual ~board();
	//Render
	void render(sf::RenderTarget* target);
	void update(const float& dt, sf::Vector2f mousePos);

};

