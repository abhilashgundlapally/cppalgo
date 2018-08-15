#include "mergesort.h"
#include <vector>

void abhi::sort(int a[], int left, int pivot, int right)
{
	int p = left , q = pivot + 1;
	std::vector<int> res;
	int size = right - left + 1;
	res.reserve( size );

	while( size )
	{
		if( p > pivot )
		{
			res.push_back( a[q] );
			q++;
		}
		else if( q > right )
		{
			res.push_back( a[p] );
			p++;
		}
		else if( a[ p ]  < a[ q ])
		{	
			res.push_back( a[p] );
			p++;
		}
		else
		{
			res.push_back( a[q] );
			q++;
		}

		--size;
	}

	for( auto val : res)
	{
		a[left] = val;
		left++;
	}


}

void abhi::mergeSort(int arr[], int left, int right)
{
	if( left < right )
	{
		int pivot = left + ( ( right - left ) / 2 );
		mergeSort( arr , left , pivot );
		mergeSort( arr , pivot + 1 , right );
		abhi::sort( arr , left , pivot , right  );
	}
}

