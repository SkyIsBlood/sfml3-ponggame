#pragma once
#include <SFML/Graphics.hpp>
#include <string_view>
#include "math/vector.hpp"

namespace Config {
    // Window settings
    inline constexpr unsigned int WindowWidth = 800;
    inline constexpr unsigned int WindowHeight = 600;
    inline constexpr unsigned int FrameRateLimit = 60;
    inline constexpr sf::Color BACKGROUND = sf::Color(20,20,20);
    inline  Vector<float> GRAVITY = Vector<float>(0, 0.5);
    inline constexpr std::string_view WindowTitle = "My Game";
    inline  Vector<float> initial_position(100.f,100.f);
}