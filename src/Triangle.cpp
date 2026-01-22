#include "../include/Triangle.hpp"

int Det(Point A, Point B, Point M)
{
    return (A.x - M.x) * (B.y - M.y) - (A.y - M.y) * (B.x - M.x);
}

bool isInside(Point A, Point B, Point C, Point M)
{
    int Qa = Det(A, B, M);
    int Qb = Det(B, C, M);
    int Qc = Det(C, A, M);

    if ((Qa >= 0 && Qb >= 0 && Qc >= 0) || (Qa <= 0 && Qb <= 0 && Qc <= 0))
    {
        return true;
    }
    return false;
}

Triangle::Triangle(int ac, char **av)
{
    std::srand(std::time(nullptr));

    if (ac > 7)
    {
        std::cerr << "Usage: " << av[0] << " -p <points> -t <time>" << std::endl;
        exit(1);
    }

    if (ac == 2 && std::string(av[1]) == "-h")
    {
        std::cout << "Usage: " << av[0] << " -p <points> -t <time>" << std::endl << "\t-p <points>: number of points to draw on, default 100" << std::endl << "\t-t <time>: time to wait between each point (in ms), default 50ms" << std::endl;
        exit(0);
    }

    try
    {
        for (int i = 1; i < ac; i++)
        {
            if (std::string(av[i]) == "-p")
            {
                this->point_number = std::stoi(av[i + 1]);
            }
            if (std::string(av[i]) == "-t")
            {
                this->timer = std::stod(av[i + 1]);
            }
            if (std::string(av[i]) == "-s")
            {
                this->size = std::stod(av[i + 1]);
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

void Triangle::generateRandomPoint()
{
    int x = (points[2].x - points[1].x + 1) * 1000;
    int y = (points[1].y - points[0].y + 1) * 1000;

    while (!isInside(points[0], points[1], points[2], M))
    {
        this->M = Point((std::rand() % x + (points[1].x * 1000)) / 1000, (std::rand() % y + (points[0].y * 1000)) / 1000);
    }
    // M = Point(200, 255);
    this->M.color = sf::Color(std::rand() % 255, std::rand() % 255, std::rand() % 255);
    this->points_vector.push_back(M);
}

Point Triangle::calcNewPoint(Point A, Point B)
{
    return Point((A.x + B.x) / 2, (A.y + B.y) / 2);
}

int Triangle::pickRandomPoint()
{
    return std::rand() % 3;
}

void Triangle::addNewPoint()
{
    int random = pickRandomPoint();

    this->M = calcNewPoint(points[random], M);
    this->M.color = sf::Color(std::rand() % 255, std::rand() % 255, std::rand() % 255);
    this->points_vector.push_back(M);
}

// Ajouter un systeme de taille avec un parametre -s <size> pour la taille de la fenetre,
// Le triangle doit adapter sa taille en fonction de la taille de la fenetre