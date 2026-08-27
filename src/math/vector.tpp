

template <typename T>
Vector<T>::Vector():x(0),y(0){}

template <typename T>
Vector<T>::Vector(T x, T y):x(x),y(y){}




// arithmetic v = u + n
template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& other) const
{
    T new_x =  x + other.x ;
    T new_y =  y + other.y ;
    return Vector<T>(new_x,new_y);
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector<T>& other) const
{
    T new_x =  x - other.x ;
    T new_y =  y - other.y ;
    return Vector<T>(new_x,new_y);
}


template <typename T>
Vector<T> Vector<T>::operator*(const T scalar ) const
{
    T new_x =  x * scalar ;
    T new_y =  y * scalar ;
    return Vector<T>(new_x,new_y);
}


template <typename T>
Vector<T> Vector<T>::operator/(const T scalar ) const
{
    if (scalar == 0)
    {
        throw std::invalid_argument("Error : divison by zero ");
    }
    
    T new_x =  x / scalar ;
    T new_y =  y / scalar ;
    return Vector<T>(new_x,new_y);
}


template <typename T>
Vector<T> operator*(T scalar , const Vector<T>& vec){
    return vec * scalar;
}

// in place arithmetic v+= u

template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& other)
{
    x += other.x;
    y += other.y;
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator-=(const Vector<T>& other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}


template <typename T>
Vector<T>& Vector<T>::operator*=(const T scalar)
{
    x *= scalar;
    y *= scalar;
    return *this;
}


template <typename T>
Vector<T>& Vector<T>::operator/=(const T scalar)
{
    if (scalar == 0)
    {
        throw std::invalid_argument("Error : divison by zero ");
    }

    x /= scalar;
    y /= scalar;
    return *this;
}
template<typename T>
bool operator>(const Vector<T> lhs,const Vector<T> rhs)
{
    return (lhs.x > rhs.x && lhs.y > rhs.y);
}
template<typename T>
bool operator<(const Vector<T> lhs, const Vector<T> rhs)
{
    return (lhs.x < rhs.x && lhs.y < rhs.y);
}
template<typename T>
bool operator==(const Vector<T> lhs, const Vector<T> rhs)
{
    return (lhs.x == rhs.x && lhs.y == rhs.y);
}
// other methods

template <typename T>
T Vector<T>::mag() const {
    return sqrt(x * x + y * y);
}




template <typename T>
Vector<T> Vector<T>::normalize()const{
    T m = mag();
    T new_x = x / m;
    T new_y = y / m;
    return Vector<T>(new_x,new_y);
}


template <typename T>
Vector<T> Vector<T>::rotate(const T angle)const{
        T new_x = x * cos(angle) - y * sin(angle);
        T new_y = x * sin(angle) + y * cos(angle);
        return Vector<T>(new_x,new_y);

}



template <typename T>
T Vector<T>::dot(const Vector<T>& other)const
{
    return x * other.x + y * other.y;
}


template <typename T>
void Vector<T>::setmag(const T magnitude){
    Vector<T> n = normalize();
    x = n.x * magnitude;
    y = n.y * magnitude;
}



template <typename T>
T Vector<T>::dist(const Vector<T>& other) const
{
    return Vector<T>(x - other.x , y - other.y).mag();
}



template <typename T>
Vector<T> Vector<T>::zero()const
{
    return Vector<T>(0,0);
}


template <typename T>
std::ostream& operator<<(std::ostream& os ,const Vector<T>& v)
{
    os<<"Vector<T>{x = "<< v.x<<" , y = "<<v.y<<" }";
    return os;
}

