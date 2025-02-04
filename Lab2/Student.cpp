#include "Student.h"
#include <string>

Student::Student(std::string r, std::string hostel, Faculty facad, float cgpa) {
    rollno = r;
    this->hostel = hostel;
    this->facad = facad;
    this->cgpa = cgpa;
}

std::string Student::getHostel() {
    return hostel;
}

Faculty Student::getFacad() {
    return facad;
}

void Student::changeHostel(std::string newhostel) {
    hostel = newhostel;
}