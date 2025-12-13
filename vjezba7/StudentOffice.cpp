#ifndef STUDENT_H
#define STUDENT_H


#include <string>
#include <iostream>
#include "Course.h"


class StudentOffice; // forward declaration


class Student {
private:
	int id;
	std::string name;
	std::string study_program;
	int year;


	Course* enrolled_courses;
	size_t enrolled_count;


	Course* completed_courses;
	size_t completed_count;


	static int total_students;


	friend class StudentOffice;


public:
	Student();
	Student(int id, const std::string& name,
		const std::string& study_program, int year);


	// Rule of Five
	Student(const Student& other);
	Student(Student&& other) noexcept;
	Student& operator=(const Student& other);
	Student& operator=(Student&& other) noexcept;
	~Student();


	static int get_total_students();


	void enroll_course(const Course& c);
	void complete_course(size_t index);


	Student& operator+=(const Course& c);
	Student& operator++(); // prefiks
	Student operator++(int); // postfiks


	friend std::ostream& operator<<(std::ostream& os, const Student& s);
	friend std::istream& operator>>(std::istream& is, Student& s);
};


#endif
