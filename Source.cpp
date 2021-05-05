/* Jason Goldenberg
*  Purpose: Image Repository using C++ recursive directory iterator 
*  Date: May 5, 2021
*/
#include "Header.h"


using namespace std;

int main()
{
	repository::selections();
}


namespace repository {
	void addToRepo()
	{
		string from, to;

		cout << "Please enter the file path of the photo" << endl;
		cin >> from;


		string temp = " ";
		char temp1[1024];
		strcpy(temp1, from.c_str());


		cout << "Please enter the name of the repository" << endl;
		cin >> to;

		string temp = " ";
		char temp2[1024];
		strcpy(temp2, to.c_str());


		if (rename(temp1, temp2) != 0)
			perror("Error moving file");
		else
			cout << "File moved successfully";



		cout << endl;
		system("pause");
		selections();
	}
	void msgBanner()
	{
		std::cout << "******************************************************" << std::endl;
		std::cout << "           Welcome to my Image repository             " << std::endl;
		std::cout << "******************************************************" << std::endl;
		std::cout << " This program will only accept image extension types  " << std::endl;
		std::cout << " such as: .jpeg, .png, .bmp and .gif" << std::endl;
		std::cout << "******************************************************" << std::endl;
		std::cout << " These are your options: " << std::endl;
		std::cout << " 1. Create Repo (must be done first)" << std::endl;
		std::cout << " 2. View Repo" << std::endl;
		std::cout << " 3. Delete Repo" << std::endl;
		std::cout << " 4. Add to Repo" << std::endl;
		std::cout << " 5. Search for item in Repo" << std::endl;
		std::cout << " 0. Exit" << std::endl;
	}

	void selections()
	{
		system("CLS");
		msgBanner();
		int selection;
		string repoName;
		do
		{
			cin >> selection;

			switch (selection)
			{
			case 1:
				createRepo();
				break;
			case 2:
				cout << endl;
				cout << "please enter the repository name" << endl;
				cin >> repoName;
				viewRepo(repoName);
				break;
			case 3:
				cout << endl;
				cout << "please enter the repository name" << endl;
				cin >> repoName;
				delRepo(repoName);
				break;
			case 4:
				addToRepo();
				break;
			case 5:
				cout << "Better try again" << endl;
				break;
			case 0:
				EXIT_SUCCESS;
				break;
			default:
				cout << " -Please select a valid option!" << endl;
			}
		} while (selection != 0);
	}

	void viewRepo(string name)
	{
		string path = name;
		for (const auto & entry : experimental::filesystem::directory_iterator(path))
			std::cout << entry.path() << std::endl;

		cout << endl;
		system("pause");
		selections();
	}

	int createRepo()
	{
		std::cout << "In order to create your repo, you need to give it a name, please enter a name" << std::endl;
		std::string name;

		std::cin >> name;

		std::cout << "-" << std::endl;
		std::cout << "The name you have chosen is: " << name << std::endl;
		std::cout << "-" << std::endl;



		if (experimental::filesystem::create_directories(name))
		{
			cout << "Success! your repository " << name << " has been created!" << endl;
		}
		else
		{
			cout << "An error has occured" << endl;
			EXIT_FAILURE;
		};
		cout << endl;
		system("pause");
		selections();

		return 0;
	}

	int delRepo(std::string name)
	{
		std::experimental::filesystem::remove_all("name"); 

		cout << endl;
		system("pause");
		selections();
	}



}


