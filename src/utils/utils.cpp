#include "utils.h"
#include "cli_kit.h"


#include <iostream>
#include <string>
#ifdef _WIN32
    #include <conio.h>
    #include <Windows.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif


using namespace std;
using namespace CliKit;

std::string Utils::getExecutablePath() {
    char buffer[1024];
    std::string path;
#ifdef _WIN32
    GetModuleFileName(NULL, buffer, sizeof(buffer));
    path = buffer;
#else
    ssize_t len = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
    if (len != -1) {
        buffer[len] = '\0';
        path = buffer;
    }
#endif
    return path;
}

std::string Utils::getProjectPath() {
    std::string executablePath = getExecutablePath();
    std::size_t found = executablePath.find_last_of("/\\");
    if (found != std::string::npos) {
        return executablePath.substr(0, found);
    }
    return "";
}

std::string Utils::removeSubstring(string original, string substring) {
    std::string result = original;
    std::size_t found = result.find(substring);
    while (found != std::string::npos) {
        result.erase(found, substring.length());
        found = result.find(substring, found);
    }
    return result;
}


string Utils::getTask(){
    string task;
    cout << Text::red << "Task: " << Text::normal;
    getline(cin, task);

    return task;
}

char Utils::getCharacter() {
#ifdef _WIN32
    return _getch();
#else
    char buf = 0;
    struct termios old{};
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return buf;
#endif
}
