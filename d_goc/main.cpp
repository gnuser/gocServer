#include "Pch.h"
#include <pthread.h>
#include <boost/program_options.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>


namespace po = boost::program_options;
using namespace std;
using namespace boost::asio;


int main(int argc, char** argv)
{
	string configFile;
	string logConfig;

	po::options_description desc("Allowed options");
	desc.add_options()
		("help,h", "produce help message")
		("config_file,f", po::value<string>(&configFile)->default_value("config_oqc.json"), "Specify a configuration file")
		("log_config,l", po::value<string>(&logConfig)->default_value("./oqc.log.config"), "Specify a log configuration")
		;
	po::variables_map vm;
	po::store(po::command_line_parser(argc, argv).options(desc).run(), vm);	
	po::notify(vm);

	if (vm.count("help")) {
		cout << desc << "\n";
		return EXIT_SUCCESS;
	}

	setlocale(LC_ALL, "");		
	try
	{
		log4cxx::PropertyConfigurator::configure(logConfig);
	}
	catch (...)
	{
		std::cerr << "Failed to load log configuration file" << std::endl;
		return EXIT_FAILURE;
	}

	// load json config
	//map<string, string> configMap = readJsonFile(configFile);

	sigset_t wait_mask;
	sigemptyset(&wait_mask);
	sigaddset(&wait_mask, SIGINT);
	sigaddset(&wait_mask, SIGQUIT);
	sigaddset(&wait_mask, SIGTERM);
	pthread_sigmask(SIG_BLOCK, &wait_mask, 0);
	int sig = 0;
	sigwait(&wait_mask, &sig);

	return 0;
}