#include <iostream>
using namespace std;

const int MAXN = 5005;

int value[MAXN];
int leftchild[MAXN];
int rightchild[MAXN];

long long levelSum[MAXN];

int nodes = 0;
int maxDepth = 0;

void insertValue(int x) {
    if (nodes == 0) {
        nodes = 1;
        value[1] = x;

        levelSum[0] += x;
        return;
    }

    int current = 1;
    int depth = 0;

    while (true) {
        if (x < value[current]) {
            if (leftchild[current] == 0) {
                nodes++;

                value[nodes] = x;
                leftchild[current] = nodes;

                depth++;

                levelSum[depth] += x;

                if (depth > maxDepth)
                    maxDepth = depth;

                return;
            }

            current = leftchild[current];
        }
        else {
            if (rightchild[current] == 0) {
                nodes++;

                value[nodes] = x;
                rightchild[current] = nodes;

                depth++;

                levelSum[depth] += x;

                if (depth > maxDepth)
                    maxDepth = depth;

                return;
            }

            current = rightchild[current];
        }

        depth++;
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        insertValue(x);
    }

    cout << maxDepth + 1 << "\n";

    for (int i = 0; i <= maxDepth; i++) {
        cout << levelSum[i];

        if (i != maxDepth)
            cout << " ";
    }

    return 0;
}