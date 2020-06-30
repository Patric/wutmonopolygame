#include "player.h"

player::player(sf::IpAddress localIpAddress, int playerId, sf::Color color)
	:lastDice(0), wallet(1000)
{
	/*!
* Tworzy nowego gracza z zadanym id, adresep ip, a tak¿e przydzielonym mu kolorem.
	*/
	this->ipAddress = localIpAddress;
	this->playerId = playerId;
	this->color = color;
	

}

player::~player()
{
	if(this->playerToken)
		delete this->playerToken; 
}

void player::createToken(float x, float y, sf::Texture* texture)
{	/*!
* Tworzy token dla gracza w okreœlonym miejscu.
	*/

	this->playerToken = new token
	(
		x,
		y,
		texture
	);

}
