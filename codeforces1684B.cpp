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
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a,b,c;
        scanf("%d%d%d", &a, &b, &c);
        int z = c;
        int y = b;
        int k = c / b + 1;
        int x = a + k * b;
        printf("%d %d %d\n", x, y, z);
    }
    return 0;
}

