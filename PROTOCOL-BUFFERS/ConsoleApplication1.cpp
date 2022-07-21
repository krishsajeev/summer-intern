#include "Helper.h"

class UUID {
public:
	std::string seed = "";
	UUID(std::string seed) {
		this->seed = seed;
	}
	std::string genID() {
		seed = sha256((seed + seed));
		return seed;
	}
};

DATA::Version* createNewVersion(DATA::Version* oldversion, DATA::Project* project, UUID* uuid) {
	DATA::Version* newversion = project->add_versions();
	project->set_currentversion(project->currentversion() + 1);

	newversion->CopyFrom(*oldversion);
	newversion->set_versionid(uuid->genID());
	newversion->set_versionnumber(project->currentversion());
	newversion->set_opsnumber(0);

	time_t now = time(0);
	newversion->set_createdtime(ctime(&now));
	std::cout << "\nCREATED NEW VERSION --- " << newversion->versionid() << std::endl;
	return newversion;
}

int main()
{
	UUID* uuid = nullptr;

	int option;
	const std::string DATA = "./DB/DATA/";

LOGINPAGE:
	USERS::User user;
	Authenticator authn;
	authn.login(&user);
	
	UUID temp(user.email());
	uuid = &temp;
	user.set_email(uuid->genID());

	std::cout << "\n------ THE CURRENT USER IS ------\n" << user.userid() << "\n";

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
		std::cout << "\n1 --- START EDITING\n2 --- REVERT BACK\n3 --- LOAD DIFF\n";
		option = -1;
		std::cin >> option;
		if (option == 2) {
			int sourceversion = projectObj->currentversion();

			int destversion;
			std::cout << "\nENTER THE VERSION YOU NEED TO REVERT BACK TO\n";
			std::cin >> destversion;

			loadDiff(projectObj->versions(destversion), projectObj->versions(sourceversion));


			int times = sourceversion - destversion;
			while (times > 0) {
				(projectObj->mutable_versions())->RemoveLast();
				times--;
				projectObj->set_currentversion(projectObj->currentversion() - 1);
			}
			versionObj = projectObj->mutable_versions(projectObj->currentversion());

		}
	}
	else {

		versionObj = projectObj->add_versions();
		projectObj->set_currentversion(projectObj->currentversion() + 1);

		versionObj->set_versionid(uuid->genID());
		std::cout << "\nCREATED NEW VERSION --- " << versionObj->versionid() << std::endl;
		versionObj->set_versionnumber(projectObj->currentversion());
		versionObj->set_opsnumber(0);

		time_t now = time(0);
		versionObj->set_createdtime(ctime(&now));

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

		//std::cout << "version object " << versionObj->DebugString();
		//std::cout << "file " << fileObj->DebugString();

		std::cout << "\nENTER THE OPERATION\n1 --- ADD\n2 --- REMOVE\n3 --- UPDATE\n4 --- DISPLAY\n5 --- GO BACK\n* --- LOGOUT\n";
		std::cin >> option;
		if (option == 1) {
			std::cout << "\nENTER THE LINE TO BE ADDED\n";
			std::string data;
			std::cin.ignore();
			std::getline(std::cin, data);
			fileObj->add_lines(data);
			versionObj->set_opsnumber(versionObj->opsnumber() + 1);


			if (versionObj->opsnumber() >= 1) {
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
			if (versionObj->opsnumber() >= 1) {
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
			if (versionObj->opsnumber() >= 1) {
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
			(projectObj->mutable_versions())->RemoveLast();
			projectObj->set_currentversion(projectObj->currentversion() - 1);
			versionObj = projectObj->mutable_versions(projectObj->currentversion());
			std::ofstream output1(DATA + "temp.txt", std::ios_base::out | std::ios_base::binary);
			gitNoteObj.SerializeToOstream(&output1);

			goto LOGINPAGE;
		}
	}

EXIT:
	std::ofstream output1(DATA + "temp.txt", std::ios_base::out | std::ios_base::binary);
	gitNoteObj.SerializeToOstream(&output1);

}
