#pragma once
#include "degree.h"
#include "student.h"

class NetworkStudent : public Student
{
protected:
	Degree degreeProgram = NETWORK;
public:
	using Student::Student;
	Degree getDegreeProgram() override;
};