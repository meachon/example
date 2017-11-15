#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */
#include <getopt.h>
#include <string>
#include <map>
#include <iostream>
//#include <algorithm>
#include <functional>


class SubCommand
{
public:
	SubCommand()
	{
		
	};
	~SubCommand(){};
	
	int run(const std::string action, int argc, char **argv)
	{
		func_name_map[action](argc,argv);
	};
	
	virtual int parse_parameter(int argc, char **argv) = 0;
	
	std::map<std::string, std::function<int(int,char **)>> func_name_map;
};

class TestCommand: public SubCommand
{
public:
	TestCommand()
	{
		func_name_map["method"] = std::bind(&TestCommand::method,this,std::placeholders::_1,std::placeholders::_2);
		func_name_map["notify"] = std::bind(&TestCommand::notify,this,std::placeholders::_1,std::placeholders::_2);
	};
	~TestCommand(){};
	
	int method(int argc, char **argv)
	{
		parse_parameter(argc, argv);
		std::cout << "TestCommand::method()" << std::endl;
	};
	
	int notify(int argc, char **argv)
	{
		parse_parameter(argc, argv);
		std::cout << "TestCommand::notify()" << std::endl;
	};
	
	int parse_parameter(int argc, char **argv)
	{
		int c;
		int digit_optind = 0;
		static struct option long_options[] = {
				{"add",     required_argument, 0,  'A' },
				{"append",  required_argument, 0,  'a' },
				{"delete",  required_argument, 0,  'd' },
				{"verbose", no_argument,       0,  'v' },
				{"create",  required_argument, 0,  'c' },
				{"help",    no_argument,       0,  '?' },
			};
		while (1) 
		{
			int this_option_optind = optind ? optind : 1;
			int option_index = 0;
			
			c = getopt_long(argc, argv, "a:A:d:vc:f:",
					 long_options, &option_index);
			if (c == -1)
				break;

			switch (c) {
			case 'A':
				printf("option %s", long_options[option_index].name);
				if (optarg)
					printf(" with arg %s", optarg);
				printf("\n");
				break;
				
			case 'a':
				printf("option %s", long_options[option_index].name);
				if (optarg)
					printf(" with arg %s", optarg);
				printf("\n");
				break;

			case 'v':
				printf("option %s", long_options[option_index].name);
				if (optarg)
					printf(" with arg %s", optarg);
				printf("\n");
				break;

			case 'c':
				printf("option %s", long_options[option_index].name);
				if (optarg)
					printf(" with arg %s", optarg);
				printf("\n");
				break;

			case 'd':
				printf("option %s", long_options[option_index].name);
				if (optarg)
					printf(" with arg %s", optarg);
				printf("\n");
				break;

			default:
				printf("?? getopt returned character code 0%o ??\n", c);
			}
		}

		if(optind < argc) 
		{
			printf("non-option ARGV-elements: ");
			while (optind < argc)
				printf("%s ", argv[optind++]);
			printf("\n");
		}
	};
};




void help()
{
	std::cout << "Usage: " << std::endl;
}

int main(int argc, char **argv)
{
	if(3 > argc)
	{
		help();
		return 0;
	}

	std::string subcommand = argv[1];
	std::string action     = argv[2];
	if(subcommand == "test")
	{
		TestCommand test;
		test.run(action,argc,argv);
		return 0;
	}
	
	std::cout << "Unable to recognize subcommands: " << subcommand << std::endl;

    exit(EXIT_SUCCESS);
}