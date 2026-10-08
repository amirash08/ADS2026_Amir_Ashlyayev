#include <iostream>
using namespace std;

const int MAXN = 5005;

int value[MAXN];
int leftchild[MAXN];
int rightchild[MAXN];

int nodes = 0;

void insertValue(int x) {
    if (nodes == 0) {
        nodes = 1;
        value[1] = x;
        return;
    }

    int current = 1;

    while (true) {
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

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        insertValue(x);
    }

    int leaves = 0;

    for (int i = 1; i <= nodes; i++) {
        if (leftchild[i] == 0 && rightchild[i] == 0)
            leaves++;
    }

    cout << leaves;

    return 0;
}