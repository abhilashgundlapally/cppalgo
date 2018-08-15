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
	/* Thread */
	std::thread th( &factorial , 7 );
	std::this_thread::sleep_for( std::chrono::seconds( 2 ) );

	std::chrono::steady_clock::time_point tp = std::chrono::steady_clock::now( ) + std::chrono::seconds( 2 );
	std::this_thread::sleep_until( tp );

	/* Mutex */
	std::mutex mu;
	std::lock_guard<std::mutex> glock( mu );
	std::unique_lock<std::mutex> ulock( mu );
	ulock.try_lock( );
	ulock.try_lock_for( std::chrono::seconds( 2 ) );
	ulock.try_lock_until( tp );

	/* Condtion variable */
	std::condition_variable cond;
	cond.wait_for( ulock , std::chrono::seconds( 2 ) );
	cond.wait_until( ulock, tp );

	/* Future and Promise */
	std::promise<int> p;
	std::future<int> f = p.get_future( );
	f.get( );
	f.wait( );
	f.wait_for( std::chrono::seconds( 2 ) );
	f.wait_until( tp );

	/* async */
	std::future<int> fa = std::async( factorial , 6 );

	/* Packaged Task */
	std::packaged_task<int(int)> pk_task( factorial  );
	pk_task( 6 );
	std::future<int> fp = pk_task.get_future( );

	return 0;
}