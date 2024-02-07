#pragma once
#include <vector>
#include<string>
#include "Triangle.h"
#include"Triangulation.h"


    class OBJWriter
    {
    public:
        void writeOBJ(std::string &filePath,Triangulation &triangulation);
    };
