#pragma once
#ifndef _VEC_H
#define _VEC_H

#include <cmath>
#include <tuple>

namespace utils
{
    template<class T>
    struct Vec
    {
        // Typedef
        using refT = const T&;
        using refVec = const Vec<T>&;

        Vec() { }
        Vec(refT x, refT y) : x(x), y(y) { }

        void set(refT x, refT y) { this->x = x; this->y = y; }

        T getX() { return x; }
        T getY() { return y; }

        Vec& operator+(refVec vec)
        {
            this->x += vec.x;
            this->y += vec.y;
            return *this;
        }

        Vec& operator+(refT val)
        {
            this->x += val;
            this->y += val;
            return *this;
        }

        Vec& operator-(refVec vec)
        {
            this->x -= vec.x;
            this->y -= vec.y;
            return *this;
        }

        Vec& operator-(refT val)
        {
            this->x -= val;
            this->y -= val;
            return *this;
        }

        static double getDistance(refVec v0, refVec v1)
        {
            double x = v0.x - v1.x;
            double y = v0.y - v1.y;
            return std::sqrt(x * x + y * y);
        }

        bool operator==(refVec vec)
        {
            return std::tuple(x, y) == std::tuple(vec.x, vec.y);
        }

        bool operator!=(refVec vec)
        {
            return !(operator==(vec));
        }

        T x; T y;
    };

    using Vector2i = Vec<int>;
}


#endif /* end of include guard:  */
