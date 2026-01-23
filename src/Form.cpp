#include "./include/Form.hpp"

Form::Form( int ac, char** av )
{
	std::srand(std::time(nullptr));

	if (ac > 9)
	{
		std::cerr << "Usage: " << av[0] << " -p <points> -t <time>" << std::endl;
		exit(1);
	}

	if (ac == 2 && std::string(av[1]) == "-h")
	{
		std::cout << "Usage: " << av[0] << " -p <points> -t <time>" << std::endl
			<< "\t-p <points>: number of points to draw on, default 100" << std::endl
			<< "\t-t <time>: time to wait between each point (in ms), default 50ms" << std::endl 
			<< "\t-s: Sets the scale of the window. Default scale is 1, with a window size of 600x600.";
		exit(0);
	}

	try
	{
		for (int i = 1; i < ac; i++)
		{
			if (std::string(av[i]) == "-p")
			{
				this->_point_number = std::stoi(av[i + 1]);
			}
			if (std::string(av[i]) == "-t")
			{
				this->_timer = std::stod(av[i + 1]);
			}
			if (std::string(av[i]) == "-s")
			{
				this->_size = std::stod(av[i + 1]);
			}
			if (std::string(av[i] == "-c"))
			{
				this->_corners = std::stod(av[i + 1]);
			}
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "Usage: " << av[0] << " -p <points> -t <time>" << std::endl << "\t-p <points>: number of points to draw on, default 100" << std::endl << "\t-t <time>: time to wait between each point (in ms), default 50ms" << std::endl;
		exit(1);
	}

	this->points =  {Point(200 * this->size, 25 * this->size), Point(12.36 * this->size, 350 * this->size), Point(387.64 * this->size, 350 * this->size)};
}

Form::~Form( void )
{
	
}
