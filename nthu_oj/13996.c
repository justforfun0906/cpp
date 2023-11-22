#include <stdio.h>
#include <string.h>

int main(void) {
    char s[1005];
    scanf("%s", s);

    int len = strlen(s);
    int ans = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 1; i - j >= 0 && i + j < len; j++) {
            if (s[i - j] == s[i + j])
                ans++;
            else
                break;
        }
        if (s[i - 1] != s[i]) continue;
        for (int j = 1; i - j - 1 >= 0 && i + j < len; j++) {
            if (s[i - j - 1] == s[i + j])
                ans++;
            else
                break;
        }
    }
    printf("%d\n", ans);
    return 0;
}