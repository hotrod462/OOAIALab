#include "Btech.h"

Btech::Btech(std::string r, std::string hostel, Faculty facad, float cgpa) 
    : Student(r, hostel, facad, cgpa) {}

Faculty Btech::getBTPGuide() {
    return BTPGuide;
}

void Btech::setBTPGuide(Faculty fac) {
    BTPGuide = fac;
}