#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "roster.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

int main() {
	std::cout << "C-867 SCRIPTING AND PROGRAMMING APPLICATIONS" << std::endl;
	std::cout << "C++, Mohammed Khan, STUDENTID: #001107593\n" << std::endl;

	Roster classRoster;
	Degree degreeProgram;

	string output, col[DATA_COLUMNS];

	for (int i = 0; i < NUMBER_OF_STUDENTS; ++i)
	{
		std::istringstream input(studentData[i]);
		for (int j = 0; j < DATA_COLUMNS; ++j) {
			std::getline(input, output, ',');
			col[j] = output;
		}

		switch (col[8][2]) {
		case 'T':
			degreeProgram = NETWORK;
			break;
		case 'C':
			degreeProgram = SECURITY;
			break;
		case 'F':
			degreeProgram = SOFTWARE;
			break;
		}

		classRoster.add(col[0], col[1], col[2], col[3], std::stoi(col[4]), std::stoi(col[5]), std::stoi(col[6]), std::stoi(col[7]), degreeProgram);
	}

	std::cout << "Roster:" << std::endl;
	classRoster.printAll();
	std::cout << std::endl;

	std::cout << "Invalid emails:" << std::endl;
	classRoster.printInvalidEmails();
	std::cout << std::endl;

	std::cout << "Average days in course by student ID:" << std::endl;
	for (int i = 0; i < NUMBER_OF_STUDENTS; ++i) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentId());
	}
	std::cout << std::endl;

	std::cout << "Students in degree program SOFTWARE:" << std::endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	std::cout << std::endl;

	classRoster.remove("A3");
	classRoster.remove("A3");
	std::cout << std::endl;

	std::cout << "Roster:" << std::endl;
	classRoster.printAll();
	std::cout << std::endl;

	classRoster.~Roster();

	system("PAUSE");
	return 0;
}

void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram) {
	int daysInCourse[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	Student* student = nullptr;

	switch (degreeProgram) {
	case NETWORK:
		student = new NetworkStudent(studentId, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
		break;
	case SECURITY:
		student = new SecurityStudent(studentId, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
		break;
	case SOFTWARE:
		student = new SoftwareStudent(studentId, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
		break;
	}

	for (int i = 0; i < NUMBER_OF_STUDENTS; ++i) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = student;
			break;
		}
	}
};

void Roster::remove(string studentId) {
	std::cout << "Removing student with ID " << studentId << "... " << std::flush;
	for (int i = 0; i < NUMBER_OF_STUDENTS; ++i) {
		if (classRosterArray[i] == nullptr) {
			std::cout << "ERROR: Student with this ID not found" << std::endl;
			break;
		}
		else if (studentId == classRosterArray[i]->getStudentId()) {
			classRosterArray[i] = nullptr;
			std::cout << "Student removed" << std::endl;
		}
	}
};

void Roster::printAll() {
	for (int i = 0; i < NUMBER_OF_STUDENTS; ++i) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
};

void Roster::printAverageDaysInCourse(string studentId) {
	for (int i = 0; i < NUMBER_OF_STUDENTS; ++i) {
		if (studentId == classRosterArray[i]->getStudentId()) {
			int* days = classRosterArray[i]->getDaysInCourse();
			std::cout << studentId << "\t";
			std::cout << std::setprecision(3) << (((float)days[0] + (float)days[1] + (float)days[2]) / 3) << std::endl;
		}
	}
};

void Roster::printInvalidEmails() {
	bool valid = false;
	for (int i = 0; i < NUMBER_OF_STUDENTS; ++i) {
		if (classRosterArray[i] == nullptr) {
			continue;
		}
		valid = false;
		string email = classRosterArray[i]->getEmailAddress();
		size_t emailLength = email.size();
		size_t j = 0;
		while (email[j] != ' ' && email[j] != '@' && j < emailLength) {
			++j;
			if (email[j] == '@' && j < emailLength) {
				++j;
				while (email[j] != ' ' && email[j] != '@' && email[j] != '.' && j < emailLength) {
					++j;
					if (email[j] == '.' && j < emailLength) {
						++j;
						while (email[j] != ' ' && email[j] != '@' && email[j] != '.' && j < emailLength) {
							++j;
							if (j == emailLength) {
								valid = true;
							}
						}
					}
				}
			}
		}
		if (valid == false) {
			std::cout << email << std::endl;
		}
	}
};

void Roster::printByDegreeProgram(Degree degreeProgram) {
	for (int i = 0; i < NUMBER_OF_STUDENTS; ++i) {
		Student* student = classRosterArray[i];
		if (student->getDegreeProgram() == degreeProgram) {
			student->print();
		}
	}
};

Roster::~Roster() {

};