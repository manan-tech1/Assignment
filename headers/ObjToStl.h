#pragma once
#include <vector>
#include<string>
#include "Triangle.h"
#include"Triangulation.h"

  class ObjToStl
    {
    public:
        void objToStlConversion(std::string &filePath,Triangulation &triangulation);
    };
