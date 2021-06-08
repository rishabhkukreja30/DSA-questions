int getId(int M[MAX][MAX], int n)
{
    //Your code here
    stack <int> s;
    int celebrity;
    for(int i=0;i<n;i++)
        s.push(i);
    while(s.size()>=2)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if(M[a][b]  == 1 )
            s.push(b);
        else
            s.push(a);
    }        
         celebrity = s.top();
         s.pop();
        for(int i=0;i<n;i++) {
            if(i != celebrity) {
                if(M[i][celebrity] == 0 || M[celebrity][i] == 1) {
                    return -1;
                }
            }
        }
    
    return celebrity;
    
}