int hourglassSum(vector<vector<int>> arr) {
    int maxSum = INT_MIN;
    int currentSum;
    
    for(size_t i = 0; i < 4; i++)
    {
        for(size_t j = 0; j < 4; j++)
        {
            currentSum = 0;
            for(size_t ik = i; ik < i + 3; ++ik)
            {
                for(size_t jk = j; jk < j + 3; jk++)
                {
                    if(i + 1==ik)
                    {
                        currentSum+= arr[ik][j + 1];
                        break;
                    }
                    else
                        currentSum+=arr[ik][jk];        
                }
            }
            if(maxSum<currentSum)
                maxSum = currentSum;
        }
    }
    return maxSum;
}

