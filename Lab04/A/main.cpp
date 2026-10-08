#include <iostream>
using namespace std;

const int MAXN = 100;

int value [MAXN];
int leftchild[MAXN];
int rightchild[MAXN];

int nodes = 0;

void insertValue(int x) {
    if (nodes == 0){
        nodes = 1;

        value[1] = x;
        leftchild[1] = 0;
        rightchild[1] = 0;  

        return;

    }

    int current = 1;
    int depth = 0;

    while (depth < 100) {
        if (x <= value[current]) {
            if (leftchild[current] == 0) {
                nodes ++;

                value[nodes] = x;
                leftchild[nodes] = 0;
                rightchild[nodes] = 0;
                leftchild[current] = nodes;

                return;
            }

            current= leftchild[current];
        }
        else {

            if (rightchild[current] == 0) {
                nodes ++;

                value[nodes] = x;
                leftchild[nodes] = 0;
                rightchild[nodes] = 0;
                rightchild[current] = nodes;

                return;
            }

            current = rightchild[current];

        }
        depth ++;
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        insertValue(x);

    }

    for (int i = 0; i < M; i++) {
        char path[105];
        cin >> path;

        int current = 1;
        bool exists = true;

        for (int j = 0; path[j] != '\0'; j++){

            if (path[j] == 'L') {
                current = leftchild[current];

            }
            else {
                current = rightchild[current];
            }
            if (current == 0){

                exists = false;
                break;
            }
        }

        if (exists)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}