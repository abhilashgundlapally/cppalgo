#include "randomset.h"
#include <set>
#include <ctime>
#include <vector>
#include <malloc.h>

int * abhi::getRandomNumbers( int begin,  int limit)
{
	std::srand( std::time( 0 ) );
	std::set<int> resultSet;
//	std::vector<int> result;
	int temp;
	int counter = limit;
	while( counter )
	{
		temp = begin + ( std::rand( ) % limit ) ;  
		if( resultSet.find( temp ) == resultSet.end( ) )
		{	
			resultSet.insert( temp );
			--counter;
		}
	}

//	result.clear( );
	//result.reserve( limit );
	int * arr = ( int * ) ( malloc( limit * sizeof(int) ) );
	for( auto val : resultSet )
		arr[--limit] = val;

	return arr;
}
