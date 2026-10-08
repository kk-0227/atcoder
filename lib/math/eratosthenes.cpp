#include <vector>
using namespace std;

// エラトステネスの篩
// n以下の各整数が素数かどうかを返す(isprime[i] == true なら i は素数)
// 前提: n >= 0
// 計算量: O(n log log n)
vector<bool> Eratosthenes(int n) {
    vector<bool> isprime(n + 1, true);
    isprime[0] = false;
    if (n >= 1) isprime[1] = false;
    for (long long i = 2; i * i <= n; i++) {
        if (!isprime[i]) continue;                                     // 合成数ならスキップ
        for (long long j = i * i; j <= n; j += i) isprime[j] = false;  // iの倍数を消す
    }
    return isprime;
}