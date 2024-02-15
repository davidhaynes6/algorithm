#pragma once
#include "point.h"
#include "sphere.h"

template <typename T>
struct Plane {
    Point3D<T> point; // A point on the plane
    Point3D<T> normal; // Normal vector to the plane

    Plane(const Point3D<T>& point, const Point3D<T>& normal) : point(point), normal(normal) {}

    bool planeSphereIntersection(const Plane<T>& plane, const Sphere<T>& sphere) {
        // Compute distance from sphere's center to the plane
        double distance = std::abs((plane.normal.x * (sphere.center.x - plane.point.x) +
            plane.normal.y * (sphere.center.y - plane.point.y) +
            plane.normal.z * (sphere.center.z - plane.point.z)) /
            std::sqrt(plane.normal.x * plane.normal.x +
                plane.normal.y * plane.normal.y +
                plane.normal.z * plane.normal.z));

        return distance <= sphere.radius;
    }
};