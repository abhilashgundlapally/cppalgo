#include <iostream>
//#include <thread>
//#include "Log.h"

class Log
{
public:
	const int logLevelInfo = 0;
	const int logLevelWarn = 1;
	const int logLevelError = 2;
private:
	int m_logLevel  = logLevelInfo ;
public:
	void setLogLevel( int level )
	{
		m_logLevel = level;
	}


	void info(const char* message)
	{
		std::cout << "[Info]:" << message << std::endl;
	}

	void warn(const char* message)
	{
		std::cout << "[Warning]:" << message << std::endl;
	}


	void error(const char* message)
	{
		std::cout << "[Error]:" << message << std::endl;
	}
};


class Person
{
public:
	virtual void display()
	{
		std::cout << "Display Person" << std::endl;
	}
};

class Aaron : public Person
{
public:
	virtual void display()
	{
		std::cout << "Display Aaron " <<std::endl;
	}
};

class Steve : public Person
{
public:
	virtual void display()
	{
		std::cout << "Display Steve"<<std::endl;
	}
};

class Diamond : public Aaron, Steve
{

};

int main( )
{
	//abhi::Log( "Hello World" );
	//int val = 7;
	//int *ptr = &val;
	//std::cout << *ptr << std::endl;
	/*
	Log log;
	log.setLogLevel( );
	log.warn( "HelloWorld~!" );
	std::cin.get( );
	*/

	Diamond d;
	d.display();
	return 0;
}
