#include "LibraryDisplayGenerator.h"

LibraryDisplayGenerator::LibraryDisplayGenerator()
{
	m_ideasPtr = &m_ideas;
}

void LibraryDisplayGenerator::GenerateIdea(std::vector<std::string> * _ideas, bool _generate)
{
	do
	{
		Helper::ClearScreen();

		std::cout << "Generating new idea, please wait" << std::endl;
		Helper::DotDotDot(600);
		int t_rand = rand() % _ideas->size();
		std::cout << "Generated Idea: " << _ideas->at(t_rand) << std::endl;
		bool t_inputCheck = false;

		do
		{
			std::cout << "------------------------------------------" << std::endl;
			std::cout << "Do you want to generate another idea (Y/N)" << std::endl;
			char t_input;
			std::cin >> t_input;
			t_input = toupper(t_input);
			t_inputCheck = Helper::CheckInputYN(t_input);
			if (t_input == 'Y')
			{
				_generate = true;
			}
			else if (t_input == 'N')
			{
				_generate = false;
			}
		} while (!t_inputCheck);
	} while (_generate);
}

void LibraryDisplayGenerator::AddIdea(std::vector<std::string> * _ideas, bool _add)
{
	do
	{
		Helper::ClearScreen();

		std::cout << "Adding new idea..." << std::endl;
		std::cout << "Enter new idea: ";
		std::string t_idea;
		std::cin >> t_idea;

		bool t_inputCheckConfirm = false;

		do
		{
			std::cout << "Confirm " << t_idea << " to be added (Y/N)" << std::endl;
			char t_input;
			std::cin >> t_input;
			t_input = toupper(t_input);
			t_inputCheckConfirm = Helper::CheckInputYN(t_input);
			if (t_input == 'Y')
			{
				_ideas->push_back(t_idea);
				std::ofstream myfile("data.txt", std::ios::app);

				if (myfile.is_open())
				{
					std::cout << "Debug: File found" << std::endl;
					std::string t = t_idea + "\n";
					myfile << t;
					myfile.close();
				}
				else
				{
					std::cout << "Error: Didn't find the file, creating new file" << std::endl;
					std::ofstream myfile("data.txt", std::ios::app);
					std::string t = t_idea + "\n";
					myfile << t;
					myfile.close();
				}
				DisplayAllIdeas(*_ideas);
			}
			else if (t_input == 'N')
			{
				std::cout << t_idea << " has been removed" << std::endl;
			}
		} while (!t_inputCheckConfirm);

		bool t_inputCheck = false;

		do
		{
			std::cout << "Do you want to add another idea (Y/N)" << std::endl;
			char t_input;
			std::cin >> t_input;
			t_input = toupper(t_input);
			t_inputCheck = Helper::CheckInputYN(t_input);
			if (t_input == 'Y')
			{
				_add = true;
			}
			else if (t_input == 'N')
			{
				_add = false;
			}
		} while (!t_inputCheck);
	} while (_add);
}

void LibraryDisplayGenerator::DisplayAllIdeas(std::vector<std::string> _ideas)
{
	for (int i = 0; i < _ideas.size(); i++)
	{
		std::cout << "Idea " << i + 1 << " " << _ideas[i] << std::endl;
	}
}

void LibraryDisplayGenerator::ClearData(std::vector<std::string> _ideas)
{
	bool t_inputCheck = false;

	do
	{
		std::cout << "Are you sure you want to clear all data? (Y/N)" << std::endl;
		char t_input;
		std::cin >> t_input;
		t_input = toupper(t_input);
		t_inputCheck = Helper::CheckInputYN(t_input);
		if (t_input == 'Y')
		{
			std::cout << "Clearing data..." << std::endl;
			_ideas.clear();
			std::cout << "Data Count: " << _ideas.size() << std::endl;
			if (_ideas.size() == 0)
			{
				std::cout << "Data cleared successfully..." << std::endl;
			}

			std::cout << "Wiping data.txt..." << std::endl;

			std::ofstream myfile("data.txt");

			if (myfile.is_open())
			{
				std::cout << "Debug: File found" << std::endl;
				myfile.clear();
				myfile.close();
			}
			else
			{
				std::cout << "Error: Didn't find the file, creating new file" << std::endl;
				std::ofstream myfile("data.txt");
			}
		}
	} while (!t_inputCheck);
}

