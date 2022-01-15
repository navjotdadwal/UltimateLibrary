void dfs(int v,int p) {
    for (int u : adj[v]) {
        if(u==p) continue;
            dfs(u);
    }
}
