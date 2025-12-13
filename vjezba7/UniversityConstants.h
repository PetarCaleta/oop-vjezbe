#ifndef UNIVERSITY_CONSTANTS_H
#define UNIVERSITY_CONSTANTS_H


#include <iostream>


struct UniversityConstants {
	static constexpr int MAX_ETCS_PER_YEAR = 60;
	static constexpr int REQUIRED_ECTS_PER_YEAR = 45;


	static void print_university_rules() {
		std::cout << "MAX ECTS: " << MAX_ETCS_PER_YEAR
			<< ", MIN ZA VISU GODINU: "
			<< REQUIRED_ECTS_PER_YEAR << std::endl;
	}
};


#endif
