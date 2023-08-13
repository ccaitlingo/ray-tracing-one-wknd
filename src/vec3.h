#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
    public:
        // e is just the name of our array
        double e[3];

        // CONSTRUCTORS
        // : is a shortcut for implementing the body of the constructor
        // Equivalent to doing e[0] = 0, e[1] = 1, etc.
        vec3() : e{0,0,0} {}
        // Another constructor!
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

        // Constants
        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        // Defining operations
        // minus (-)
        // i.e. How do you subtract vectors?
        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
        // indexing ([])
        double operator[](int i) const { return e[i]; }
        // indexing ([])
        // The & declares this as a reference variable
        // Why have a repeat?
        // Ans: For when it is invoked on const or non-const objects
        double& operator[](int i) { return e[i]; }

        // add (+)
        vec3& operator+=(const vec3 &v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            // * = a pointer, allows you to refer directly to values in memory
            // (not referring to a copy).
            // The only difference btwn reference (&) and pointer (*) is that
            // a pointer can be null.
            return *this;
        }

        // multiply (*)
        vec3& operator*=(double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        // divide (/)
        vec3& operator/=(double t) {
            return *this *= 1/t;
        }

        double length() const {
            return sqrt(length_squared());
        }

        double length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }
};

// point3 is just an alias for vec3, but useful for geometric clarity in the code.
using point3 = vec3;

// Vector Utility functions / Static Functions
// toString
inline std::ostream& operator<<(std::ostream &out, const vec3 &v){
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

// add (+) two given vectors
inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + u.e[2]);
}

// add (-) two given vectors
inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

// multiply (*) to given vectors
inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

// multiply (*) a given vector by a constant
inline vec3 operator*(double t, const vec3 &v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

// multiply (*) a given vector by a double
inline vec3 operator*(const vec3 &v, double t) {
    return t * v;
}

// divide (/) a given vector by a double
inline vec3 operator/(vec3 v, double t) {
    return (1/t) * v;
}

inline double dot(const vec3 &u, const vec3 &v) {
    return u.e[0] * v.e[0]
            + u.e[1] * v.e[1]
            + u.e[2] * v.e[2];
}

inline vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
        u.e[2] * v.e[0] - u.e[0] * v.e[2],
        u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}

#endif