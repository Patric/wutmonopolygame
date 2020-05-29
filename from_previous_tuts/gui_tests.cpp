#include <SFML/Graphics.hpp>
#include "textBox.h"
#include "button.h"
#include <iostream>

void gui_tests()
{
	sf::RenderWindow window;

	sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);

	window.create(sf::VideoMode(900, 900), "WUT Monopoly in building...", sf::Style::Titlebar | sf::Style::Close); // "|" adds the functionality of "Close" to Titlebar I guess?
	window.setPosition(centerWindow);

	window.setKeyRepeatEnabled(true);
	sf::Font Centaur;
	Centaur.loadFromFile("Centaur.ttf");
	textBox textbox1(15, sf::Color::White, false);
	textbox1.setFont(Centaur);
	textbox1.setPosition({ 100, 100 });
	textbox1.setLimit(true, 10);


	Button btn1("Click me", { 200, 50 }, 20, sf::Color::Green, sf::Color::Red);
	btn1.setFont(Centaur);
	btn1.setPosition({ 100, 300 });




	//Main Loop
	while (window.isOpen()) {

		sf::Event Event;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			textbox1.setSelected(true);
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			textbox1.setSelected(false);
		}
		//Event Loop:

		while (window.pollEvent(Event)) {//loop to get anyevent from the event queue
			switch (Event.type) {

			case sf::Event::Closed:
				window.close();
			case sf::Event::TextEntered:
				textbox1.typedOn(Event);
				break;
			case sf::Event::MouseMoved:
				if (btn1.isMouseOver(window)) {
					btn1.setBackColor(sf::Color::White);
				}
				else {
					btn1.setBackColor(sf::Color::Green);
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (btn1.isMouseOver(window)) {
					std::cout << "You clicked the button\n";
				}

			}

		}
		window.clear();
		textbox1.drawTo(window);
		btn1.drawTo(window);
		window.display();
	}

}