#include <stdio.h>
#include <string.h>

int main() {
    char a[10005], b[10005];
    scanf("%s %s", a, b);
    
    int n = strlen(a);
    int m = strlen(b);
    
    int pref_suf = 0;
    int suf_pref = 0;
    
    int max1 = n < m ? n : m;
    for (int len = 1; len <= max1; len++) {
        int ok = 1;
        for (int i = 0; i < len; i++) {
            if (a[i] != b[m - len + i]) {
                ok = 0;
                break;
            }
        }
        if (ok) pref_suf = len;
    }
    
    int max2 = n < m ? n : m;
    for (int len = 1; len <= max2; len++) {
        int ok = 1;
        for (int i = 0; i < len; i++) {
            if (a[n - len + i] != b[i]) {
                ok = 0;
                break;
            }
        }
        if (ok) suf_pref = len;
    }
    
    printf("%d %d\n", pref_suf, suf_pref);
    return 0;
}