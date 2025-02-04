#ifndef STUDENT_H
#define STUDENT_H

#include "Faculty.h"
#include <string>

class Student {
    public:
        std::string rollno;
        std::string hostel;
        Faculty facad;
        float cgpa;

        Student(std::string r, std::string hostel, Faculty facad, float cgpa);
        std::string getHostel();
        Faculty getFacad();
        void changeHostel(std::string newhostel);
};

#endif // STUDENT_H 