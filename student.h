#pragma once
#include <string>
#include "degree.h"
using std::string;

class Student
{
public:
	const static int courseCompletionDaysArraySize = 3;

protected:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[courseCompletionDaysArraySize];
	Degree degreeProgram;

public:
	Student();
	Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree degreeProgram);

	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourse();
	virtual Degree getDegreeProgram() = 0;

	void setStudentId(string studentId);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse[]);
	void setDegree(Degree degreeProgram);

	virtual void print();

	~Student();
};