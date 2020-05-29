#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>


class Button {
public:

	Button() { }

	Button(std::string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor) {
	
		button.setSize(size);
		button.setFillColor(bgColor);
		text.setFillColor(textColor);
		text.setCharacterSize(charSize);
		text.setString(t);
	}


	void setFont(sf::Font& font) { //to prevent any access violation we put that in public
		text.setFont(font);
	}

	void setBackColor(sf::Color color) {
		button.setFillColor(color);
	}

	void setTextColor(sf::Color color) {
		text.setFillColor(color);
	}
	void setPosition(sf::Vector2f pos) {
		button.setPosition(pos);
		
		float xPos = (pos.x + button.getLocalBounds().width / 2);
		float yPos = (pos.y + button.getLocalBounds().height / 2);
		text.setOrigin(text.getLocalBounds().left + text.getLocalBounds().width / 2.0f, text.getLocalBounds().top + text.getLocalBounds().height / 2.0f);
		

		text.setPosition({ xPos, yPos});
	}

	void drawTo (sf::RenderWindow& window) {
		window.draw(button);
		window.draw(text);
	}


	bool isMouseOver(sf::RenderWindow& window) {
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;

		float btnPosX = button.getPosition().x;
		float btnPosY = button.getPosition().y;

		float btnxPosWidth = button.getPosition().x + button.getLocalBounds().width; 
		float btnyPosHeight = button.getPosition().y + button.getLocalBounds().height;

		if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) {
			return true;
		}
		return false;

	}

	

private:
	sf::RectangleShape button;
	sf::Text text;

};