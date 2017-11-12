#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include "Helper.h"
#include "LibraryDisplayGenerator.h"

int main()
{
	LibraryDisplayGenerator m_libraryDisplayGenerator;

	m_libraryDisplayGenerator.LoadData();

	srand(time(NULL));

	do
	{
		bool t_inputCheck = false;
		do
		{
			Helper::ClearScreen();
			std::cout << " Welcome to the Library Display Idea Generator" << std::endl;
			std::cout << "-----------------------------------------------" << std::endl;
			std::cout << "| 1) Generate a new idea                      |" << std::endl;
			std::cout << "| 2) Add a new idea                           |" << std::endl;
			std::cout << "| 3) Remove an idea                           |" << std::endl;
			std::cout << "| 4) Clear Data                               |" << std::endl;
			std::cout << "| 5) Help                                     |" << std::endl;
			std::cout << "| 6) Exit                                     |" << std::endl;
			std::cout << "-----------------------------------------------" << std::endl;
			std::cout << " Enter menu choice: ";

			int t_option;
			std::cin >> t_option;

			t_inputCheck = Helper::CheckInputNum(t_option, 0, 6);

			switch (t_option)
			{
			case 1:
				if (m_libraryDisplayGenerator.m_ideasPtr->size() > 0)
				{
					m_libraryDisplayGenerator.GenerateIdea(m_libraryDisplayGenerator.m_ideasPtr, m_libraryDisplayGenerator.CanGenerate());
				}
				else
				{
					m_libraryDisplayGenerator.AddIdea(m_libraryDisplayGenerator.m_ideasPtr, m_libraryDisplayGenerator.CanAdd());
				}
				break;
			case 2:
				m_libraryDisplayGenerator.AddIdea(m_libraryDisplayGenerator.m_ideasPtr, m_libraryDisplayGenerator.CanAdd());
				break;
			case 3:
				m_libraryDisplayGenerator.RemoveIdea();
				break;
			case 4:
				if (m_libraryDisplayGenerator.m_ideasPtr->size() > 0)
				{
					m_libraryDisplayGenerator.ClearData(m_libraryDisplayGenerator.m_ideas);
				}
				break;
			case 5:
				m_libraryDisplayGenerator.DisplayHelp();
				break;
			case 6:
				m_libraryDisplayGenerator.SetExit(true);
				break;
			}
		} while (!t_inputCheck);
	} while (!m_libraryDisplayGenerator.CanExit());
	return 0;
}