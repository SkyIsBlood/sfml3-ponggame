#pragma once 
#include <SFML/Graphics.hpp>
#include "../Entity/Entity.hpp"
#include "../math/vector.hpp"
#include "../Render/Renderer.hpp"
#include "../assets/assets.hpp"
#include "../config.hpp"




namespace core 
{
	int border(Entity<float>& e);
	void showhearts(int& hearts, sf::RenderWindow& mainwindow);
	void withblock(Entity<float>& A,const Entity<float>& B,float & ball_speed);
	
}
