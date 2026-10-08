#include <iostream>
using namespace std;

const int MAXV = 100005;

bool existsValue[MAXV];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        existsValue[x] = true;
    }

    if (K > N) {
        cout << -1;
        return 0;
    }

    int count = 0;

    for (int x = 1; x < MAXV; x++) {
        if (existsValue[x]) {
            count++;

            if (count == K) {
                cout << x;
                return 0;
            }
        }
    }

    cout << -1;

    return 0;
}