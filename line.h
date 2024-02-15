#pragma once
#include "point.h"

template<typename T>
struct Line3D {

    Point3D<T> p1, p2;

    Line3D(const Point3D<T>& p1, const Point3D<T>& p2) : p1(p1), p2(p2) {}

    bool containPoint(const Point3D<T>& point) const 
    {
        // vector from p1 to p2
        Point3D<T> dirP1P2 = { p2.x - p1.x, p2.y - p1.y, p2.z - p1.z };

        // vector from p1 to point
        Point3D<T> dirP1Point = { point.x - p1.x, point.y - p1.y, point.z - p1.z };

        // calculate the cross product of dirP1P2 and dirP1Point
        Point3D<T> crossProduct = {
            dirP1P2.y * dirP1Point.z - dirP1P2.z * dirP1Point.y,
            dirP1P2.z * dirP1Point.x - dirP1P2.x * dirP1Point.z,
            dirP1P2.x * dirP1Point.y - dirP1P2.y * dirP1Point.x
        };

        return crossProduct.x == 0 && crossProduct.y == 0 && crossProduct.z == 0;
    }
};