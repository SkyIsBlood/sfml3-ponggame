#pragma once
//things for everything to work
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <print>
#include <string>
#include "physics/physics.hpp"
#include "math/vector.hpp"
#include "config.hpp"
#include "assets/assets.hpp"
//must be initiated before starting the game
#include "Shapes/Shapes.hpp"
#include "Entity/Entity.hpp"
#include "Render/Renderer.hpp"
//the main loop
#include "setup/setup.hpp"
#include "core/core.hpp"


//assets 



namespace Game {	
	void run();
	namespace math
	{
		template <typename T>
		Vector<T> Vector2D(T x, T y);
	};

}
#include "Game.tpp"
