#pragma once

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

// Define keys:
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27


class textBox {
public:

	textBox() { }

	textBox(int size, sf::Color color, bool sel) { //initial selected state of the textBox (at the moment of consturctor initiation)
		textbox.setCharacterSize(size);
		textbox.setFillColor(color);
		isSelected = sel;
		if (isSelected) {
			textbox.setString(tracker); // when selected it has _ by default
		}
		else {
			textbox.setString(""); // if not selected it doesn't have _ by default
		}
	}
	void setFont(sf::Font& font) { //to prevent any access violation we put that in public
		textbox.setFont(font);
	}


	void setPosition(sf::Vector2f pos) {
		textbox.setPosition(pos);
	}

	void setLimit(bool ToF) {
		hasLimit = ToF; //True or False
	}

	void setLimit(bool ToF, int lim) {
		hasLimit = ToF;
		limit = lim - 1;
	}

	void isTracker(bool ToF) { //puts tracker at the end of the string

		if (ToF == true) {
			textbox.setString(text.str() + tracker);
		}
		else {
			std::string t = text.str();
			std::string newT = "";
			for (int i = 0; i < t.length(); i++) {
				newT += t[i];
			}
			textbox.setString(newT);
		}
	}

	void setSelected(bool sel) { //when textbox is selected it has the underscore
		isSelected = sel;

		if (!sel) {
			isTracker(false);
		}
		else {
			isTracker(true);
		}
	}

	std::string getText() {
		return text.str();
	}
	//functiuon that draws on the screen
	void drawTo(sf::RenderWindow& window) {
		window.draw(textbox);
	}

	void typedOn(sf::Event input) {
		if (isSelected) { //we only let user type when he is selecting the textbox
			int charTyped = input.text.unicode; //gets the value of the character that's being typed
			if (charTyped < 128) {// nothing what would crash the programme
				if (hasLimit) {
					if (text.str().length() <= limit) {
						inputLogic(charTyped);
					}
					else if (text.str().length() > limit && charTyped == DELETE_KEY) { //user has to be able to delete keys after reaching the limt
						deleteLastChar();
					}
					
				}
				else {
						inputLogic(charTyped);
				
				}
			}
		}
	}

private:
	sf::Text textbox;
	std::ostringstream text;
	bool isSelected; // is the user selecting textbox or not
	bool hasLimit = false;
	int limit = 0;
	std::string tracker = "|";
	//we want to get input from the user 
	
	void inputLogic(int charTyped) { //SFML returnes a unicode value of the character typed or ASCII value and we want to display that on the screen
		if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) { //if character is not equal to any of the special keys
			text << static_cast<char>(charTyped); // << is how we write to a ostringstream object, static_cast allows us to convert types

		}
		else if (charTyped == DELETE_KEY) {
			if (text.str().length() > 0) {//make sure there is something to delete
				deleteLastChar();
			}
		}
		else if (charTyped == ENTER_KEY) {
			setSelected(true);
		}

		isTracker(true); //to keep track of where we are in the textbox. Will be appended always to the end of the textbox
	}

	void deleteLastChar() { //called when DELETE_KEY is pressed
		std::string t = text.str();
		std::string newT = "";
		for (int i = 0; i < t.length() - 1; i++) {
			newT += t[i];
		}
		text.str(""); //clear before we put the copied (without the last character) value
		text << newT;
		isTracker(true);
	}


};
