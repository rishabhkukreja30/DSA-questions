bool isSafe(int node, int color[], bool graph[][101], int V, int col) {
    for(int k=0;k<V;k++) {
        if(k != node and graph[k][node] == 1 and color[k] == col) {
            return false;
        }
    }
    return  true;
}

bool solve (int node, int color[], int m, int V, bool graph[101][101]) {
    if(node == V)  {
        return true;
    }
    
    for(int i=1;i<=m;i++) {
        if(isSafe(node, color, graph, V, i)) {
            color[node] = i;
            if(solve(node+1, color, m, V, graph)) {
                return true;
            }
            color[node] = 0;
        }
    }
    return false;
}



bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    int color[V] = {0};
    
    if(solve(0,color, m, V, graph)) {
        return true;
    }
    return false;

}