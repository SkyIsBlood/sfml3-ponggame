#pragma once
#include <SFML/Graphics.hpp>
#include "../math/vector.hpp"
#include "../Entity/Entity.hpp"
#include <string>

namespace Renderer 
{
	
	template <typename T> void render_entity(sf::RenderWindow& rwindow, Entity<T>& entity);
	template <typename T> void render_sprite(sf::RenderWindow& rwindow, std::string& sprite_path, Vector<T> position , Vector<T> scale);
}

#include "Renderer.tpp"
