#pragma once
#include <SFML/Graphics.hpp>
#include "../math/vector.hpp"
#include "../config.hpp"
#include <algorithm>
namespace Body{

    template <typename T>
    class Body
    {
    public:
        float mass;
        float friction = 1.f;
        float max_velocity;
        Vector<T> position;
        Vector<T> velocity;
        Vector<T> acceleration;
        Body(Vector<T> position, float mass, float friction ,float max_velocity);
        void update(float dt);
        void applyforce(const Vector<T>& force);
    };


}



#include "physics.tpp"