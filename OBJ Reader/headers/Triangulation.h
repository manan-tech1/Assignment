#pragma once
#include<vector>
#include<map>
#include"Triangle.h"
using namespace std;


class Triangulation
{
    public:
        Triangulation();
        ~Triangulation();
        vector<Triangle>& triangles();
        vector<Point3D>& uniquePoints();
        
    // private :Point3D findKey(std::map<Point3D, int> &nMapedCoordinates,int index);
    private:
        vector<Triangle> mTriangles;
        vector<Point3D> mUniquePoints;

};
