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

bool isValid(const std::string& email)
{

	const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

	return regex_match(email, pattern);
}

DATA::Version* createNewVersion(DATA::Version* oldversion, DATA::Project* project, UUID* uuid) {
	DATA::Version* newversion = project->add_versions();
	project->set_currentversion(project->currentversion() + 1);

	newversion->CopyFrom(*oldversion);

	newversion->set_versionid(uuid->genID());
	newversion->set_versionnumber(project->currentversion());
	newversion->set_opsnumber(0);
	newversion->set_createdtime("now");
	std::cout << "\nCREATED NEW VERSION --- " << newversion->versionid() << std::endl;
	return newversion;
}

int main()
{
	int option = -1;
	USERS::User user;

	auto authMapObj = USERS::Users::default_instance();

	const std::string AUTH = "./DB/AUTH/";
	const std::string DATA = "./DB/DATA/";

	std::fstream input(AUTH + "temp.txt", std::ios_base::in | std::ios_base::binary);
	if (input)
		authMapObj.ParseFromIstream(&input);

	auto authMap = authMapObj.mutable_users();

LOGINPAGE:

	std::cout << "WELCOME TO GIT NOTE\n\n1 --- LOGIN\n2 --- SIGNUP\n3 --- DISPLAY USERS\n";
	UUID* uuid = nullptr;

	while (1) {
		std::cout << "\nENTER THE OPTION\n";
		std::cin >> option;

		if (option == 1) {
			std::string email = "krish@gmail.com";
			//std::cout << "\nENTER EMAIL\n";
			//std::cin >> email;

			std::string password = "password";
			//std::cout << "\nENTER PASSWORD\n";
			//std::cin >> password;
			password = sha256(password);

			if (authMap->find(email) != authMap->end() && (*authMap)[email].passwd() == password) {
				std::cout << "\n---- LOGGED IN SUCCESFULLY ----\n";
				user = (*authMap)[email];

				UUID temp(user.email());
				uuid = &temp;
				std::string str = (uuid->genID());

				std::cout << "\nCURRENT USER IS\n" << str << std::endl;

				user.set_userid((str));

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

			UUID temp(email);
			uuid = &temp;
			user.set_userid(uuid->genID());

			(*authMap)[email] = user;

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


	DATA::GitNote gitNoteObj = DATA::GitNote::default_instance();

	std::fstream input1(DATA + "temp.txt", std::ios_base::in | std::ios_base::binary);
	if (input1)
		gitNoteObj.ParseFromIstream(&input1);

	auto gitNoteMap = gitNoteObj.mutable_workspaces();

	std::cout << gitNoteObj.DebugString();

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


PROJECTPAGE:
	auto workspaceMap = workspaceObj->mutable_projects();

	DATA::Project* projectObj = nullptr;

	option = -1;
	std::cout << "\nENTER OPTION\n1 --- OPEN EXISTING PROJECT\n2 --- CREATE NEW PROJECT\n3 --- DISPLAY AVAILABLE PROJECTS\n4 --- GO BACK\n";
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

		projectObj->set_projectid(uuid->genID());
	}
	else if (option == 3) {
		std::cout << "\nTHE AVAILABLE PROJECTS ARE\n";
		for (auto it = workspaceMap->begin(); it != workspaceMap->end(); it++)
			std::cout << it->first << std::endl;
		goto PROJECTPAGE;
	}
	else if(option == 3) {
		goto LOGINPAGE;
	}

VERSIONPAGE:

	DATA::Version* versionObj = nullptr;

	if (projectObj->currentversion() != -1 && projectObj->currentversion() < projectObj->versions_size()) {
		versionObj = projectObj->mutable_versions(projectObj->currentversion());

		std::cout << "\nTHE AVAILABLE VERSIONS ARE\n";
		for (int i = 0; i <= projectObj->currentversion(); i++) {
			std::cout << projectObj->versions(i).versionnumber() << " " << projectObj->versions(i).versionid() << std::endl;
		}

		std::cout << "\nDO YOU WANT TO START EDITING FROM THE LATEST VERSION OR REVERT BACK TO AN OLDER VERSION ?\n";
		std::cout << "\n1 --- START EDITING\n2 --- REVERT BACK\n";
		option = -1;
		std::cin >> option;
		if (option == 2) {
			int sourceversion = projectObj->currentversion();
			//std::cout << sourceversion;

			int destversion;
			std::cout << "\nENTER THE VERSION YOU NEED TO REVERT BACK TO\n";
			std::cin >> destversion;

			std::cout << "old\n" << projectObj->DebugString();

			int times = sourceversion - destversion;
			while (times > 0) {
				//std::cout << projectObj->versions(projectObj->versions_size() - 1).versionid() << std::endl;
				(projectObj->mutable_versions())->RemoveLast();
				times--;
				projectObj->set_currentversion(projectObj->currentversion() - 1);
				//std::cout << "   ejected";
			}
			versionObj = projectObj->mutable_versions(projectObj->currentversion());
			//std::cout << "current v " << versionObj->versionid();

			std::cout << "new\n" << projectObj->DebugString();

		}
	}
	else {

		versionObj = projectObj->add_versions();
		projectObj->set_currentversion(projectObj->currentversion() + 1);

		versionObj->set_versionid(uuid->genID());
		std::cout << "\nCREATED NEW VERSION --- " << versionObj->versionid() << std::endl;
		versionObj->set_versionnumber(projectObj->currentversion());
		versionObj->set_opsnumber(0);
		versionObj->set_createdtime("now");

	}



FILEPAGE:

	auto versionMap = versionObj->mutable_files();
	DATA::File* fileObj = nullptr;
	option = -1;
	std::cout << "\nENTER THE OPTION\n1 --- OPEN EXISTING FILE\n2 --- CREATE NEW FILE\n3 --- DISPLAY AVAILABLE FILES\n4 --- GO BACK\n5 --- EXIT\n";
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
	else if (option == 3) {
		std::cout << "\nTHE AVAILABLE FILES ARE\n";
		for (auto it = versionMap->begin(); it != versionMap->end(); it++)
			std::cout << it->first << std::endl;
		goto FILEPAGE;

	}
	else if(option == 4) {
		goto PROJECTPAGE;
	}
	else {
		goto EXIT;
	}

	while (1) {
		std::cout << "\nENTER THE OPERATION\n1 --- ADD\n2 --- REMOVE\n3 --- UPDATE\n4 --- DISPLAY\n5 --- GO BACK\n* --- LOGOUT\n";
		std::cin >> option;
		if (option == 1) {
			std::cout << "\nENTER THE LINE TO BE ADDED\n";
			std::string data;
			std::cin.ignore();
			std::getline(std::cin, data);
			fileObj->add_lines(data);
			versionObj->set_opsnumber(versionObj->opsnumber() + 1);


			if (versionObj->opsnumber() == 1) {
				versionObj = createNewVersion(versionObj, projectObj, uuid);
				versionMap = versionObj->mutable_files();
				fileObj = &(*versionMap)[fileObj->name()];
			}

		}
		else if (option == 2) {
			std::cout << "\nENTER THE LINE NUMBER\n";
			int linenum;
			std::cin >> linenum;
			for (int i = linenum; i < fileObj->lines_size() - 1; i++) {
				(fileObj->mutable_lines())->SwapElements(i, i + 1);
			}
			(fileObj->mutable_lines())->RemoveLast();

			//foo.mutable_repeated_field()->SwapElements(index_to_remove, foo.repeated_field_size() - 1);
			//foo.mutable_repeated_field()->RemoveLast();

			versionObj->set_opsnumber(versionObj->opsnumber() + 1);
			if (versionObj->opsnumber() == 1) {
				versionObj = createNewVersion(versionObj, projectObj, uuid);
				versionMap = versionObj->mutable_files();
				fileObj = &(*versionMap)[fileObj->name()];
			}

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
			if (versionObj->opsnumber() == 1) {
				versionObj = createNewVersion(versionObj, projectObj, uuid);
				versionMap = versionObj->mutable_files();
				fileObj = &(*versionMap)[fileObj->name()];
			}

		}
		else if (option == 4) {
			for (int i = 0; i < fileObj->lines_size(); i++) {
				std::cout << i << " " << fileObj->lines(i) << std::endl;
			}

		}
		else if (option == 5) {
			goto FILEPAGE;
		}
		else {
			std::ofstream output1(DATA + "temp.txt", std::ios_base::out | std::ios_base::binary);
			gitNoteObj.SerializeToOstream(&output1);


			goto LOGINPAGE;
		}
	}

EXIT:
	std::ofstream output1(DATA + "temp.txt", std::ios_base::out | std::ios_base::binary);
	gitNoteObj.SerializeToOstream(&output1);

}
