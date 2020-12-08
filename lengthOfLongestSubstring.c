#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char * s){
    int len = strlen(s);
    int i = 0, j = 0, k = 1;
    int max = 0;
    int num = 0;

    for(i=1; i<len; i++) {
        for (j = i; j >=0; j--) {
            k++;
           if (s[i] == s[j]) {
            num++;
            break;
           }
        }

        if (max == 0) {
            max = k;
            k = 1;
        }

        if (max > 0) {
            if (k > max) {
                max = k;
                k = 1;
            }
        }

        i = num;
        k = 1;

    }
}

int main() {
    char str1 = "abcabcbb";
    int len = 0;
    len = lengthOfLongestSubstring(str1);

}