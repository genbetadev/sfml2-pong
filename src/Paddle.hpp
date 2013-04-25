#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp>

class Ball;

class Paddle : public sf::RectangleShape
{
public:
	Paddle();

	void updateHuman(sf::Time& delta);
	void updateIA(sf::Time& delta, Ball& ball);

private:
	float speed;

}; // class Paddle

#endif // PADDLE_HPP