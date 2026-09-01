namespace Renderer 
{
	void render_entity(sf::RenderWindow& rwindow,auto& entity);
	void draw(sf::RenderWindow& rwindow, auto& shape);
	void render_sprite(sf::RenderWindow& rwindow, auto& sprite_path, Vector<float> position , Vector<float> scale);
}
#include "Renderer.tpp"