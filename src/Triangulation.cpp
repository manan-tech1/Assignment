#include "..\headers\Triangulation.h"
#include<map>
#include<vector>
#include<iostream>


Triangulation::Triangulation()
{

}
Triangulation::~Triangulation()
{
    
}

vector<Triangle> & Triangulation::triangles()
{
    return mTriangles;
}

vector<Point3D> & Triangulation::uniquePoints()
{
    return mUniquePoints;
}

// Point3D Triangulation :: findKey(std::map<Point3D, int> &nMapedCoordinates,int index)
// {
//     Point3D p(0.0,0.0,0.0);
//     for (auto &it : nMapedCoordinates)
//         {
//             int value1 =it.second;
//             if ( value1 == index)
//             {
//                 // std::cout<<key;
//                return it.first;
//             }
//         }
//         return p;
// }