#include <iostream>
using namespace std;

const int MAXN = 105;

int value[MAXN];
int leftchild[MAXN];
int rightchild[MAXN];

long long result[MAXN];

int nodes = 0;
int resultSize = 0;

long long sum = 0;

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

void reverseInorder(int v) {
    if (v == 0)
        return;

    reverseInorder(rightchild[v]);

    sum += value[v];

    result[resultSize] = sum;
    resultSize++;

    reverseInorder(leftchild[v]);
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        insertValue(x);
    }

    reverseInorder(1);

    for (int i = 0; i < resultSize; i++) {
        cout << result[i];

        if (i + 1 < resultSize)
            cout << " ";
    }

    return 0;
}