// 二項係数 nCr (mod p) を、前処理 O(N)・1回あたり O(1) で求める
// 前提: mintが定義済みで、modが素数 (modint998244353 など)。割り算に逆元を使うため
// 使い方:
//   Combination comb(N);  // 0以上N以下のnについて使える
//   comb.C(n, r);         // nCr を mint で返す (r < 0 または r > n なら 0)
struct Combination{
	vector<mint> fact, inv_fact; // fact[i] : i! , inv_fact[i] : i! の逆元
	Combination(int N) : fact(N + 1), inv_fact(N + 1){
		fact[0] = 1;
		for(int i = 1; i <= N; i++)fact[i] = fact[i - 1] * i;
		inv_fact[N] = fact[N].inv(); // 逆元の計算は最後の1回だけ
		for(int i = N; i > 0; i--)inv_fact[i - 1] = inv_fact[i] * i; // (i-1)! の逆元 = i! の逆元 × i
	}
	
	mint C(int n, int r){ // nCr = n! / (r! (n-r)!)
		if(r < 0 || r > n)return 0;
		return fact[n] * inv_fact[r] * inv_fact[n - r];
	}
};