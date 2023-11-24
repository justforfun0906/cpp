#include <stdio.h>
#include <string.h>
#define MAXN 1005
#define MAXLEN 305

int N, K;
int cnt[MAXN] = {0}, len[MAXN] = {0};
char d[MAXN][MAXLEN] = {'\0'};
int ans[MAXN]; //for the sorted cookies


//check if "idx_a" > "idx_b" in terms of both # of ‘7’s and di values:
//if "idx_a" > "idx_b", then for "idx_a"
//  1. less ‘7’s
//  2. smaller di (under same # of ‘7’s)
int cmp_1(int idx_a, int idx_b) {
    if (cnt[idx_a] < cnt[idx_b]) return 1;
    else if (cnt[idx_a] > cnt[idx_b]) return -1; 
    else { //equal # of ‘7’s
        if (len[idx_a] < len[idx_b]) return 1;
        else if (len[idx_a] > len[idx_b]) return -1;
        else { //equal length
            int res = strcmp(d[idx_a], d[idx_b]); 
            if (res < 0) return 1;
            else if (res > 0) return -1;
            else return 0; //the same
        }
    }
}

//phase 1: sort the whole N cookies
void bubble_sort_1() {
    for (int i = 0; i < N-1; ++i) {
        for (int j = 0; j < N-1-i; ++j) {
            if(cmp_1(ans[j],ans[j+1])>0) {
                int temp = ans[j];
                ans[j] = ans[j+1];
                ans[j+1] = temp;
            }
        }
    }
}

//check if "idx_a" > "idx_b" in terms of di values only:
//if "idx_a" > "idx_b", then for "idx_a"
//  1. larger di
int cmp_2(int idx_a, int idx_b) {
    if (len[idx_a] > len[idx_b]) return 1;
    else if (len[idx_a] < len[idx_b]) return -1;
    else return strcmp(d[idx_a], d[idx_b]); //equal length
}

//phase 2: sort the first K cookies
void bubble_sort_2() {
    for (int i = 0; i < K-1; ++i) {
        for (int j = 0; j < K-1-i; ++j) {
            if(cmp_2(ans[j],ans[j+1])>0) {
                int temp = ans[j];
                ans[j] = ans[j+1];
                ans[j+1] = temp;
            }
        }
    }
}

void find_ans() {
    for (int j = 0; j < N; ++j)
        ans[j] = j;

    bubble_sort_1();
    bubble_sort_2();
}

void hex_to_dec(char* input, int n) {
    for (int i = 0, j = 0; input[j] != '\0'; i = j+1) {
        j = i;
        while (input[j] != '|' && input[j] != '\0') j++;

        int num = 0;
        char str_hex[15]={'\0'};
        char str_dec[15]={'\0'};
        strncpy(str_hex, input+i,j-i); //input[i]~input[j-1] form "hec"
        sscanf(str_hex, "%x", &num); //use sscanf and sprintf
        sprintf(str_dec, "%d", num); //    to transform "hec" to "dec"
        strcat(d[n], str_dec);
    }
    len[n]=strlen(d[n]);
    for (int pos = 0; pos < len[n]; ++pos) {
        if (d[n][pos] == '7') cnt[n]++;
    }
}

int main() {
    scanf("%d %d", &N, &K);
    char input[255];
    for (int i = 0; i < N; ++i) {
        scanf("%s", input);
        hex_to_dec(input, i);
    }

    find_ans();
    for (int i = 0; i < N; ++i)
        printf("%s\n", d[i]);

    return 0;
}
