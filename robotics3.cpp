
//Robotics class example 3 classes
#include <iostream>
#include <cstdlib>
#include <ctime>

class Robot //Defines a class, syntax "class" ClassName {objects};
{
private: //If no access specifier is provided the compiler assumes it is private until otherwise told
    int m_location;//Because this is private it can only be accessed from within this class
public: // The program can access the following portion
    int move (int gameSize , int startPoint) // Define a function
    {
        m_location = std::rand () % (gameSize - startPoint + 1) + startPoint; //Move robot to random location within our games range
        std::cout << "Robot location: " << m_location  << std::endl;
        return m_location;
    }
};

int setGoal (int gameSize)
{
    int goal;
    goal = std::rand () %gameSize + 1;
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
    int location = 0;
    int gameArea;
    int startPoint = 1;
    int goal;

        // Game setuo
    Robot bot; //This creates and object called bot out of the class robot
    std::srand (std::time(NULL));
    gameArea = gameBoard ();
    goal = setGoal (gameArea);
    std::cout << "The robot's goal is: " << goal << std::endl; // Print the robots goal for debug purposes
    //Game begin
    while (true)
    {
        location = bot.move (gameArea , startPoint); // The bot.move portion is how we can access a function within a class
        if (location == goal)
        {
            std::cout << "Goal reached: " << location << std::endl;
            break;
        }
    }


    return 0;
}
