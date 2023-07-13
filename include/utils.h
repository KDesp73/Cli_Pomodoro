#pragma once

#include <string>

using namespace std;

namespace Utils {
    string getExecutablePath();
    string getProjectPath();
    string removeSubstring(string original, string substring);
    string getTask();
    char getCharacter();
};
