#ifndef FACULTY_H
#define FACULTY_H

#include <string>

class Faculty {
    public:
        std::string name;
        bool isPerm;

        Faculty(std::string tempname, bool permStat);
        Faculty();
};

#endif // FACULTY_H 