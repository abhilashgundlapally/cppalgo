#include <iostream>
#include <thread>
#include <future>
#include <chrono>
int factorial( std::future<int>& fu )
{
	int res = 1;
	int val = fu.get( );
	while( val )
	{
		res = res * val;
		val--;
	}
	return res;	
}

int main( void )
{
	std::promise<int> p;
	std::future<int> f = p.get_future( );
	//std::future<int> fu = std::async( &factorial , 4 );
	//std::shared_future<int> sf = f.share();
	//can be passed by value
	//useful when broadcast kind of function model
	std::future<int> fu = std::async( std::launch::deferred | std::launch::async, &factorial, std::ref( f ) );
	
	std::this_thread::sleep_for( std::chrono::seconds( 2 ) );
	p.set_value( 4 );
	int val = fu.get( );
	std::cout<< "Dequed : " << val << std::endl;
	return 0;
}