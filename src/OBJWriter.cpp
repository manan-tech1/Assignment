#include "../headers/OBJWriter.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../headers/Point3D.h"
using namespace std;


void  OBJWriter::  writeOBJ(std::string &filePath,Triangulation &triangulation)
{
     std::ofstream outFile(filePath);
 
    if (!outFile.is_open())
    {
        cout << "Error while opening the file for writing." << endl;
    }
 
    vector<Point3D> &points = triangulation.uniquePoints();
    
 
    vector<Triangle> &triangles = triangulation.triangles();
    for (const Triangle &triangle : triangles)
    {

        outFile << points[triangle.v1()-1].x() << " " << points[triangle.v1()-1].y() << " " << points[triangle.v1()-1].z() << endl;
        outFile << points[triangle.v2()-1].x() << " " << points[triangle.v2()-1].y() << " " << points[triangle.v2()-1].z() << endl;
        outFile << points[triangle.v3()-1].x() << " " << points[triangle.v3()-1].y() << " " << points[triangle.v3()-1].z() << endl;
    }
    outFile.close();
}