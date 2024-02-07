// STLWriter.h
#pragma once
#include <string>
#include <vector>
#include "Triangle.h"
#include"Triangulation.h"
#include<map>

    class STLWriter
    {
    public:
        void writeSTLToFile(std::string &filePath ,Triangulation &triangulationObj);
    };
