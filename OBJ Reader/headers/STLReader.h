#pragma once

#include<map>
#include <string>
#include <vector>
#include "Triangulation.h"


    class STLReader {
public:
    void readSTL(std::string &filePath,Triangulation & triangulation);
};


