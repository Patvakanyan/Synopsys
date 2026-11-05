int sockMerchant(int n, vector<int> ar) {
    unordered_map<int, int> ret;
    int pairs = 0;
    for(size_t i = 0; i < ar.size(); i++)
    {
        ret[ar[i]]++;
        if (ret[ar[i]] == 2)
        {
            pairs++;
            ret[ar[i]] = 0;
        }
    }
    return pairs;
}
