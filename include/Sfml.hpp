#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "./Triangle.hpp"

# define SCREEN_WIDTH 400
# define SCREEN_HEIGHT 400


class SFML
{
public:
    SFML(double i_size);
    ~SFML();

    void analyseEvent();
    void display(Triangle &i_triangle, int counter);

    void drawTriangle(std::array<Point, 3> i_points);

    sf::RenderWindow &getWindow() { return window; };

private:
    sf::RenderWindow window;
};