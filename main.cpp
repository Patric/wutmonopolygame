#include "game.h"

//Netowrk tests

//include "multiplayer_test.cpp"
//#include <SFML/Network.hpp>
//#include <SFML/Graphics.hpp>
//#include <iostream>
//
//#define TILE_SIZE 49.f
//
//
//
//
//
//
//
//
//
//int main() {
//	
//
//	//sf::IpAddress ip = sf::IpAddress::getPublicAddress();
//	sf::TcpSocket socket;
//	std::string consoleInput;
//	std::cout << "Your global ip is " << sf::IpAddress::getPublicAddress() << "\n";
//	std::cout << "type \"host\" or type ip" << std::endl;
//	std::cin >> consoleInput;
//
//	std::cout << "type gate" << "\n";
//	int gate;
//	std::cin >> gate;
//
//	if (consoleInput == "host")
//	{
//		sf::TcpListener listener;
//		listener.listen(gate);
//
//
//		std::cout << "Waiting for connection..." << std::endl;
//		if (listener.accept(socket) != sf::Socket::Done)
//		{
//			//listener.listen(8080);
//			std::cout << "Couldn't connect \n";
//			//std::cin >> consoleInput;
//			return 0;
//		}
//		// else
//			//std::cout << listener.accept(socket) << "\n";
//		std::cout << "I'm here" << "\n";
//	}
//	else
//
//	{
//	
//		std::cout << "Trying to connect..." << std::endl;
//		//Timeout is set to 10 seconds. If nothing happens - Abort
//		if (socket.connect(consoleInput, gate, sf::seconds(10)) != sf::Socket::Done)
//		{
//			std::cout << "Couldn't connect \n";
//			//Couldn't connect for some reaston
//			//std::cin >> consoleInput;
//			return 0;
//
//		}
//	}
//		//set up the scene
//
//		sf::RenderWindow window(sf::VideoMode(640, 480), "Networking");
//
//		socket.setBlocking(false);
//
//		sf::Vector2f shapeSize(TILE_SIZE, TILE_SIZE);
//		sf::RectangleShape localShape(shapeSize);
//		sf::RectangleShape remoteShape(shapeSize);
//		remoteShape.setFillColor(sf::Color::Green);
//		while (window.isOpen())
//		{
//			//Handle Input
//			sf::Vector2i moveDir;
//			sf::Event event;
//			while (window.pollEvent(event))
//			{
//				switch (event.type)
//				{
//				case sf::Event::KeyPressed:
//					if (event.key.code == sf::Keyboard::W)
//						moveDir.y += -1;
//					else if (event.key.code == sf::Keyboard::S)
//						moveDir.y += 1;
//					else if (event.key.code == sf::Keyboard::D)
//						moveDir.x += 1;
//					else if (event.key.code == sf::Keyboard::A)
//						moveDir.x += -1;
//					break;
//
//
//				case sf::Event::Closed:
//					window.close();
//					break;
//				}
//
//
//			}
//
//
//
//			//Check for new papckets
//
//			sf::Packet packet;
//			if (socket.receive(packet) == sf::Socket::Done)
//			{
//				sf::Vector2f pos;
//				packet >> pos.x >> pos.y;
//				remoteShape.setPosition(pos);
//
//			}
//
//			//Update frame
//
//			if (moveDir.x != 0 || moveDir.y != 0)
//			{
//				localShape.move(moveDir.x * TILE_SIZE, moveDir.y * TILE_SIZE);
//				sf::Packet packet;
//				packet << localShape.getPosition().x << localShape.getPosition().y;
//				if (socket.send(packet) != sf::Socket::Done)
//				{
//					//Handle problem (probably the other disconnected)
//					std::cout << "Other user disconnected \n";
//					return 0;
//				}
//
//
//			}
//
//
//			//Render frame
//
//			window.clear();
//
//			window.draw(localShape);
//			window.draw(remoteShape);
//
//			window.display();
//
//
//		}//Window is open loop boundary
//
//


//Normal work
int main()
{

	game game;
	game.run();


	return 0;

}