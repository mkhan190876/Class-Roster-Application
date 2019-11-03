#pragma once
#include "degree.h"
#include "student.h"

class SecurityStudent : public Student
{
protected:
	Degree degreeProgram = SECURITY;
public:
	using Student::Student;
	Degree getDegreeProgram() override;
};