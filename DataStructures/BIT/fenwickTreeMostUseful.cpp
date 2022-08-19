template <typename T>
class fenwick {
  vector<T> bit; int N;
public:
  fenwick(int n) { N = n + 5; bit.resize(N);}
  void add(int i, T val) { while (i < N) { bit[i] += val; i += (i & -i);} }
  void add(int l, int r, T val) { add(l, val); add(r + 1, -val);}
  T query(int i) { T ans(0); while (i > 0) { ans += bit[i]; i -= (i & -i); } return ans;} // prefix sum
  T rquery(int l, int r) { return (T)(query(r) - query(l - 1)); } // range sum
  T pquery(int idx) { return (T)(query(idx) - query(idx - 1));}
  int lb(T val) {
    static const int LOG = log2(N); T sum(0); int pos = 0;
    for (int i = LOG; i >= 0; --i) { int calc = pos + (1 << i); if (calc < N && sum + bit[calc] < val) { sum += bit[calc]; pos = calc;}}
    if (pos > N - 5) pos = N - 5; return pos + 1;//// +1 because 'pos' will have position of largest value less than 'v'
  }
};
