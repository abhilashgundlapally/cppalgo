#include <iostream>
#include <thread>
#include <future>

int factorial( int val )
{
	int res = 1;
	while( val )
	{
		res = res * val;
		--val;
	}
	return res;
}

int main( void )
{
	//std::packaged_task<int(int)> packaged_task( factorial  );
	std::packaged_task<int( )> packaged_task( std::bind( factorial , 8 ) );

	//packaged_task( 6 );
	//int val = packaged_task.get_future( ).get( );
	return 0;
}