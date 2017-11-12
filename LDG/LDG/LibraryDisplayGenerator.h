#ifndef LIBRARYDISPLAYGENERATOR_H
#define LIBRARYDISPLAYGENERATOR_H

#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <windows.h>
#include "Helper.h"

class LibraryDisplayGenerator
{
private:
	bool m_exit = false;
	bool m_generate = true;
	bool m_add = true;
	/*std::vector<std::string> m_ideas;
	std::vector<std::string> * m_ideasPtr;*/

public:
	LibraryDisplayGenerator();
	~LibraryDisplayGenerator() = default;

	void GenerateIdea(std::vector<std::string> * _ideas, bool _generate);
	void AddIdea(std::vector<std::string> * _ideas, bool _add);
	void DisplayAllIdeas(std::vector<std::string> _ideas);
	void ClearData(std::vector<std::string> _ideas);
	void LoadData();
	void DisplayHelp();
	void RemoveIdea();
	void SaveData();
	bool CanExit() { return m_exit; };
	bool CanGenerate() { return m_generate; };
	bool CanAdd() { return m_add; };
	void SetExit(bool _exit);

	std::vector<std::string> m_ideas;
	std::vector<std::string> * m_ideasPtr;
};

#endif