// Core for the Password Generator App

#include "core.h"

using namespace std;

int print_help() {
	cout << "Password Generator Help" << endl;
	cout << "Usage: PWGenerator [options]" << endl;
	cout << "Options:" << endl;
	cout << "  --help       Show this help message" << endl;
	cout << "  -c			Set the Numbver for how many different passwords will be generated" << endl;
	cout << "  -l			Set the Password length" << endl;
	cout << "  -l1			Password Character Level 1" << endl;
	cout << "  -l2			Password Character Level 2" << endl;
	cout << "  -l3			Password Character Level 3" << endl;
	cout << "  -l4			Password Character Level 4" << endl;
	return 0;
}

vector<string> generate_password(int strength, int length, int count)
{
	// Make a vector to store passwords
	vector<string> passwords;

	const string lower = "abcdefghijklmnopqrstuvwxyz";
	const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const string digits = "0123456789";
	const string punctuation = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

	string characters = lower;

	// Add character sets based on strength level
	if (strength >= 2) {
		characters += upper;
	}
	if (strength >= 3) {
		characters += digits;
	}
	if (strength >= 4) {
		characters += punctuation;
	}

	// Generate Multiple Passwords
	for(int i = 0; i < length; ++i)
	{
		// Generate Random Now
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dist(0, static_cast<int>(characters.size()) - 1);

		// Make Passwords
		std::string password;
		password.reserve(length);
		for (int i = 0; i < length; ++i) {
			char c = characters[dist(gen)];
			password.push_back(c);
		}

		// Add password to vector
		passwords.push_back(password);
	}

	// Return the generated passwords
	return passwords;
}
