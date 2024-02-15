#include <QtCore/QCoreApplication>
#include <iostream>
#include <vector>
#include <functional>
#include "task.h"
#include "algorithm.h"
#include "point.h"
#include "line.h"
#include "sphere.h"
#include "plane.h"

template <typename T>
void display(T &vector)
{
    if (!vector.size()) return;
    for (auto e : vector) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
};

using std::vector;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setApplicationName("Core App");
    QCoreApplication::setApplicationVersion("1.0");
    
    //Algorithm algorithm;

    // Time the lengthyOperation1 of the Algorithm class
    //Task::timeMethod("MatrixMulitplication", & Algorithm::execute, &algorithm);

    /*
    vector<int> q = { 0,1,0,1,0,1,0,1 };
    vector<int> p = { 1,1,1,1,0,0,0,0 };
    vector<int> r(q.size(), 0);
    display(q);
    display(p);
    std::cout << std::endl;

    std::logical_and<int> logical_and_function;
    std::transform(q.begin(), q.end(), p.begin(), r.begin(), logical_and_function);
    display(r);
    */

    // Define some points, lines, a sphere, and a plane
    Point3D<double> p1(0, 0, 0), p2(1, 1, 1), p3(3, 3, 3);
    Line3D<double> line(p1, p2);
    Sphere<double> sphere(p2, 2.0);
    Plane<double> plane({ 0, 0, 1 }, { 0, 0, 1 }); // Plane z=1 with normal pointing in z-direction

    // Perform rotations
    Point3D<double> rotatedX = rotatedX.rotateX(p1, M_PI / 4); // Rotate p1 around x-axis by 45 degrees
    Point3D<double> rotatedY = rotatedY.rotateY(p1, M_PI / 4); // Rotate p1 around y-axis by 45 degrees

    // Check for intersections
    bool lineSphereIntersect = sphere.lineSphereIntersection(line, sphere);
    bool planeSphereIntersect = plane.planeSphereIntersection(plane, sphere);

    // Print results
    std::cout << "Rotated around X-axis: (" << rotatedX.x << ", " << rotatedX.y << ", " << rotatedX.z << ")\n";
    std::cout << "Rotated around Y-axis: (" << rotatedY.x << ", " << rotatedY.y << ", " << rotatedY.z << ")\n";
    std::cout << "Line-Sphere Intersection: " << (lineSphereIntersect ? "Yes" : "No") << std::endl;
    std::cout << "Plane-Sphere Intersection: " << (planeSphereIntersect ? "Yes" : "No") << std::endl;


    return a.exec();
}
