//Robotics class example 1
// Comment
/* Comment*/
#include <iostream>
#include <cstdlib> //Library that contains rand() function, is inside std namespace

//#include <name> must go at the top


int main() //Where your program starts operations
{
    //Declare/define variables
    /*
    int = integer = whole number
    float = floating point number = decimal or fraction eg .75 3/4
    bool = boolean = true or false, 1 or 0
    */

    // Here we declare and assign our variables at the same time
    int location = 0; // The robots location.
    int gameArea = 20; //the size of our X axis
    int startPoint = 1; // the starting point of our range for the X axis
    int goal; // Create goal location
    int seed; //rand() seed number

        // Game setuo
   	 /* Here we are using :: to access cout which is in the standard namespace, standard gets shortened to std
    	This will print to the screen the text inside the quotation marks*/
    std::cout << "Enter valid seed number: " << std::endl;
    std::cin >> seed; //here we take a users input and assign it to our variable seed
    // Game setup
    std::srand(seed); // Pass seed inout into the seed function
 	   /* rand functions works by using an algorithm to come up with a "random" number, this number will not change because it uses 	the same algorithm everytime, to over come this we use a seed number to provide different inputs into this algorithm.
   	 To define a range of numbers for rand to find a random number in we use %, % divides the number by a number we provide and 	then gives back to us the remainder. This will provide us with a number between 0 and or given number because the remainder of 	the division cannot be larger then the given number. We then modify this range by adding a number to it to give us our starting 	point. eg. range 50-55 = %5 + 50 */
    goal = std::rand() %gameArea + 1; // define where the goal is
    std::cout << "The robot's goal is: " << goal << std::endl; // Print the robots goal for debug purposes. Notice how we print a variable

    //Game begin
    while (true) // Loop will repeat until the condition simplifies to "false", == < >
    {
        location = std::rand () % gameArea + startPoint; //Move robot to random location within our games range
        std::cout << "Robot location: " << location  << std::endl;
        if (location == goal) // If we reach the goal
        {   //Groups the following statements together
            std::cout << "Goal reached: " << location << std::endl;
            break; // Break out of the while loop
        }
    }
    return 0; // Exit program with no errors
}


