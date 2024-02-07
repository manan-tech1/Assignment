// STLWriter.cpp
#include "../headers/STLWriter.h"
#include "../headers/Triangulation.h"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <map>
#include <vector>
using namespace std;


void STLWriter ::writeSTLToFile(std::string &filePath ,Triangulation &triangulationObj)
{
    std::ofstream outFile(filePath);
 
    if (!outFile.is_open())
    {
        cout << "Error while opening the file for writing." << endl;
    }
 
    vector<Point3D> &points = triangulationObj.uniquePoints();
    vector<Triangle> &triangles = triangulationObj.triangles();
    for (const Triangle &triangle : triangles)
    {
        outFile << points[triangle.v1()].x() << " " << points[triangle.v1()].y() << " " << points[triangle.v1()].z() << endl;
        outFile << points[triangle.v2()].x() << " " << points[triangle.v2()].y() << " " << points[triangle.v2()].z() << endl;
        outFile << points[triangle.v3()].x() << " " << points[triangle.v3()].y() << " " << points[triangle.v3()].z() << endl;
    }
    outFile.close();
}
