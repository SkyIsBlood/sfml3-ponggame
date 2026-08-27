void Game::run() 
{
	sf::RenderWindow& window = setup::getwindow();
	core::mainloop(window);
}








template <typename T>
Vector<T> Game::math::Vector2D(T x, T y) {
		return Vector<T>(x, y);
}