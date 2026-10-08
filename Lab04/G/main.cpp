#include <iostream>
using namespace std;

const int MAXN = 20005;

int value[MAXN];
int leftchild[MAXN];
int rightchild[MAXN];

int nodes = 0;
int answer = 0;

void insertValue(int x) {
    if (nodes == 0) {
        nodes = 1;
        value[1] = x;
        return;
    }

    int current = 1;

    while (true) {
        if (x == value[current]) {
            return;
        }

        if (x < value[current]) {
            if (leftchild[current] == 0) {
                nodes++;

                value[nodes] = x;
                leftchild[current] = nodes;

                return;
            }

            current = leftchild[current];
        }
        else {
            if (rightchild[current] == 0) {
                nodes++;

                value[nodes] = x;
                rightchild[current] = nodes;

                return;
            }

            current = rightchild[current];
        }
    }
}

int height(int v) {
    if (v == 0)
        return 0;

    int leftHeight = height(leftchild[v]);
    int rightHeight = height(rightchild[v]);

    int path = leftHeight + rightHeight + 1;

    if (path > answer)
        answer = path;

    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        insertValue(x);
    }

    height(1);

    cout << answer;

    return 0;
}