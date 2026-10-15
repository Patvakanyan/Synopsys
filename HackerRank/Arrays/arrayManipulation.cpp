
long arrayManipulation(int n, vector<vector<int>> queries)
{
    vector<long long> arr(n + 2, 0);

    for (size_t i = 0; i < queries.size(); ++i)
    {
        int a = queries[i][0];
        int b = queries[i][1];
        int k = queries[i][2];

        arr[a] += k;
        arr[b + 1] -= k;
    }

    long long current = 0;
    long long maximum = 0;

    for (int i = 1; i <= n; ++i)
    {
        current += arr[i];

        if (current > maximum)
            maximum = current;
    }

    return maximum;
}
