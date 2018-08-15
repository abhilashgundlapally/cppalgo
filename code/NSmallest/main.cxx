#include <iostream>
#include "../QuickSort/quicksort.h"
#include "../RandomNumbers/randomset.h"

int searchNth( int *a ,int left ,int right ,int nth )
{
	int partition = abhi::partition( a , left , right );
	if( nth == partition )
		return a[partition];
	else if( nth < partition )
		return searchNth( a , left , partition -1 , nth );
	else
		return searchNth( a , partition + 1 ,right  , nth );

	return -1;
}

void display( int * ar , int length )
{
	while( length >= 0)
	{
		std::cout<< ar[length ] << "->";
		--length;
	}
}

int main( void )
{
	int arr[] = { 5 , 7, 1, 9 , 2, 4, 8, 6, 3 , 0 };

	int *test = abhi::getRandomNumbers( 77 , 1000 );
	//std::cout << test[3];
	//display( test , 9 );
	std::cout << searchNth( test , 0 , 999 , 50 );
	free( test );
	return 0;
}

