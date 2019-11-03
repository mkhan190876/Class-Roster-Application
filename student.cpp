#include <iostream>
#include "student.h"

Student::Student()
{
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = -1;
	for (int i = 0; i < courseCompletionDaysArraySize; i++) this->daysInCourse[i] = 0;
}

Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree degreeProgram)
{
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < courseCompletionDaysArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
}

string Student::getStudentId()
{
	return studentId;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmailAddress()
{
	return emailAddress;
}

int Student::getAge()
{
	return age;
}

int* Student::getDaysInCourse()
{
	return daysInCourse;
}

Degree Student::getDegreeProgram()
{
	return degreeProgram;
}

void Student::setStudentId(string studentId)
{
	this->studentId = studentId;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress)
{
	this->emailAddress = emailAddress;
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setDaysInCourse(int daysInCourse[])
{
	for (int i = 0; i < courseCompletionDaysArraySize; i++)
		this->daysInCourse[i] = daysInCourse[i];
}

void Student::print() {
	std::cout << getStudentId();
	std::cout << "\tFirst name: " << getFirstName();
	std::cout << "\tLast name: " << getLastName();
	std::cout << "\tAge: " << getAge();

	int* days = getDaysInCourse();
	std::cout << "\t  Days in course: " << days[0] << ", " << days[1] << ", " << days[2];

	string degreeString = "";
	switch (getDegreeProgram()) {
	case NETWORK:
		degreeString = "NETWORK";
		break;
	case SECURITY:
		degreeString = "SECURITY";
		break;
	case SOFTWARE:
		degreeString = "SOFTWARE";
		break;
	}
	std::cout << "\tDegree: " << degreeString << std::endl;
}

Student::~Student()
{

}