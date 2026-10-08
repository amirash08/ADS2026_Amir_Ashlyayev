#include <iostream>
using namespace std;

const int MAXN = 1005;

int leftchild[MAXN];
int rightchild[MAXN];

int levelCount[MAXN];

int maxWidth = 0;

void dfs(int v, int depth) {
    if (v == 0)
        return;

    levelCount[depth]++;

    if (levelCount[depth] > maxWidth)
        maxWidth = levelCount[depth];

    dfs(leftchild[v], depth + 1);
    dfs(rightchild[v], depth + 1);
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        if (z == 0)
            leftchild[x] = y;
        else
            rightchild[x] = y;
    }

    dfs(1, 0);

    cout << maxWidth;

    return 0;
}