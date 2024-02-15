#pragma once
template<typename T>
struct Point3D
{
    T x, y, z;
   
    Point3D(T x = 0, T y = 0, T z = 0) : x(x), y(y), z(z) {}

    T distanceTo(const Point3D& point) const {
        return std::sqrt(
            (x - point.x) * (x - point.x) + 
            (y - point.y) * (y - point.y) +
            (z - point.z) * (z - point.z));
    }

    Point3D<T> translate(const Point3D<T>& point, const Point3D<T>& offset) {
        return { point.x + offset.x, point.y + offset.y, point.z + offset.z };
    }

    Point3D<T> scale(const Point3D<T>& point, double scaleFactor) {
        return { point.x * scaleFactor, point.y * scaleFactor, point.z * scaleFactor };
    }

    Point3D<T> rotateZ(const Point3D<T>& point, T theta) {
        T cosTheta = std::cos(theta);
        T sinTheta = std::sin(theta);
        return { point.x * cosTheta - point.y * sinTheta,
                point.x * sinTheta + point.y * cosTheta,
                point.z };
    }

    Point3D<T> rotateX(const Point3D<T>& point, T theta) {
        T cosTheta = std::cos(theta);
        T sinTheta = std::sin(theta);
        return { point.x,
                point.y * cosTheta - point.z * sinTheta,
                point.y * sinTheta + point.z * cosTheta };
    }

    Point3D<T> rotateY(const Point3D<T>& point, T theta) {
        T cosTheta = std::cos(theta);
        T sinTheta = std::sin(theta);
        return { point.x * cosTheta + point.z * sinTheta,
                point.y,
                -point.x * sinTheta + point.z * cosTheta };
    }
 };