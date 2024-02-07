#pragma once
#include <vector>
#include<string>
#include "Triangulation.h"


 class OBJReader
    {
    public:
        void readOBJ(std::string &filePath,Triangulation &triangulation);
    };
