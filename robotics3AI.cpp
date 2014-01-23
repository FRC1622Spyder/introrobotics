//Robotics class example 3 classes w/ AI
#include <iostream>
#include <cstdlib>
#include <ctime>

class robot
{
private:
    int location;
public:
    int move (int gameSize , int startPoint)
    {
        location = std::rand () % (gameSize - startPoint + 1) + startPoint; //Move robot to random location within our games range
        std::cout << "Robot location: " << location  << std::endl;
        return location;
    }
};

int setGoal (int gameSize)
{
    int goal; // Create goal location
    goal = std::rand () %gameSize + 1; // define where the goal is
    return goal;
}

int gameBoard ()
{
    int board;
    std::cout << "How large of a range would you like the game to be? 1 - " << std::endl;
    std::cin >> board;
    return board;
}

int main ()
{
    //Declare/define variables
    int location = 0; // The robots location.
    int gameArea; //the range of values rand will use
    int startPoint = 1; // the starting point for values returned by rand
    int goal;

        // Game setuo
    robot bot;
    std::srand (std::time(NULL)); // Pass seed
    gameArea = gameBoard ();
    goal = setGoal (gameArea);
    std::cout << "The robot's goal is: " << goal << std::endl; // Print the robots goal for debug purposes
    //Game begin
    while (true)
    {
        location = bot.move (gameArea , startPoint);
        if (location == goal) // If we reach the goal
        {
            std::cout << "Goal reached: " << location << std::endl;
            break; // Break out of the while loop
        }
         if (location < goal) // If the robots location is below goal then change the start point and range so that we dont guess lower numbers but stay within our game area
        {
            startPoint = location + 1;
            gameArea = gameArea - location + 1;
        }
        if (location > goal) // If robot is above goal change the range so that we dont guess higher numbers
        {
            gameArea = gameArea - (gameArea - location) - 1;
        }
    }


    return 0;
}
