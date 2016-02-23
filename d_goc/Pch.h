#ifndef __PCH_HEADER__
#define __PCH_HEADER__

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <stdexcept>
#include <cstring>
#include <map>

#include "log4cxx/propertyconfigurator.h"
#include "log4cxx/helpers/exception.h"

#include "boost/shared_ptr.hpp"
#include "boost/asio.hpp"
#include "boost/bind.hpp"
#include <boost/thread/shared_mutex.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/tss.hpp>

typedef boost::unique_lock<boost::mutex> MutexLock;

#endif
