#include <ctime>
#include <fstream>
#include <iostream>
#include "Login.pb.h"
#include <regex>
#include "sha256.h"
#include <string>
#include "Workspace.pb.h"


class Authenticator {
private:
	bool isValid(const std::string& email)
	{

		const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

		return regex_match(email, pattern);
	}
public:
	bool login(USERS::User* user) {

		int option = -1;
		auto authMapObj = USERS::Users::default_instance();

		const std::string AUTH = "./DB/AUTH/";
		std::fstream input(AUTH + "temp.txt", std::ios_base::in | std::ios_base::binary);
		if (input)
			authMapObj.ParseFromIstream(&input);

		auto authMap = authMapObj.mutable_users();

		std::cout << "WELCOME TO GIT NOTE\n\n1 --- LOGIN\n2 --- SIGNUP\n3 --- DISPLAY USERS\n";


		while (1) {
			std::cout << "\nENTER THE OPTION\n";
			std::cin >> option;

			if (option == 1) {
				std::string  email = "krish@gmail.com";
				std::cout << "\nENTER EMAIL\n";
				//std::cin >> email;

				std::string password = "password"; // = password
				std::cout << "\nENTER PASSWORD\n";
				//std::cin >> password;
				password = sha256(password);

				if (authMap->find(email) != authMap->end() && (*authMap)[email].passwd() == password) {
					std::cout << "\n---- LOGGED IN SUCCESFULLY ----\n";
					*user = (*authMap)[email];

					break;
				}
				else {
					std::cout << "\nWRONG USERID OR PASSWORD\nTRY AGAIN\n";
					continue;
				}

			}
			else if (option == 2) {
				std::string name;
				std::cout << "\nENTER NAME\n";
				std::cin >> name;
				user->set_name(name);

				std::string email;
				std::cout << "\nENTER EMAIL\n";
				std::cin >> email;
				if (isValid(email)) {
					user->set_email(email);
				}
				else {
					std::cout << "\nINVALID EMAIL\nTRY AGAIN\n";
					continue;
				}

				std::string passwd;
				std::cout << "\nENTER PASSWORD\n";
				std::cin >> passwd;
				passwd = sha256(passwd);
				user->set_passwd(passwd);

				std::string location;
				std::cout << "\nENTER LOCATION\n";
				std::cin >> location;
				user->set_location(location);


				(*authMap)[email] = *user;

				std::cout << "\n---- SIGNED UP SUCCESSFULLY ----\n";

				std::ofstream output(AUTH + "temp.txt", std::ios_base::out | std::ios_base::binary);
				authMapObj.SerializeToOstream(&output);
				continue;
			}
			else {
				for (auto it = authMap->begin(); it != authMap->end(); ++it)
					std::cout << it->first << " => " << it->second.DebugString() << '\n';
			}
		}

		return true;
	}
};

int max(int a, int b) {
	return (a > b) ? a : b;
}

void LCS(std::string X, std::string Y, int m, int n) {
	int** L = new int* [m];
	for (int i = 0; i < m; i++)
	{
		L[i] = new int[n];
	}

	/* Following steps build L[m+1][n+1] in bottom up
	  fashion. Note that L[i][j] contains length of LCS of
	  X[0..i-1] and Y[0..j-1] */
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;
			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

	// Following code is used to print LCS
	int index = L[m - 1][n - 1] + 1;

	// Create a character array to store the lcs string
	char* lcs = new char[index + 1];

	lcs[index] = '\0'; // Set the terminating character

	// Start from the right-most-bottom-most corner and
	// one by one store characters in lcs[]
	int i = m, j = n;
	while (i > 0 && j > 0) {
		// If current character in X[] and Y are same, then
		// current character is part of LCS
		if (X[i - 1] == Y[j - 1]) {
			lcs[index - 1]
				= X[i - 1]; // Put current character in result
			i--;
			j--;
			index--; // reduce values of i, j and index
		}

		// If not same, then find the larger of two and
		// go in the direction of larger value
		else if (L[i - 1][j] > L[i][j - 1])
			i--;
		else
			j--;
	}

	/*
	for (int i = 0; i < m; i++)
	{
		delete[] L[i];
	}
	delete[] L;
	*/

	// Print the lcs
	std::cout << lcs;

	//delete[] lcs;
}

std::string stringify(DATA::File file) {
	std::string temp = file.lines(0);
	for (int i = 1; i < file.lines_size(); i++) {
		temp = temp + file.lines(i);
	}
	return temp;
}

void loadDiff(DATA::Version v1, DATA::Version v2) {
	for (auto it = v1.files().begin(); it != v1.files().end(); it++) {
		if (v2.files().contains(it->first)) {
			std::string str1 = stringify(it->second);
			std::string str2 = stringify((v2.files().find(it->first))->second);
			LCS(str1, str2,str1.length(),str2.length());
		}
	}
}

