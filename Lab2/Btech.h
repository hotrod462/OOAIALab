#ifndef BTECH_H
#define BTECH_H

#include "Student.h"

class Btech : public Student {
    public:
        Faculty BTPGuide;

        Btech(std::string r, std::string hostel, Faculty facad, float cgpa);
        Faculty getBTPGuide();
        void setBTPGuide(Faculty fac);
};

#endif // BTECH_H 