#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;

const int MAXLEN = 5000;


int main() {
    char string[MAXLEN];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", string);
        int len = strlen(string);
        if (len == 1) {
            printf("%s\n", string);
        } else if (len == 2) {
            printf("%c\n", string[1]);
        } else {
            char minc = 127;
            for (int j = 0; j < len; ++j) {
                minc = min(minc, string[j]);
            }
            printf("%c\n", minc);
        }
    }
    
    return 0;
}

