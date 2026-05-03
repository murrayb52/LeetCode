#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* convert(char* s, int numRows) {
    int row = 0;
    bool vertical = true;
    int length = strlen(s);  
    int *rowAssignment = (int *)(malloc(length * sizeof(int)));   // assigns row numbers to letters
    char *returnString = (char *)(malloc(length + 1));

    if (numRows == 1) {
        returnString = s;
    }
    else {
        // determine which row each letter is in
        for (int letter = 0; letter < length; letter++ )  {
            *(rowAssignment + letter) = row;

            // next row management
            if (vertical)   {
                if (row < numRows - 1) {
                    row++;
                }
                else { // reached end of vertical
                    vertical = false;
                    row--;
                }
            }
            else {
                if (row > 0)   {
                    row--;
                }
                else { // reached end of diagnoal
                    vertical = true;
                    row++;
                }
            }
        }

        // traverse through letter assignment and copy into returnString
        int returnStringLetter = 0;
        for (int row = 0; row < numRows; row++ )  {
            for (int letter = 0; letter < length; letter++ ) {
                if (rowAssignment[letter] == row) {
                    *(returnString + returnStringLetter) = s[letter];
                    returnStringLetter++;
                }
            }
        }

        *(returnString + returnStringLetter) = '\0';
    }
    return returnString;
}

int main(void) {
    printf("Input: \"PAYPALISHIRING\", numRows=3 -> %s\n", convert("PAYPALISHIRING", 3)); // PAHNAPLSIIGYIR
    printf("Input: \"PAYPALISHIRING\", numRows=4 -> %s\n", convert("PAYPALISHIRING", 4)); // PINALSIGYAHRPI
    printf("Input: \"A\",              numRows=1 -> %s\n", convert("A", 1));              // A
}