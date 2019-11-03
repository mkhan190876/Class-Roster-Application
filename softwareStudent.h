#pragma once
#include "degree.h"
#include "student.h"

class SoftwareStudent : public Student
{
protected:
	Degree degreeProgram = SOFTWARE;
public:
	using Student::Student;
	Degree getDegreeProgram() override;
};