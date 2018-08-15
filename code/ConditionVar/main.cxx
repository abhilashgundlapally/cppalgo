#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <chrono>
#include <condition_variable>

std::deque<int> g_dq;
std::mutex g_mu;
std::condition_variable g_cond;

void functionOne( )
{
	int count = 10;
	while( count )
	{
		std::unique_lock<std::mutex> locker( g_mu );
		g_dq.push_front( count );
		locker.unlock( );
		g_cond.notify_one( );
		std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
		--count;
	}
}

void functionTwo( )
{
	int data = 0;
	while ( data  != 1 )
	{
		std::unique_lock<std::mutex> locker( g_mu );
		//if( !g_dq.empty( ) )
		//{
		g_cond.wait( locker , [ ]( ){ return !g_dq.empty( ); } );
		data = g_dq.back( );
		g_dq.pop_back( );
		locker.unlock( );
		std::cout<<"Dequed Value : " << data << std::endl;
		//}else
		//{
		//	locker.unlock( );
		//}
	}
}

int main( void )
{
	std::thread thOne( &functionOne );
	std::thread thTwo( &functionTwo );
	thOne.join( );
	thTwo.join( );
	return 0;
}