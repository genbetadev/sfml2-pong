#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Score.hpp"

class Ball : public sf::Sprite
{
public:
	Ball();

	void update(sf::Time& delta, sf::FloatRect& p1, sf::FloatRect& p2, Score& score);

	float getSpeedX() const;

private:
	sf::Texture texture_ball;
	sf::Vector2f speed;
	sf::SoundBuffer buffer;
	sf::Sound sound;
}; // class Ball

#endif // BALL_HPP