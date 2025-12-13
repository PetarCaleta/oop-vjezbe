#include "Student.h"
#include "UniversityConstants.h"


int Student::total_students = 0;


Student::Student()
	: id(0), name(""), study_program(""), year(1),
	enrolled_courses(nullptr), enrolled_count(0),
	completed_courses(nullptr), completed_count(0) {
	++total_students;
}


Student::Student(int id, const std::string& name,
	const std::string& study_program, int year)
	: id(id), name(name), study_program(study_program), year(year),
	enrolled_courses(nullptr), enrolled_count(0),
	completed_courses(nullptr), completed_count(0) {
	++total_students;
}


Student::Student(const Student& o)
	: id(o.id), name(o.name), study_program(o.study_program), year(o.year),
	enrolled_count(o.enrolled_count), completed_count(o.completed_count) {


	enrolled_courses = enrolled_count ? new Course[enrolled_count] : nullptr;
	for (size_t i = 0; i < enrolled_count; ++i)
		enrolled_courses[i] = o.enrolled_courses[i];


	completed_courses = completed_count ? new Course[completed_count] : nullptr;
	for (size_t i = 0; i < completed_count; ++i)
		completed_courses[i] = o.completed_courses[i];


	++total_students;
}


Student::Student(Student&& o) noexcept
	: id(o.id), name(std::move(o.name)), study_program(std::move(o.study_program)),
	year(o.year), enrolled_courses(o.enrolled_courses), enrolled_count(o.enrolled_count),
	completed_courses(o.completed_courses), completed_count(o.completed_count) {


	o.enrolled_courses = nullptr;
	o.completed_courses = nullptr;
	o.enrolled_count = o.completed_count = 0;
	++total_students;
}


Student& Student::operator=(const Student& o) {
	if (this != &o) {
		delete[] enrolled_courses;
		delete[] completed_courses;


		id = o.id;
		name = o.name;
		study_program = o.study_program;
		year = o.year;


		enrolled_count = o.enrolled_count;
		completed_count = o.completed_count;


		enrolled_courses = enrolled_count ? new Course[enrolled_count] : nullptr;
		for (size_t i = 0; i < enrolled_count; ++i)
			enrolled_courses[i] = o.enrolled_courses[i];


		completed_courses = completed_count ? new Course[completed_count] : nullptr;
		for (size_t i = 0; i < completed_count; ++i)
			completed_courses[i] = o.completed_courses[i];
	}
	return *this;
}


Student& Student::operator=(Student&& o) noexcept {
	if (this != &o) {
		delete[] enrolled_courses;
		delete[] completed_courses;


		id = o.id;
		name = std::move(o.name);
		study_program = std::move(o.study_program);
		year = o.year;


		enrolled_courses = o.enrolled_courses;
		completed_courses = o.completed_courses;
		enrolled_count = o.enrolled_count;
		completed_count = o.completed_count;


		o.enrolled_courses = nullptr;
	}
