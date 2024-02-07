#include <iostream>
#include <vector>
#include "./headers/Point3D.h"
#include "./headers/Triangle.h"
#include "./headers/OBJReader.h"
#include "./headers/OBJWriter.h"
#include "./headers/Triangulation.h"
#include "./headers/ObjToStl.h"
#include "./headers/STLReader.h"
#include "./headers/STLWriter.h"
#include "./headers/StlToObj.h"

typedef vector<Triangle> Triangles;

int main()
{
    try
    {
        
        int choice;
        cout << "enter your choice \n";
        cout << "1. read .stl and write in text file \n";
        cout << "2. read .obj and write in text file \n";
        cout << "3. read .stl and write in .obj file \n";
        cout << "4. read .obj and write in .stl file \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string filepath = "D:/Divyaansh/c++/OBJ Reader/inputfiles/Cube10.stl";
            string filepath1 = "D:/Divyaansh/c++/OBJ Reader/outputfiles/writeSTL.txt";
            Triangulation triangulation;
            STLReader stlReader;
            stlReader.readSTL(filepath,triangulation);

            STLWriter stlWriter;
            stlWriter.writeSTLToFile(filepath1, triangulation);
        }
        break;

        case 2:
        {
            string filepath = "D:/Divyaansh/c++/OBJ Reader/inputfiles/cube.obj";
            string filepath1 = "D:/Divyaansh/c++/OBJ Reader/outputfiles/writeObj.txt";
            Triangulation triangulation;
            OBJReader objReader;
            objReader.readOBJ(filepath,triangulation);

            OBJWriter objWriter;
            objWriter.writeOBJ(filepath1 ,triangulation);
        }
        break;

        case 3:
        {
            string filepath = "D:/Divyaansh/c++/OBJ Reader/inputfiles/Cube10.stl";
            string filepath1 = "D:/Divyaansh/c++/OBJ Reader/outputfiles/StlToObj.obj";
            Triangulation triangulation;
            STLReader stlReader;
            stlReader.readSTL(filepath,triangulation);

            StlToObj stlToObj;
            stlToObj.stlToObjConversion(filepath1,triangulation);
        }
        break;

        case 4:
        {
            string filepath = "D:/Divyaansh/c++/OBJ Reader/inputfiles/cube.obj";
            string filepath1 = "D:/Divyaansh/c++/OBJ Reader/outputfiles/ObjToStl.stl";
            Triangulation triangulation;
            OBJReader objReader;
            objReader.readOBJ(filepath, triangulation);

            ObjToStl objToStl;
            objToStl.objToStlConversion(filepath1, triangulation);
        }
        default:
            break;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}