int jumpingOnClouds(vector<int> c)
{
    int count = 0;
    size_t i = 0;

    while (i < c.size() - 1)
    {
        if (i + 2 < c.size() && c[i + 2] == 0)
            i += 2;
        else
            i++;

        count++;
    }

    return count;
}
