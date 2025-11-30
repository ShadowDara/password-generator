// Password Generator App in C++

#include <iostream>

#include "core.h"

using namespace std;

int main(int argc, char* argv[])
{
	// O Command line arguments
	if  (argc == 1) 
	{
		cout << "No arguments provided. Run with --help for more Infos" << endl;
		cout << "Generating 10 passwords with length 16 and strength level 3 by default now." << endl;
	}

	// Lenght in Characters
	int password_length = 16;

	// How many passwords to generate, 10 by default
	int password_count = 10;

	// Password Strength Level [1-4]
	int password_strength = 3;

	// Loop through arguments
	for (int i = 0; i < argc; ++i) {
		// Check if there is a next argument
		bool next_arg = false;
		if (argc > i)
		{
			next_arg = true;
		}

		// Help argument
		if (argv[i] == string("--help"))
		{
			return print_help();
		}

		// Password Level 1-4
		if (argv[i] == string("-l1"))
		{
			password_strength = 1;
		}
		if (argv[i] == string("-l2"))
		{
			password_strength = 2;
		}
		if (argv[i] == string("-l3"))
		{
			password_strength = 3;
		}
		if (argv[i] == string("-l4"))
		{
			password_strength = 4;
		}

		// Get the Password Length
		if (argv[i] == string("-c"))
		{
			if (next_arg)
			{
				password_count = stoi(argv[i + 1]);
			}
			else
			{
				cout << "No length provided after -c argument" << endl;
				cout << "Using default: 10" << endl;
			}
		}

		// Get the Password Count
		if (argv[i] == string("-l"))
		{
			if (next_arg)
			{
				password_length = stoi(argv[i + 1]);
			}
			else
			{
				cout << "No length provided after -l argument" << endl;
				cout << "Using default: 10" << endl;
			}
		}
	}

	// Generate Passwords
	vector<string> password = generate_password(password_strength, password_length, password_count);

	for(int i = 0; i < password.size(); ++i)
	{
		cout << password[i] << endl;
	}

	// Return with exit code 0
	return 0;
}
