#include <iostream>
using namespace std;

const int MAXN = 1005;

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

int findNode(int x) {
    int current = 1;

    while (current != 0) {
        if (value[current] == x)
            return current;

        if (x < value[current])
            current = leftchild[current];
        else
            current = rightchild[current];
    }

    return 0;
}

void preorder(int v) {
    if (v == 0)
        return;

    cout << value[v] << " ";

    preorder(leftchild[v]);
    preorder(rightchild[v]);
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        insertValue(x);
    }

    int k;
    cin >> k;

    int node = findNode(k);

    preorder(node);

    return 0;
}