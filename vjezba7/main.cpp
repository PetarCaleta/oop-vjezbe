#include <vector>
#include <iostream>
#include "Student.h"
#include "StudentOffice.h"


int main() {
	UniversityConstants::print_university_rules();


	Course c("Programiranje", "PRG", 5);
	Student s1(1, "Ana", "Racunarstvo", 1);


	for (int i = 0; i < 9; ++i)
		StudentOffice::enroll_student(s1, c);


	for (int i = 0; i < 9; ++i)
		StudentOffice::process_exam_results(s1);


	++s1;


	std::vector<Student> studenti{ s1 };
	StudentOffice::update_student_years(studenti);


	for (auto& s : studenti)
		std::cout << s << std::endl;


	std::cout << "Ukupno studenata: "
		<< Student::get_total_students() << std::endl;


	return 0;
}
