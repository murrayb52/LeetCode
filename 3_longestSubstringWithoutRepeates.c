#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
    int lastSeen[128] = {0};
    int maxLen = 0;
    int left = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        int c = s[right];
        if (lastSeen[c] > left)
            left = lastSeen[c];
        lastSeen[c] = right + 1;
        if (right - left + 1 > maxLen)
            maxLen = right - left + 1;
    }

    return maxLen;
}

int main() {
    char* tests[] = {"abcabcbb", "bbbbb", "pwwkew"};
    for (int i = 0; i < 3; i++)
        printf("Input: \"%s\" -> Output: %d\n", tests[i], lengthOfLongestSubstring(tests[i]));
    return 0;
}
