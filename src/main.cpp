#include "../include/Sfml.hpp"

#include <iostream>

// -p <points>: number of points to draw on, default 100
// -t <time>: time to wait between each point (in ms), default 250ms

int main(int ac, char **av)
{
    Triangle triangle(ac, av);

    SFML sfml(triangle.getSize());

    sf::Clock clock;
    sf::Time time;
    float seconds;

    triangle.generateRandomPoint();

    int counter = 0;

    while (sfml.getWindow().isOpen())
    {
        time = clock.getElapsedTime(); 
        seconds = time.asMilliseconds();
        // std::cout << counter << std::endl;
        sfml.analyseEvent();

        if (seconds > triangle.getTimer())
        {
            if (counter < triangle.getPointNumber())
            {
                triangle.addNewPoint();
                counter++;
            }

            sfml.display(triangle, counter);
            clock.restart();
        }
    }
    return 0;
}