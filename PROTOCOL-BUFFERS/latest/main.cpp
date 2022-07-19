#include <fstream>
#include <iostream>
#include "Login.pb.h"
#include <regex>
#include "sha256.h"
#include <string>
#include "Workspace.pb.h"

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

	auto authMapObj = USERS::Users::default_instance();

	const std::string AUTH = "./DB/AUTH/";
	const std::string DATA = "./DB/DATA/";

	std::fstream input(AUTH + "temp.txt", std::ios_base::in | std::ios_base::binary);
	if (input)
		authMapObj.ParseFromIstream(&input);

	auto authMap = authMapObj.mutable_users();


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

			if (authMap->find(userid) != authMap->end() && (*authMap)[userid].passwd() == password) {
				std::cout << "\n---- LOGGED IN SUCCESFULLY ----\n";
				user = (*authMap)[userid];
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

			(*authMap)[userid] = user;

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

	//std::cout << user.DebugString();

	DATA::GitNote gitNoteObj = DATA::GitNote::default_instance();

	std::fstream input1(DATA + "temp.txt", std::ios_base::in | std::ios_base::binary);
	if (input1)
		gitNoteObj.ParseFromIstream(&input1);

	auto gitNoteMap = gitNoteObj.mutable_workspaces();
	
	DATA::Workspace* workspaceObj;

	if (gitNoteMap->contains(user.userid())) {
		workspaceObj = &(*gitNoteMap)[user.userid()];
		//std::cout << workspaceObj->userid();
	}
	else {
		(*gitNoteMap)[user.userid()] = DATA::Workspace::default_instance();
		workspaceObj = &(*gitNoteMap)[user.userid()];
		workspaceObj->set_userid(user.userid());
	}

	auto workspaceMap = workspaceObj->mutable_projects();

	DATA::Project* projectObj = nullptr;

	int option;
	std::cout << "\nENTER OPTION\n1 --- OPEN EXISTING PROJECT\n2 --- CREATE NEW PROJECT\n3 --- DISPLAY AVAILABLE PROJECTS\n";
	std::cin >> option;
	if (option == 1) { //existing
		std::string projectName;
		std::cout << "\nENTER PROJECT NAME\n";
		std::cin >> projectName;

		projectObj = &(*workspaceMap)[projectName];
	}
	else if (option == 2) { //new
		std::string projectName;
		std::cout << "\nENTER PROJECT NAME\n";
		std::cin >> projectName;

		projectObj = &(*workspaceMap)[projectName];

		projectObj->set_userid(user.userid());
		projectObj->set_currentversion(-1);
		projectObj->set_projectname(projectName);

		std::string projectID;
		std::cout << "\nENTER PROJECT ID\n";
		std::cin >> projectID;
		projectObj->set_projectid(projectID);
	}
	else if(option == 3) {
		std::cout << "\nTHE AVAILABLE PROJECTS ARE\n";
		for (auto it = workspaceMap->begin(); it != workspaceMap->end(); it++)
			std::cout << it->first << std::endl;
	}


	DATA::Version* versionObj = nullptr;

	if (projectObj->currentversion() != -1 && projectObj->currentversion() < projectObj->versions_size()) {
		versionObj = projectObj->mutable_versions(projectObj->currentversion());
	}
	else {
		versionObj = projectObj->add_versions();
		projectObj->set_currentversion(projectObj->currentversion() + 1);
		
		std::cout << "\nENTER VERSION ID\n";
		int id;
		std::cin >> id;

		versionObj->set_versionid(id);
		versionObj->set_versionnumber(projectObj->currentversion());
		versionObj->set_opsnumber(0);
		versionObj->set_createdtime("now");
		/*
		if (projectObj->currentversion() != 0) {
			auto temp = (projectObj->mutable_versions(projectObj->currentversion() - 1))->mutable_files();
			auto temp2 = versionObj->mutable_files();

			temp2 = temp;
		}*/

	}

	auto versionMap = versionObj->mutable_files();

	DATA::File* fileObj = nullptr;
	std::cout << "\nENTER THE OPTION\n1 --- OPEN EXISTING FILE\n2 --- CREATE NEW FILE\n3 --- DISPLAY AVAILABLE FILES\n";
	std::cin >> option;

	if (option == 1) {
		std::string fileName;
		std::cout << "\nENTER FILE NAME\n";
		std::cin >> fileName;

		fileObj = &(*versionMap)[fileName];
	}
	else if (option == 2) {
		std::string fileName;
		std::cout << "\nENTER FILE NAME\n";
		std::cin >> fileName;

		fileObj = &(*versionMap)[fileName];

		fileObj->set_name(fileName);
	}
	else {
		std::cout << "\nTHE AVAILABLE FILES ARE\n";
		for (auto it = versionMap->begin(); it != versionMap->end(); it++)
			std::cout << it->first << std::endl;

	}

	while (1) {
		std::cout << "\nENTER THE OPERATION\n1 --- ADD\n2 --- REMOVE\n3 --- UPDATE\n4 --- DISPLAY\n";
		std::cin >> option;
		if (option == 1) {
			std::cout << "\nENTER THE LINE TO BE ADDED\n";
			std::string data;
			std::cin.ignore();
			std::getline(std::cin, data);
			fileObj->add_lines(data);
			versionObj->set_opsnumber(versionObj->opsnumber() + 1);
		}
		else if (option == 2) {/*
			std::cout << "\nENTER THE LINE NUMBER\n";
			int linenum;
			std::cin >> linenum;
			for (int i = linenum; i < fileObj->lines_size() - 1; i++) {
				fileObj->set_lines(i, fileObj->lines(i + 1));
			}*/
		}
		else if (option == 3) {
			std::cout << "\nENTER THE NEW LINE DATA\n";
			std::string data;
			std::cin.ignore();
			std::getline(std::cin, data);
			std::cout << "\nENTER THE LINE NUMBER\n";
			int linenum;
			std::cin >> linenum;
			fileObj->set_lines(linenum, data);
			versionObj->set_opsnumber(versionObj->opsnumber() + 1);
		}
		else if (option == 4) {
			for (int i = 0; i < fileObj->lines_size(); i++) {
				std::cout << i << " " << fileObj->lines(i) << std::endl;
			}

		}
		else {
			break;
		}
	}


	std::ofstream output1(DATA + "temp.txt", std::ios_base::out | std::ios_base::binary);
		gitNoteObj.SerializeToOstream(&output1);

}
