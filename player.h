#pragma once
#include "token.h"
//#include "propertyField.h"//to change
//#include "propertyField.h" //newesst

class player
{
private:
	sf::IpAddress ipAddress;

public:
	token* playerToken;
	int playerId;
	sf::Text nickname;
	sf::Color color;
	sf::Int64 lastDice;
	int wallet;
	

	player(sf::IpAddress localIpAddress, int playerId, sf::Color color);
	virtual ~player();

	void createToken(float x, float y, sf::Texture* texture);
};

