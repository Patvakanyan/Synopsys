long repeatedString(string s, long n) {
    int count = 0;
    for(size_t i = 0; i < s.length(); ++i)
    {
        if (s[i]=='a')
            count++;
    }
    long fully = (n / s.length()) * count;
    int repeated = n % s.length();
    count = 0;
    for(size_t i = 0; i < repeated; ++i)
    {
        if(s[i]=='a')
            count++;
    }
    return count + fully;
}

