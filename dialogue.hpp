#ifndef DIALOGUE_H_INCLUDED
#define DIALOGUE_H_INCLUDED


#include <string>
#include <vector>
#include <iostream>

//The game is exprressed through dialogue
//The game will present information and choices for the player to choose a valid choice
//This will loop until they do so

class Dialogue
{
private:
//Piece of information that the dialogue displays
	std::string description;
//A vector of choices will be shown
//the dialogue automatically numbers the choices
	std::vector<std::string>choices;



public:
	//Runs the dialogue
	int activate()
	{
		//Output of information
		std::cout<<description <<std::endl;


		//Output of choices
		for(int i = 0; i < this->choices.size(); ++i)
		{
			if(this->choices[i] != "")
			std::cout<<i+1 << ": " << this->choices[i] <<std::endl;
		}

		int userInput =-1;
		//Read input from player until valid option is picked
		while(true)
		{


            std::cin >> userInput;

//'Valid' means withing the range of numbers outputted
			if(userInput >= 0 && userInput <= choices.size())
			{
				return userInput;
			}

		}
		return 0;
	}
	Dialogue(std::string description, std::vector<std::string>choices)
	{
		this->description = description;
		this->choices = choices;
	}


	Dialogue()
	{
	}


    };

#endif /* DIALOGUE_HPP */
