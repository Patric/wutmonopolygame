#include "game.h"

//Static functions


//Initialising functions


void game::initStates()
{
	/*!
* Inicjalizuje stany poprzez umieszczenie na g�rze stosu stanu menu. Ka�dy stan ma wska�nik na stos wska�nik�w stan�w. 
	*/

	//puts new game state on top of the stack
	//states itself is just a regular stack. We need to send an adress to a pointer that can handle it
	this->states.push(new mainMenuState(this->window, &this->states)); 
	//this->states.push(new gameState(this->window));
}

void game::initWindow()
{
	/*!
* Inicjalizuje okno programu z konfiguracj� z pliku Config/window.ini.
	*/

	//Create SFML window using options from window.ini file
	std::ifstream ifs("Config/window.ini"); 

	//Returns a vector of videomodes back to us, everything that our computer supports
	this->videoModes = sf::VideoMode::getFullscreenModes();

	


	//Default options
	std::string title = "None";
	//gets current resolution of the desktop
	sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();

	//window_bounds.bitsPerPixel; // how many color per pixel or smth, 32 by default I think
	bool fullscreen = false;
	unsigned framerate_limit = 120;
	bool vertical_sync_enabled = false;
	unsigned antialiasing_level = 0;


	if (ifs.is_open()) {
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> fullscreen;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
	}

	ifs.close();

	//sf::ContextSettings::
	this->fullscreen = fullscreen; //just for tidyness. We seperate local variables from the top
	this->windowSettings.antialiasingLevel = antialiasing_level;

	if (this->fullscreen) 
	{
		this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Fullscreen, this->windowSettings);

	}
	else 
	{
		this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Titlebar | sf::Style::Close, this->windowSettings);
	}

	
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}



//default values for safe guard, there might be errors if we don't do that
void game::initVariables()
{
	/*!
* Inicjalizuje atrybuty klasy, nadaj�c im domy�lne warto�ci pocz�tkowe.
	*/
	this->window = NULL;
	this->fullscreen = false;
	this->dt = 0.f;



}

//Constructors/Destructors
game::game()
{
	/*!
* Inicjalizuje stany oraz okno programu.
	*/
	this->initWindow();
	this->initStates();
}



game::~game()
{
	/*!
* Niszczy utworzone okno oraz po kolei stany ze stosu a� do opr�nienia.
	*/
	delete this -> window;

	//we do that until states are not empty
	while (!this->states.empty()) {

		delete this->states.top(); //removes the data the pointer is holding
		this->states.pop(); //removes the pointer 
	}
}


//Methods

//Regular
void game::endApplication()
{
	/*!
* Wykonuje czynno�ci po zainicjowaniu zamykania programu.
	*/
	std::cout << "Ending application...\n";
		

}
//Update
void game::updateDt()
{	
	/*!
* Aktualizuje atrybut delty czasowej ilo�ci� czasu potrzebnej do wyrenderowania jednej klatki.
	*/
	
	/*Updates the dt variable with the time it takes to update and render one frame.*/

	this->dt = this->dtClock.restart().asSeconds();
	//system("cls");
	//std::cout << this->dt << "\n";
}

void game::updateSFMLEvents()
{
	/*!
* Aktualizuje Eventy SFML, do kt�rych zaliczaj� si� klikni�cia myszyny, zamykanie okien oraz wciskanie przycisk�w. Aktualnie obs�uguje tylko zamykanie okna.
	*/
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}
}

void game::update()
{	/*!
* G��wna metoda aktualizacji gry. Aktualizuje eventySFMLEvents oraz obs�uguje stany.
	*/
	this->updateSFMLEvents();
		
	if (!this->states.empty()) //if there is a state on the stack
	{
		this->states.top()->update(this->dt);
		//we render the top one. When we create a state we can 
		//send a pointer to the window to that state or when we render it we can update it
		if (this->states.top()->getQuit())
		{
			
			//things we want to do before quitting the game
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	//Applicaiton end
	else //if states.empty() if there are no states on the gamestack we end the game
	{
		this->endApplication();
		this->window->close();
	}
	
}


//Render

void game::render()
{
	/*!
* G��wna metoda rysowania element�w. Czy�ci ekran, a nast�pnie rysuje elementy na zainicjowanym oknie, kt�re s� zawarte w stanie, k�ry jest aktualnie na g�rze stosu.
	*/
	this->window->clear();

	//Render items

	if(!this -> states.empty()) //if there is a state on the stack
	{
		this->states.top()->render(this->window);
		//we render the top one. When we create a state we can 
		//send a pointer to the window to that state or when we render it we can update it
	}
		

	this->window->display();




}

//Core

void game::run()
{
	/*!
* G��wna p�tla gry, dzia�aj�ca gdy okno jest otwarte i aktualizuj�ca aktualny stan i rysuj�ca go.
	*/

	while (this -> window->isOpen()) {

		this->updateDt(); //updates delta time
		this->update();
		this->render();
		

	}


}