void LibraryDisplayGenerator::LoadData()
{
	std::ifstream myfile("data.txt");
	if (myfile.is_open())
	{
		std::cout << "Debug: File found" << std::endl;
		std::string t_line;
		while (std::getline(myfile, t_line))
		{
			m_ideas.push_back(t_line);
			std::cout << t_line << std::endl;
		}
		myfile.close();
	}
	else
	{
		std::cout << "Error: Didn't find the file, creating new file" << std::endl;
		std::ofstream myfile("data.txt");
	}
}

void LibraryDisplayGenerator::DisplayHelp()
{
	bool t_finished = false;

	do
	{
		bool t_inputCheck = false;

		Helper::ClearScreen();

		std::cout << "-----------------------------------------------" << std::endl;
		std::cout << "|Help                                         |" << std::endl;
		std::cout << "-----------------------------------------------" << std::endl;
		std::cout << "|This program will help generate a display    |" << std::endl;
		std::cout << "|idea for you. You can add new ideas to the   |" << std::endl;
		std::cout << "|system when needed or start fresh and add a  |" << std::endl;
		std::cout << "|list of them yourself.                       |" << std::endl;
		std::cout << "-----------------------------------------------" << std::endl;

		std::cout << "-----------------------------------------------" << std::endl;
		std::cout << "|Input                                        |" << std::endl;
		std::cout << "-----------------------------------------------" << std::endl;
		std::cout << "|This program uses 'Y' or 'N' as the main     |" << std::endl;
		std::cout << "|input. The main menu uses numbers to decide  |" << std::endl;
		std::cout << "|what the system needs to do.                 |" << std::endl;
		std::cout << "-----------------------------------------------" << std::endl;

		do
		{
			std::cout << "-----------------------------------------------" << std::endl;
			std::cout << "Are you finished (Y/N)" << std::endl;
			char t_input;
			std::cin >> t_input;
			t_input = toupper(t_input);
			t_inputCheck = Helper::CheckInputYN(t_input);
			if (t_input == 'Y')
			{
				t_finished = true;
			}
			else if (t_input == 'N')
			{
				t_finished = false;
			}
		} while (!t_inputCheck);
	} while (!t_finished);
}

void LibraryDisplayGenerator::RemoveIdea()
{
	std::string t_idea;

	std::cout << "Enter idea: ";
	std::cin >> t_idea;

	bool t_ideaFound = false;
	for (int i = 0; i < m_ideasPtr->size(); i++)
	{
		if (t_idea == m_ideas[i])
		{
			t_ideaFound = true;
			std::cout << "Debug: Valid id" << std::endl;
			std::cout << "Removing idea, please wait" << std::endl;
			Helper::DotDotDot(600);
			std::cout << "Debug: " << m_ideas[i] << std::endl;
			m_ideas.erase(m_ideas.begin() + i);
			Helper::WaitFor(1000);
		}
	}
	if (!t_ideaFound)
	{
		std::cout << "Error: Invalid idea" << std::endl;
		Helper::WaitFor(1000);
	}
}

void LibraryDisplayGenerator::SaveData()
{
	std::ofstream myfile("data.txt");

	if (myfile.is_open())
	{
		std::cout << "Debug: File found" << std::endl;
		myfile.clear();
		for (int i = 0; i < m_ideas.size(); i++)
		{
			std::string t = m_ideas[i] + "\n";
			myfile << t;
		}
		myfile.close();
	}
	else
	{
		std::cout << "Error: Didn't find the file, creating new file" << std::endl;
		std::ofstream myfile("data.txt", std::ios::app);
		for (int i = 0; i < m_ideas.size(); i++)
		{
			std::string t = m_ideas[i] + "\n";
			myfile << t;
		}
		myfile.close();
	}
}

void LibraryDisplayGenerator::SetExit(bool _exit)
{
	m_exit = _exit;
	if (m_exit)
	{
		SaveData();
	}
}