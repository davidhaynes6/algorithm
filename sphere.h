#pragma once
#include "point.h"
#include "line.h"

template<typename T>
struct Sphere {
    Point3D<T> center;
    T radius;

    Sphere(const Point3D<T>& center, double radius) : center(center), radius(radius) {}

    bool lineSphereIntersection(const Line3D<T>& line, const Sphere<T>& sphere) {
        // Direction vector of the line
        Point3D dir = { line.p2.x - line.p1.x, line.p2.y - line.p1.y, line.p2.z - line.p1.z };

        // Vector from the line's start point to the sphere's center
        Point3D f = { line.p1.x - sphere.center.x, line.p1.y - sphere.center.y, line.p1.z - sphere.center.z };

        double a = dir.x * dir.x + dir.y * dir.y + dir.z * dir.z;
        double b = 2 * (f.x * dir.x + f.y * dir.y + f.z * dir.z);
        double c = (f.x * f.x + f.y * f.y + f.z * f.z) - sphere.radius * sphere.radius;

        // Discriminant
        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0) {
            // No intersection
            return false;
        }
        else {
            // Intersection occurs
            return true;
        }
    }

};
