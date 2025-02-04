#include "DualDegree.h"

// Remove the class definition and just implement the methods
DualDegree::DualDegree(std::string r, std::string hostel, Faculty facad, float cgpa)
    : Student(r, hostel, facad, cgpa) {}

Faculty DualDegree::getDDPGuide() {
    return DDPGuide;
}

Faculty DualDegree::getTASupervisor() {
    return TASupervisor;
}

void DualDegree::setDDPGuide(Faculty fac) {
    DDPGuide = fac;
}

void DualDegree::setTASupervisor(Faculty fac) {
    TASupervisor = fac;
}