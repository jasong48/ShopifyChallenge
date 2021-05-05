#define _CRT_SECURE_NO_WARNINGS
#ifndef HEADER_H
#define HEADER_H
#include <filesystem>
#include <iostream>
#include <string>
#include <fstream>


	
namespace repository {
	void addToRepo();
	void msgBanner();
	void selections();
	void viewRepo(std::string name);
	int createRepo();
	int delRepo(std::string name);
}

#endif