#include "../include/Sfml.hpp"

SFML::SFML(double i_size)
{
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

    sf::Vector2u windowSize = {
        static_cast<unsigned int>(std::round(SCREEN_WIDTH * i_size)),
        static_cast<unsigned int>(std::round(SCREEN_HEIGHT * i_size))
    };

    this->window.create(sf::VideoMode(windowSize), "Triangle Fractal Point Distribution");
    this->window.setFramerateLimit(60);

    this->window.setPosition(
        sf::Vector2i(
            static_cast<int>((desktopMode.size.x - windowSize.x) / 2),
            static_cast<int>((desktopMode.size.y - windowSize.y) / 2)
        )
    );
}

SFML::~SFML()
{
    this->window.close();
}

void SFML::analyseEvent()
{
    while (auto event = this->window.pollEvent())
        {
        if (event->is<sf::Event::Closed>() || sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Escape))
        {
            this->window.close();
            exit(0);
        }
    }
}

void SFML::display(Triangle &i_triangle, int counter)
{
    this->window.clear();

    int i = 0;

    sf::Font font;
    if (!font.openFromFile("asset/font.ttf"))
    {
        throw std::runtime_error("Impossible d'ouvrir le fichier font.ttf");
    }

    sf::Text text(font, "Points: " + std::to_string(counter), 22); // 22 = taille des caractères
    text.setLetterSpacing(1.f);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(10.f, 10.f)); // maintenant il faut un Vector2f

    std::vector<sf::Vertex> vertices;
    vertices.reserve(i_triangle.getPointsVector().size());

    for (auto &point : i_triangle.getPointsVector()) {
        vertices.push_back({sf::Vector2f(point.x, point.y), point.color});
    }

    this->window.draw(text);
    this->window.draw(vertices.data(), vertices.size(), sf::PrimitiveType::Points);
    this->drawTriangle(i_triangle.getPoints());
    this->window.display();
}

void SFML::drawTriangle(std::array<Point, 3> i_points)
{
    sf::Vertex AB[2];
    AB[0].position = sf::Vector2f(i_points[0].x, i_points[0].y);
    AB[0].color = sf::Color::White;
    AB[1].position = sf::Vector2f(i_points[1].x, i_points[1].y);
    AB[1].color = sf::Color::White;

    sf::Vertex BC[2];
    BC[0].position = sf::Vector2f(i_points[1].x, i_points[1].y);
    BC[0].color = sf::Color::White;
    BC[1].position = sf::Vector2f(i_points[2].x, i_points[2].y);
    BC[1].color = sf::Color::White;

    sf::Vertex CA[2];
    CA[0].position = sf::Vector2f(i_points[2].x, i_points[2].y);
    CA[0].color = sf::Color::White;
    CA[1].position = sf::Vector2f(i_points[0].x, i_points[0].y);
    CA[1].color = sf::Color::White;

    this->window.draw(AB, 2, sf::PrimitiveType::Lines);
    this->window.draw(BC, 2, sf::PrimitiveType::Lines);
    this->window.draw(CA, 2, sf::PrimitiveType::Lines);
}
