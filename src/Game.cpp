#include "Game.hpp"

void Game::run() 
{
	sf::RenderWindow& window = setup::getwindow();
	MAINLOOP::mainloop(window);
}



