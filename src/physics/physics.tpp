


template <typename T>
Body::Body<T>::Body(Vector<T> pos, float mass, float friction,float max_velocity) :position(pos), mass(mass), friction(friction), max_velocity(max_velocity) {}


template <typename T>
void Body::Body<T>::update(float dt)
{
    velocity += acceleration * dt;
    position += velocity ;
    velocity *= friction;
    velocity = Vector<float>(std::clamp<float>(velocity.x, -max_velocity, max_velocity), std::clamp<float>(velocity.y, -max_velocity, max_velocity));
    acceleration = Vector<T>();
}


#if 0
template <typename T>
void Body<T>::check_collison_wBorder()
{
    float bounce = 0.8;
    //check right and left
    if ((position.x + 2 * shape.getRadius()) > Config::WindowWidth)
    {
        velocity.x = velocity.x * -bounce;
    }
    else if (position.x < 0)
    {
        velocity.x = velocity.x * -bounce;

    }
    //check down and up
    if ((position.y + 2 * shape.getRadius()) > Config::WindowHeight)
    {
        velocity.y = velocity.y * -bounce;
    }
    else if (position.y < 0)
    {
        velocity.y = velocity.y * -bounce;
    }
}
#endif // 0



template <typename T>
void Body::Body<T>::applyforce(const Vector<T>& force)
{
    Vector<T> f = force / mass ;
    acceleration +=  f;
}