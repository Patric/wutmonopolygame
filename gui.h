#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <list>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_PRESSED};

namespace gui 
{ //allows to have several button class. Using namespace since it's a samll gui library

	class button
	{
	private:
		short unsigned buttonState;
		float keyTime;
		float keyTimeMax;
		bool blocked;
		//bool isPressed;
		//bool isMouseOver;

		sf::RectangleShape shape;
		sf::Font* font;
	

		sf::Color idleColor;
		sf::Color hoverColor;
		sf::Color pressedColor;

	public:
		sf::Text text;

		button(float x, float y, float width, float height, sf::Font* font,
			std::string text,
			sf::Color idleColor, sf::Color hoverColor, sf::Color pressedColor);


		virtual ~button();


		//Accessors

		//Object called by const function cannot be modified
		const bool isPressed() const;
		void blockButton();
		void unblockButton();



		//methods
		const bool getKeyTime();
		void updateKeyTime(const float& dt);
		void update(sf::Vector2f mousePos, const float& dt);
		void render(sf::RenderTarget* target);

		


	};
	
	class infoBar 
	{
	private:
		
		
		sf::RectangleShape shape;
		sf::Font* font;
		std::vector<sf::Text*> infos;
		sf::Color color;
		
	


	public:
	
			std::map<std::string, sf::Vector2f> positions;

			infoBar(float x, float y, float width, float height, sf::Color color, sf::Font* font);
			virtual ~infoBar();
			void initPositions();

			void addInfo(std::string position_name, std::string Text);
			void updateInfo(std::string text, unsigned int index);
			
			
			void render(sf::RenderTarget* target);



	};


	class menu {
	private:
		sf::Font* font;

	public:
		std::list<button*> buttons;

		menu(float x, float y, std::vector<std::string> buttonNames, sf::Font* font);
		virtual ~menu();


		//methods

		void update(sf::Vector2f mousePos, const float& dt);
		void render(sf::RenderTarget* target);

	};
}





