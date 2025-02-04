#ifndef DUALDEGREE_H
#define DUALDEGREE_H

#include "Student.h"
#include <string>

class DualDegree : public Student {
    public:
        Faculty DDPGuide;
        Faculty TASupervisor;

        DualDegree(std::string r, std::string hostel, Faculty facad, float cgpa);
        Faculty getDDPGuide();
        Faculty getTASupervisor();
        void setDDPGuide(Faculty fac);
        void setTASupervisor(Faculty fac);
};

#endif // DUALDEGREE_H 