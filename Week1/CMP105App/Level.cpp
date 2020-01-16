#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	// initialise game objects
	//Red rectangle
	rectr.setSize(sf::Vector2f(250,200 ));
	rectr.setPosition(950, 400);
	rectr.setFillColor(sf::Color::Red);

	//Green rectangle
	rectg.setSize(sf::Vector2f(150, 100));
	rectg.setPosition(150, 150);
	rectg.setFillColor(sf::Color::Green);

	//Blue rectangle
	rectb.setSize(sf::Vector2f(100, 50));
	rectb.setPosition(175, 175);
	rectb.setFillColor(sf::Color::Blue);
	
	// Circle
	circle.setRadius(50);
	circle.setPosition(600, 300);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(2.f);

	//Render text
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading text from file\n";
	}
	text.setFont(font);
	text.setString("Hello World");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	sf::Vector2u pos = window->getSize();
	sf::Vector2f rectsize = rectr.getSize();
	rectr.setPosition(pos.x - rectsize.x, pos.y - rectsize.y);
}

// Render level
void Level::render()
{
	beginDraw();
	
	window->draw(rectr);
	//window->draw(rectg);
	//window->draw(rectb);
	//window->draw(text);
	//window->draw(circle);
	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}