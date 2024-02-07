#include "../headers/StlToObj.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../headers/Point3D.h"
using namespace std;

void StlToObj :: stlToObjConversion(std::string &filePath,Triangulation &triangulation)
{
    ofstream outFile(filePath);
 
    if (!outFile.is_open())
    {
        cout << "Error while opening text file." << endl;
        return;
    }
 
    vector<Point3D> &points = triangulation.uniquePoints();
    for (size_t i = 0; i < points.size(); i++)
    {
        outFile<<"v"<<" "<<points[i].x()<<" " << points[i].y() << " " << points[i].z() << endl;

    }
    
    vector<Triangle> &triangles = triangulation.triangles();
 
   cout<<triangulation.triangles().size();
   int countVertex=1;
    for (const Triangle &triangle : triangles)
    {
        outFile << "f" << " "<< triangle.v1()+1<<"//"<<" "<<triangle.v2()+1<<"//"<<" "<<triangle.v1()+1<<"//"<<endl;
              
    }
    outFile.close();
    cout << "Data writting from .stl to text file successful!" << endl;
}