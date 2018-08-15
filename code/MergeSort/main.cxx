#include <iostream>
#include <vector>
#include <chrono>
#include "mergesort.h"

void display( int a[] )
{
	for( int i = 0 ; i < 10 ; ++i  )
	{
		std::cout << a[i] << "->" ;
	}
	std::cout<<'\n';
}



int main( void )
{
	int arr[] = { 5 , 7, 1, 9 , 2, 4, 8, 6, 3 , 0 };
	auto now = std::chrono::high_resolution_clock::now( );
	//display( arr );
	abhi::mergeSort( arr , 0 , 9 );
	display( arr );
	auto end = std::chrono::high_resolution_clock::now( );
	std::cout<< std::chrono::duration_cast<std::chrono::milliseconds>( end - now ).count( )   << std::endl;
	return 0;
}