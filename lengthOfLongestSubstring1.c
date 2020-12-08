/*
程序的大体思路：
    1、从字符串的第二个元素开始向前遍历，如果有相同的字符，则获取该子字符串的长度
    2、跟之前获取的子字符串比较大小，如果大则替换，否则不做处理
    3、字符串长度为0或是1的，则单独处理
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char *s){
    int len = strlen(s);  //  求字符串的长度
    printf("len:%d\n", len);
    int i = 0, j = 0, k = 1; //  k为每次循环获取的字符串的长度
    int max = 0;    //  最大子字符串的长度
    int num = 0;   //  求出相同字符的下标
    int flag = 0;   //  标识，判断字符串中是否有相同的字符

    if ((len == 0) || (len == 1)) {   //  如果字符串长度位0或是1，则直接返回
        printf("AAAA\n");
        max = len;
    }

    if (len >= 2) { // 如果字符串的长度为2，则进行处理
        for(i=1; i<len; i++) {
            for (j = i - 1; j >=num; j--) {
                if (s[i] == s[j]) {
                    flag = 1;
                    if (max == 0) {
                        k = i;
                        printf("k0:%d\n", k);
                    }
                    if (max > 0) {
                        k = i - num;
                        printf("k0 2:%d\n", k);
                    }
                    printf("k1:%d\n", k);
                    i = j;
                    num = j+1;
                    break;
               }
               if ((flag == 0) && (i == (len - 1)) && (j == num)) {
                    flag = 1;
                    k = len - num;
                    printf("i == len :%d\n", k);
                }
            }

            if (flag == 1) {
                flag = 0;
                if (max == 0) {
                    max = k;
                    k = 1;
                }

                if (max > 0) {
                    if (k > max) {
                        printf("max k:%d\n", k);
                        max = k;
                        k = 1;
                    }
                    else {
                        k = 1;
                    }
                }
            }
        }
    }

    printf("max:%d\n", max);
    return max;
}

int main() {
    //char str1[] = "abcabcbb";
    //char str1[] = "au";
    //char str1[] = "abcb";
    char str1[] = "ohomm";
    int len = 0;
    len = lengthOfLongestSubstring(str1);
    printf("len:%d\n", len);

}