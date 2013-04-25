#ifndef PONG_HPP
#define PONG_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Ball.hpp"
#include "Paddle.hpp"
#include "Score.hpp"

class Pong
{
public:
	Pong();

	void run();

private:
	sf::RenderWindow window;
	sf::Clock clock;
	sf::Time time;

	sf::Texture texture_back;
	sf::Sprite background;

	sf::Music music;

	Ball ball;
	Paddle pad_player;
	Paddle pad_ia;

	Score score;
}; // class Pong

#endif // PONG_HPP