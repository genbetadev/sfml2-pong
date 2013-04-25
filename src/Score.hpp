#ifndef SCORE_HPP
#define SCORE_HPP

#include <SFML/Graphics.hpp>

class Score
{
public:
	Score();

	void show(sf::RenderWindow& window);

	void addPointPlayer();
	void addPointIA();

private:
	sf::Font font;
	sf::Text text_player;
	sf::Text text_ia;
	unsigned int points_player;
	unsigned int points_ia;
}; // class Score

#endif // SCORE_HPP