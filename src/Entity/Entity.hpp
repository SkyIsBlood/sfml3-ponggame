#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "../math/vector.hpp"
#include "../physics/physics.hpp"
template <typename T>

class Entity:public Body::Body<T>
{
public :
	sf::Texture texture;
	Entity(const std::string& texture_path
		, const Vector<T>& position
		, float mass
		,float friction
	,float max_velcoity);

};
#include "Entity.tpp"