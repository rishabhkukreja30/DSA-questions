long long int maxHistogramArea(vector<long long int> &a)
{
    stack<long long int> s;
    long long int maxArea = 0;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            s.push(i);
        }
        else
        {
            while (!s.empty() && a[i] < a[s.top()])
            {
                long long int x = s.top();
                s.pop();
                long long int area = 0;
                if (s.empty())
                    area = a[x] * i;
                else
                    area = a[x] * (i - s.top() - 1);
                maxArea = max(area, maxArea);
            }
            s.push(i);
        }
    }
    while (!s.empty())
    {
        long long int area = 0;
        long long int x = s.top();
        s.pop();
        if (s.empty())
        {
            area = a[x] * n;
        }
        else
        {
            area = a[x] * (n - x);
        }

        maxArea = max(area, maxArea);
    }

    return maxArea;
}






