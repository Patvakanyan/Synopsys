#include "merge.hpp"

void Merge(std::vector<int> &a, std::size_t p, std::size_t q, std::size_t r)
{
	std::size_t nL = q - p + 1;
	std::size_t nR = r - q - 1;
	std::vector<int> L;
	std::vector<int> R;
	L.reserve(nL);
	R.reserve(nR);

	for (std::size_t i = 0; i < nL; i++)
		L.push_back(a[p + i]);

	for (std::size_t i = 0; i < nR; i++)
		R.push_back(a[q + 1 + i]);
	std::size_t il = 0;
	std::size_t ir = 0;
	std::size_t i = p;
	while (il < nL && ir < nR)
	{
		if (L[il] <= R[ir])
		{
			a[i] = L[il];
			il++;
		}
		else
		{
			a[i] = R[ir];
			ir++;
		}
		++i;
	}
	while (il < nL)
	{
		a[i] = L[il];
		++il;
		++i;
	}
	while (ir < nR)
	{
		a[i] = R[ir];
		++ir;
		++i;
	}
}

void mergeSort(std::vector<int> &a, std::size_t p, std::size_t r)
{
	if (p < r)
	{
		std::size_t q = (p + r) / 2;
		mergeSort(a, q + 1, r);
		mergeSort(a, p, q);
		Merge(a, p, q, r);
	}
}
