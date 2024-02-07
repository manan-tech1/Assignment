#include "../headers/STLReader.h"
// #include "../headers/Point3DComparator.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;


void STLReader ::readSTL(std::string &filePath,Triangulation &triangulation)
{
    std::ifstream inputFile(filePath);
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file: " << std::endl;
        return;
    }
    map<Point3D, int> nMapedCoordinates;
    // vector<Point3D> points;
    std::string line;
    int count=1;
    int index1;
    int index2;
    int index3;
    while (std::getline(inputFile, line))
    {
        if (line.find("vertex") != std::string::npos)
        {
            double x, y, z;
            istringstream iss(line);
            string keyword;
            iss >> keyword >> x >> y >> z;
            Point3D p1(x,y,z);
            auto iterator=nMapedCoordinates.find(p1);
            if(iterator == nMapedCoordinates.end())
            {
                
               // nMapedCoordinates.insert(pair<Point3D, int>(p1,triangulation.uniquePoints().size() ));
                nMapedCoordinates[p1] = triangulation.uniquePoints().size();
                triangulation.uniquePoints().push_back(p1);

            }
        //    points.push_back(p1);
            if(count == 1)
            {
                index1 = nMapedCoordinates[p1];
                count++;
            }
           else if(count == 2)
            {
                index2 = nMapedCoordinates[p1];
                count++;
            }
            else if(count == 3)
            {   
               // cout<<nMapedCoordinates[p1]<<endl;
                index3 = nMapedCoordinates[p1];
                count++;
            }
            // triangles.push_back(Triangle(pointIndexMap[point]));
           
        }
        
        if(count == 4)
        {
            //  cout<<index1<<" "<<index2<<" "<<index3<<endl;
            triangulation.triangles().push_back(Triangle(index1, index2, index3));
            count = 1; 
        }
    }
    inputFile.close();
}