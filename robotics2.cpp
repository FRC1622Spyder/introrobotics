//Robotics class example 2 functions
#include <iostream>
#include <cstdlib>
#include <ctime> //Added another library that has time functions
// here we define a function for later use, the syntax is ReturnDataType Name (Parameters) Statements
int setGoal (int gameSize) //Note argument declaration
{
    int goal; // Create goal location
    goal = std::rand () %gameSize + 1; // gameSize is replaced with the values passed to it
    return goal; /*This is the value that will be returned by calling this function,
    must match the return type you specified in the function declaration "int setGoal"*/
}

int gameBoard () //We create another function, this time no values will be passed to it
{
    int board; //We must declare a variable inside the function because it is local
    std::cout << "How large of a range would you like the game to be? 1 - " << std::endl;
    std::cin >> board;
    return board;
}

int main ()
{

    int location = 0;
    int gameArea;
    int startPoint = 1;
    int goal;


    std::srand (std::time(NULL)); /* Instead of asking the user for a seed number we use the computer to generate one. we pass to the srand() function another function called time(). We then pass the value NULL to time telling the computer to give us back how many seconds it has been since 1 JAN 1970*/
    gameArea = gameBoard (); //Use the function gameBoard() to create our game area
    goal = setGoal (gameArea);
    std::cout << "The robot's goal is: " << goal << std::endl;

    while (true)
    {
        location = std::rand () % gameArea + startPoint;
        std::cout << "Robot location: " << location  << std::endl;
        if (location == goal)
        {
            std::cout << "Goal reached: " << location << std::endl;
            break;
        }
    }


    return 0;
}
