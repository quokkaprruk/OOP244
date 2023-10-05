#include "cstring.h"
namespace sdds {

    void strCpy(char* des, const char* src) {

        int i = 0;

        //loop until meet src[i] == '\0'
        while (src[i] != '\0') {

            //assign src[i] to des[i]
            des[i] = src[i];
            i++;
        }
        //add '\0' at the end of the string
        des[i] = '\0';

    };

    int strLen(const char* s) {
        int len = 0;

        while (s[len] != '\0') {

            //count the len
            len++;
        }
        return len;
    };

    void strCat(char* des, const char* src) {

        int lenDes = 0, lenSrc = 0;

        //get the len of des
        while (des[lenDes] != '\0') {
            lenDes++;
        }


        while (src[lenSrc] != '\0') {
            //assign src[lenSrc] to the end of des[lenDes]
            des[lenDes] = src[lenSrc];

            lenSrc++;
            lenDes++;
        }
        des[lenDes] = '\0';
    };
}