#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
    int tail = 1;   // tail is 1 more than string index
    int lastSeenPos[128] = {0}; // value is string index + 1. 0 = null
    int longest = 0;

    for (int head = 1; s[head - 1] != '\0'; head++ ) {   // head is 1 more than string index
        char letter = s[head - 1];
        // if we've seen letter at or after tail, update window
        if (lastSeenPos[letter] >= tail)   {
            tail = lastSeenPos[letter] + 1; // move tail just beyond this letter's previously seen position
        }
        // evaluate window length every loop
        if (longest < head - tail + 1) longest = head - tail + 1;
        lastSeenPos[letter] = head;
    }
    return longest;
}

int main() {
    char* tests[] = {"dvdf", "aab", "abcabcbb", "bbbbb", "pwwkew", " "};
    for (int i = 0; i < 6; i++)
        printf("Input: \"%s\" -> Output: %d\n", tests[i], lengthOfLongestSubstring(tests[i]));
    return 0;
}
