#include "quicksort.h"
#include <utility>


int abhi::partition(int *a, int left, int right)
{
	int pv = a[left];
	int i = left + 1;
	for( int j = left + 1 ; j <= right ; ++j )
	{
		if( a[j] < pv )
		{
			std::swap<int>( a[j] , a[i] );
			++i;
		}
	}

	std::swap<int>( a[left] , a[i -1] );
	return i - 1;
}

void abhi::quicksort(int *a, int left, int right  )
{
	int pv = abhi::partition( a , left , right );
	if( pv > left )
		quicksort( a , left , pv - 1 );
	if( pv < right )
		quicksort( a , pv + 1 , right );
}
