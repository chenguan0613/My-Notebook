#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;
const int MAXM = 30;

// 矩阵乘法：a × b → res，大小 m×m
// 因为矩阵是 01 矩阵，加 if(a[i][k]) 剪枝加速
struct Matrix {
    ll a[MAXM][MAXM];
    int sz;

    Matrix(int _sz = 0) {
        sz = _sz;
        memset(a, 0, sizeof(a));
    }

    // 单位矩阵
    static Matrix identity(int sz) {
        Matrix I(sz);
        for (int i = 0; i < sz; i++) I.a[i][i] = 1;
        return I;
    }

    Matrix operator*(const Matrix& b) const {
        Matrix res(sz);
        for (int i = 0; i < sz; i++) {
            for (int k = 0; k < sz; k++) {
                if (a[i][k] == 0) continue;          // 剪枝：跳过 0
                ll aik = a[i][k];
                for (int j = 0; j < sz; j++) {
                    res.a[i][j] = (res.a[i][j] + aik * b.a[k][j]) % MOD;
                }
            }
        }
        return res;
    }
};

// 矩阵快速幂：base^exp
Matrix matPow(Matrix base, ll exp) {
    Matrix res = Matrix::identity(base.sz);
    while (exp > 0) {
        if (exp & 1) res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        ll k;
        cin >> n >> m >> k;
        int s, t;
        cin >> s >> t;
        s--; t--;
        vector<Matrix> A(n, Matrix(m));
        for (int idx = 0; idx < n; idx++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    cin >> A[idx].a[i][j];
                }
            }
        }

        if (k == 0) {
            cout << (s == t ? 1 : 0) << '\n';
            continue;
        }

        vector<Matrix> pref(n + 1);
        pref[0] = Matrix::identity(m);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] * A[i - 1];
        }
        Matrix C = pref[n];

        ll q = k / n;
        int r = (int)(k % n);

        Matrix Cq = matPow(C, q);

        Matrix finalMat = Cq * pref[r];

        cout << finalMat.a[s][t] << '\n';
    }
    return 0;
}
