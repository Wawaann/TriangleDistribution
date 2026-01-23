#pragma once

# include <iostream>
# include <cstdlib>
# include <ctime>
# include <array>
# include <vector>
# include <cmath>

# include <SFML/Graphics.hpp>

# define DEFAULT_POINTS_NUMBER 500
# define DEFAULT_TIMER 50.0f
# define DEFAULT_SIZE 1.0f

typedef struct Point
{
	double x;
	double y;
	sf::Color color;

	Point(double i_x, double i_y, sf::Color i_color) : x(i_x), y(i_y), color(i_color)
	{
	}

	Point(double i_x, double i_y) : x(i_x), y(i_y), color(sf::Color::White)
	{
	}

	Point(const Point &p, sf::Color i_color) : x(p.x), y(p.y), color(i_color)
	{
	}

	Point(sf::Color i_color): x(0), y(0), color(i_color)
	{
	}

	Point operator=(const Point &p)
	{
		x = p.x;
		y = p.y;
		return *this;
	}
} Point;

// point A = (200, 25
// point B = (12.36, 350)
// point C = (387.64 , 137.5)

class Form
{
public:
	Form( int, char** );
	~Form( void );

private:
    unsigned int        _corners = 3;
    unsigned int        _point_number = DEFAULT_POINTS_NUMBER;
    unsigned int        _timer = DEFAULT_TIMER;
    unsigned int        _size = DEFAULT_SIZE;
    
	std::vector<Point>	_formPoints;
	std::vector<Point>	_points;
};