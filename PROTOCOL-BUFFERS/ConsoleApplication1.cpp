// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <fstream>
#include <iostream>
#include "Login.pb.h"
#include <regex>
#include <string>

bool isValid(const std::string& email)
{

	// Regular expression definition
	const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

	// Match the string pattern
	// with regular expression
	return regex_match(email, pattern);
}

int main(int argc, char* argv[]) {
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	USERS::Users userlist;
	USERS::User* userptr;
	USERS::User user;

	std::string DB = "temp.txt";

	// Read from file.
	std::fstream input(DB, std::ios_base::in | std::ios_base::binary);
	if (input) {
		userlist.ParseFromIstream(&input);
	}
	userptr = userlist.add_users();


	std::cout << "WELCOME TO GITNOTES\n\n";
	std::cout << "ENTER THE OPTION\n1 --- LOGIN\n2 --- SIGNUP\n";

	int option;
	std::cin >> option;

	std::string id;
	std::cout << "\nENTER USER ID\n" << std::endl;
	std::cin >> id;

	std::string passwd;
	std::cout << "\nENTER PASSWORD\n";
	std::cin >> passwd;

	bool flag = true;
	while (flag) {
		if (option == 1) {
			for (int i = 0; i < userlist.users_size(); i++) {
				if (id == userlist.users(i).userid() && passwd == userlist.users(i).passwd()) {
					std::cout << "\n------- LOGGED IN SUCCESSFULLY ------\n";
				}
				else {
					std::cout << "\nWRONG USER ID OR PASSWORD.\nTRY AGAIN\n";
					continue;
				}
				if (innerflag) {
					continue;
				}
			}
		}
		else if (option == 2) {

			userptr->set_userid(id);

			userptr->set_passwd(passwd);

			std::string name;
			std::cout << "\nENTER NAME\n" << std::endl;
			std::cin >> name;
			userptr->set_email(name);

			std::string loc;
			std::cout << "\nENTER LOCATION\n" << std::endl;
			std::cin >> loc;
			userptr->set_email(loc);


			std::string email;
			std::cout << "\nENTER EMAIL ID\n" << std::endl;
			std::cin >> email;
			if (isValid(email)) {
				userptr->set_email(email);
			}
			else {
				std::cout << "\nINVALID EMAIL\nTRY AGAIN\n";
				continue;
			}

			std::cout << "\n------- SIGNED UP SUCCESSFULLY ------\n";

		}
	}
	

	/*
	userptr->set_name("sajeev");
	userptr->set_email("124@gmail");
	userptr->set_location("sdfsdfsd");
	userptr->set_userid("9898");
	userptr->set_passwd("dfdd");
	*/

	// Write to file
	std::ofstream ofs(DB, std::ios_base::out | std::ios_base::binary);
	userlist.SerializeToOstream(&ofs);

	std::cout << "\nUSERSLIST\n";
	for (int i = 0; i < userlist.users_size(); i++) {
		user = userlist.users(i);
		std::cout << user.DebugString();
	}

	return 1;
}

