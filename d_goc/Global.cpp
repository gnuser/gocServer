#include "Pch.h"
#include "Global.hpp"

using namespace boost::asio;
using namespace std;

io_service &getIoService()
{
	static io_service io;
	return io;
}

