#include <fstream>
#include <iostream>
#include "Login.pb.h"
#include <regex>
#include "sha256.h"
#include <string>

bool isValid(const std::string& email)
{

	// Regular expression definition
	const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

	// Match the string pattern
	// with regular expression
	return regex_match(email, pattern);
}

int main()
{
	USERS::User user;

	auto mapobj = USERS::Users::default_instance();
	auto map = mapobj.mutable_users();


	std::fstream input("temp.txt", std::ios_base::in | std::ios_base::binary);
	if (input)
		mapobj.ParseFromIstream(&input);


	std::cout << "WELCOME TO GIT NOTE\n\n1 --- LOGIN\n2 --- SIGNUP\n";

	while (1) {
		int option;
		std::cout << "\nENTER THE OPTION\n";
		std::cin >> option;

		if (option == 1) {
			std::string userid;
			std::cout << "\nENTER USERID\n";
			std::cin >> userid;

			std::string password;
			std::cout << "\nENTER PASSWORD\n";
			std::cin >> password;
			password = sha256(password);

			if (map->find(userid) != map->end() && (*(mapobj.mutable_users()))[userid].passwd() == password) {
				std::cout << "\n---- LOGGED IN SUCCESFULLY ----\n";
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
			user.set_name(name);

			std::string email;
			std::cout << "\nENTER EMAIL\n";
			std::cin >> email;
			if (isValid(email)) {
				user.set_email(email);
			}
			else {
				std::cout << "\nINVALID EMAIL\nTRY AGAIN\n";
				continue;
			}

			std::string passwd;
			std::cout << "\nENTER PASSWORD\n";
			std::cin >> passwd;
			passwd = sha256(passwd);
			user.set_passwd(passwd);

			std::string location;
			std::cout << "\nENTER LOCATION\n";
			std::cin >> location;
			user.set_location(location);

			std::string userid;
			std::cout << "\nENTER USERID\n";
			std::cin >> userid;
			user.set_userid(userid);

			(*(mapobj.mutable_users()))[userid] = user;

			std::cout << "\n---- SIGNED UP SUCCESSFULLY ----\n";

			std::ofstream output("temp.txt", std::ios_base::out | std::ios_base::binary);
			mapobj.SerializeToOstream(&output);
			continue;
		}
		else {
			for (auto it = map->begin(); it != map->end(); ++it)
				std::cout << it->first << " => " << it->second.DebugString() << '\n';
		}
	}


	/*
	
	for (auto it = map->begin(); it != map->end(); ++it)
		std::cout << it->first << " => " << it->second.DebugString() << '\n';
	*/
	/*
	std::cout << (*(mapobj.mutable_users()))["df"].DebugString();
	std::cout << (*(mapobj.mutable_users()))["bye"].DebugString();
	*/
	//(*(mapobj.mutable_users()))["bye"] = user;
	
	//std::ofstream output("temp.txt", std::ios_base::out | std::ios_base::binary);
	//mapobj.SerializeToOstream(&output);
	

	//(*mutable_users())["key"] = user;







}