#include "StudentOffice.h"


void StudentOffice::moveStudent(Student& s, std::string new_program) {
	s.study_program = std::move(new_program);
}


void StudentOffice::enroll_student(Student& s, const Course& c) {
	int ects = s.enrolled_count * 5;
	if (ects + c.get_ects() <= UniversityConstants::MAX_ETCS_PER_YEAR)
		s += c;
}


void StudentOffice::process_exam_results(Student& s) {
	if (s.enrolled_count > 0)
		s.complete_course(0);
}


void StudentOffice::update_student_years(std::vector<Student>& students) {
	for (auto& s : students)
		++s;
}
