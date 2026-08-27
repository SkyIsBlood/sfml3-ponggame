#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>




template <typename T>
class Vector
{   
public:
    T x,y;
    Vector();
    Vector(T x , T y);
    Vector<T> operator+(const Vector& other) const;
    Vector<T> operator-(const Vector& other) const ;
    Vector<T> operator*(const T scalar) const;
    Vector<T> operator/(const T scalar) const;
    Vector<T>& operator+=(const Vector& other) ;
    Vector<T>& operator-=(const Vector& other) ;
    Vector<T>& operator*=(const T scalar) ;
    Vector<T>& operator/=(const T scalar) ;
    T mag() const;
    Vector normalize() const;
    Vector rotate(const T angle)const;
    T dot(const Vector& other)const;
    void setmag(const T magnitude);
    T dist(const Vector& other) const;
    Vector zero()const;
    friend std::ostream& operator<<(std::ostream& os ,const Vector<T>& v);
    


};
template <typename T> Vector<T> operator*(T scalar, const Vector<T>& vec);
template <typename T> std::ostream& operator<<(std::ostream& os, const Vector<T>& v);
template <typename T> inline bool operator==(const Vector<T> lhs, const Vector<T> rhs);
template <typename T> inline bool operator>(const Vector<T> lhs, const Vector<T> rhs);
template <typename T> inline bool operator<(const Vector<T> lhs, const Vector<T> rhs);


#include "vector.tpp"