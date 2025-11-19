#pragma once

#include <iostream>
#include "Game.h"

class TicTacToe : public Game
{

private:
	char m_board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', };
	int turnCounter = 0;

public:
	int playerChoice;
	int playerTurn = 0;



	bool IsGameOver() const
	{
		if (m_board[0] != ' ' && m_board[0] == m_board[1] && m_board[1] == m_board[2])
		{
			return true;
		}
		else if (m_board[3] != ' ' && m_board[3] == m_board[4] && m_board[4] == m_board[5])
		{
			return true;
		}
		else if (m_board[6] != ' ' && m_board[6] == m_board[7] && m_board[7] == m_board[8])
		{
			return true;
		}
		else if (m_board[0] != ' ' && m_board[0] == m_board[3] && m_board[3] == m_board[6])
		{
			return true;
		}
		else if (m_board[1] != ' ' && m_board[1] == m_board[4] && m_board[4] == m_board[7])
		{
			return true;
		}
		else if (m_board[2] != ' ' && m_board[2] == m_board[5] && m_board[5] == m_board[8])
		{
			return true;
		}
		else if (m_board[0] != ' ' && m_board[0] == m_board[4] && m_board[4] == m_board[8])
		{
			return true;
		}
		else if (m_board[2] != ' ' && m_board[2] == m_board[4] && m_board[4] == m_board[6])
		{
			return true;
		}
		else if (turnCounter == 9)
		{
			std::cout << "It's a tie." << "\n";

			return true;
		}
		else
		{
			return false;
		}
	};

	void TakeTurn()
	{
		int playerInput;
		
		if (playerTurn == 0)
		{
			std::cout << "Player 1 turn.\n";
			std::cout << "Where would you like to place your mark? (Enter a number 1-9)\n";
			std::cin >> playerInput;
			while (true)
			{
				if (playerInput > 0 && playerInput < 10)
				{
					if (m_board[playerInput - 1] == 'X' || m_board[playerInput - 1] == 'O')
					{
					std::cout << "This spot is already taken, choose another. (Enter a number 1-9)\n";
					std::cin >> playerInput;
					}
					else
					{
						m_board[playerInput - 1] = 'X';
						break;
					}
				}
				else
				{
					std::cout << "Please enter a valid number (1-9)\n";
					return;
				}
			}


			playerTurn = 1;

		}
		else
		{
			std::cout << "Player 2 turn.\n";
			std::cout << "Where would you like to place your mark? (Enter a number 1-9)\n";
			std::cin >> playerInput;
			while (true)
			{
				if (playerInput > 0 && playerInput < 10)
				{
					if (m_board[playerInput - 1] == 'X' || m_board[playerInput - 1] == 'O')
					{
						std::cout << "This spot is already taken, choose another. (Enter a number 1-9)\n";
						std::cin >> playerInput;
					}
					else
					{
						m_board[playerInput - 1] = 'O';
						break;
					}
				}
				else
				{
					std::cout << "Please enter a valid number (1-9)\n";
					return;
				}
			}

			playerTurn = 0;
		}

		turnCounter++;
		system("cls");
	};

	void Display() const
	{
		std::cout << m_board[0] << "|" << m_board[1] << "|" << m_board[2] << "\n"
			<< "------" << "\n"
			<< m_board[3] << "|" << m_board[4] << "|" << m_board[5] << "\n"
			<< "------" << "\n"
			<< m_board[6] << "|" << m_board[7] << "|" << m_board[8] << "\n";
	};
};