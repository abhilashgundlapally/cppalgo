#include <iostream>
#include <thread>
class Functor
{
public:
	int f( int  , char ){ return 0;};
	int g( double ){ return 0; };
	int operator()( int val ){ return val ;}
};

struct Node
{
	int i;
	float f;
	double d;
	bool b;
};

int foo( int val ){ return val; }
int main( void )
{
	Functor f;
	std::thread t1( f , 6 ); // copy_of_f 
	std::thread t2( std::ref( f ) , 6 );
	//std::thread t3(  std::move( f )  , 6 );
	std::thread t4(  Functor( ) , 6 );
	std::thread t5( [](int val){ return val*val ; } , 6 );

	std::thread t6( &foo , 6 );
	std::thread t7( &Functor::f, f, 6 , 'A' );
	std::thread t8( &Functor::f, &f, 6 , 'B' );

	t1.join( );
	t2.join( );
	//t3.join( );
	t4.join( );
	t5.join( );
	t6.join( );
	t7.join( );
	t8.join( );

	//std::async
	//std::bind
	//std::call_once

	//int val = (int)((Node *)nullptr)->d;
	//std::cout <<  val <<std::endl;

	return 0;
}