#include "setup.hpp"

sf::RenderWindow& setup::getwindow()
{
	static sf::RenderWindow window(sf::VideoMode({ Config::WindowWidth,Config::WindowHeight }), "hello world");
	window.setFramerateLimit(60);
	window.clear(Config::BACKGROUND);
	std::cout << "window is created with success" << std::endl;
	return window;
}