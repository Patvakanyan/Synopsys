vector<int> rotLeft(vector<int> a, int d) {
    vector<int> ret{};
    for(size_t i = d; i < a.size(); ++i)
        ret.push_back(a[i]);
    for(size_t i = 0; i < d; ++i)
        ret.push_back(a[i]);
    return ret;
}

