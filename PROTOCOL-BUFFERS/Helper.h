#include <ctime>
#include <fstream>
#include <iostream>
#include "Login.pb.h"
#include <regex>
#include "sha256.h"
#include <string>
#include "Workspace.pb.h"

class UUID {
private:
	std::string seed = "";
public:
	UUID(std::string seed) {
		this->seed = seed;
	}
	std::string genID() {
		seed = sha256((seed + seed));
		return seed;
	}
};

class Authenticator {
private:
	bool isValid(const std::string& email)
	{

		const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

		return regex_match(email, pattern);
	}
public:
	bool login(UUID* uuid,USERS::User* user) {

		int option = -1;
		auto authMapObj = USERS::Users::default_instance();

		const std::string AUTH = "./DB/AUTH/";
		std::fstream input(AUTH + "temp.txt", std::ios_base::in | std::ios_base::binary);
		if (input)
			authMapObj.ParseFromIstream(&input);

		auto authMap = authMapObj.mutable_users();

		std::cout << "WELCOME TO GIT NOTE\n\n1 --- LOGIN\n2 --- SIGNUP\n3 --- DISPLAY USERS\n";
		uuid = nullptr;

		while (1) {
			std::cout << "\nENTER THE OPTION\n";
			std::cin >> option;

			if (option == 1) {
				std::string email;
				std::cout << "\nENTER EMAIL\n";
				std::cin >> email;

				std::string password; // = password
				std::cout << "\nENTER PASSWORD\n";
				std::cin >> password;
				password = sha256(password);

				if (authMap->find(email) != authMap->end() && (*authMap)[email].passwd() == password) {
					std::cout << "\n---- LOGGED IN SUCCESFULLY ----\n";
					*user = (*authMap)[email];

					UUID temp(user->email());
					uuid = &temp;
					std::string str = (uuid->genID());

					std::cout << "\nCURRENT USER IS\n" << str << std::endl;

					user->set_userid((str));

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

				UUID temp(email);
				uuid = &temp;
				user->set_userid(uuid->genID());

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
