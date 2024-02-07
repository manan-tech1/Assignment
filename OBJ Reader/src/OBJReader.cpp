#include "../headers/OBJReader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../headers/Point3D.h"
using namespace std;


void OBJReader ::readOBJ(std::string &filePath,Triangulation &triangulation)
{
    // std::vector<Point3D> points;

    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << std::endl;
    }

    std::string line;
    istringstream iss(line);
    string keyword;
    while (std::getline(file, line))
    {

        if (line.find("v") != string::npos) // Taking inputs of v as vertices
        {
            double x, y, z;
            istringstream iss(line);
            string keyword;
            iss >> keyword >> x >> y >> z;

            if (keyword == "v")
            {

                Point3D P1(x, y, z);

                triangulation.uniquePoints().push_back(P1);
            }
        }

        if (line.find("f") != string::npos) // Checking the face values
        {
            string x, y, z;
            istringstream iss(line);
            string keyword;
            iss >> keyword >> x >> y >> z;

            if (keyword == "f")
            {

                int v1, v2, v3; // converting string into int
                v1 = x[0];
                v1 -= 48;
                v2 = y[0];
                v2 -= 48;
                v3 = z[0];
                v3 -= 48;

                Triangle T(v1, v2, v3);
                triangulation.triangles().push_back(T);
            }
        }
    }
// vector<Triangle> &triangles = triangulation.triangles();
//     for (const Triangle &triangle : triangles)
//     {
    
// }

    cout << triangulation.triangles().size();
    file.close();
}