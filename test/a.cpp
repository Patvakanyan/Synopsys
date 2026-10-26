#include <iostream>
#include <vector>
int main()
{
	std::vector<int> a = {1,3,4};
	int b = a[0]; 
	for(int i = 0; i< a.size(); ++i)
	{
		b ^= a[i];
		if (!b)
		{
			std::cout << "zibil" <<std::endl;
			return 0;
		}
	
	}

}
