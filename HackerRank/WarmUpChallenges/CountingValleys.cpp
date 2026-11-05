int countingValleys(int steps, string path)
{
	int ret = 0;
	int tmpHigh = 0;
	for (int i = 0; i < steps; ++i)
	{
		if (path[i] == 'U' && tmpHigh + 1 == 0)
		{
			cout << tmpHigh << "I" << i << endl;
			ret++;
		}
		if (path[i] == 'U')
			tmpHigh++;
		else
			tmpHigh--;
	}
	return ret;
}
