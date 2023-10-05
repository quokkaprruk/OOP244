//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#include "cstring.h"
namespace sdds {

    void strnCpy(char* des, const char* src, int len) {

        int i = 0;

        //loop if meet src[i] != '\0' and i < len
        while (i < len && src[i] != '\0') {
            //assign src[i] to des[i]
            des[i] = src[i];
            i++;
        }

        //if the number of the characters copied is less than "len"
        if (i < len) {
            //des will be null terminated
            des[i] = '\0';
        }

    };

}