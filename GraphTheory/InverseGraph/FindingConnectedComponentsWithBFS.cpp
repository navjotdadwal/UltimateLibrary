void solve(int test_case = 0)
{
    int n; cin >> n;
    int m; cin >> m;
    vector<set<int>> adj(n);
    set<int> toremove;
    queue<int> bfs;
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    vector<int> todo;
    for(int i = 0; i < n; ++i)
        toremove.insert(i);
    int ccs = 0;
    for(int i = 0; i < n; ++i) {
        if(toremove.count(i)) {
            bfs.push(i);
            ++ccs;
            toremove.erase(i);
            while(bfs.size()) {
                int x = bfs.front();
                bfs.pop();
                todo.clear();
                for(int j : toremove)
                    if(!adj[x].count(j)) 
                        todo.pb(j);
                for(int j : todo)
                    toremove.erase(j), bfs.push(j);
                
            }       
        }
    }
 
    cout << ccs - 1 << "\n";
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // C++ IO Stuff
    int T = 1;
#ifdef runcase
    cin >> T;
#endif
    // new test cases
    for(int nt = 0, i; nt < T; nt++) {
        solve(nt);
        ++i;
    }
}
