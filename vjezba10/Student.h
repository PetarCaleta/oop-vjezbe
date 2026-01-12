#ifndef STUDENT_H
#define STUDENT_H

#include <string>

namespace student_records {

    struct Student {
        std::string ime;
        std::string prezime;
        int bodovi;
    };

    inline int bodovi_u_ocjenu(int b) {
        if (b < 40) return 1;
        if (b < 55) return 2;
        if (b < 70) return 3;
        if (b < 85) return 4;
        return 5;
    }

}

#endif