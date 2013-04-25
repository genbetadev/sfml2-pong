#include "Paddle.hpp"
#include "config.hpp"
#include "Ball.hpp"

Paddle::Paddle()
	: sf::RectangleShape()
{
	// Definimos la velocidad de la  pala (sólo y)
	this->speed = 300.0f;
	// Definimos el tamaño del rectángulo
	this->setSize(sf::Vector2f(18, 66));
	// Definimos el origen en el centro
	this->setOrigin(9, 33);
	// Establecemos el color de relleno en blanco
	this->setFillColor(sf::Color(255, 255, 255));
	// Establecemos el color del borde en negro
	this->setOutlineColor(sf::Color(0, 0, 0));
	// Establecemos el grosor del borde en 2 hacia dentro
	this->setOutlineThickness(-2.0f);
}

void Paddle::updateHuman(sf::Time& delta)
{
	// Obtenemos la posición superior e inferior
	float top = this->getGlobalBounds().top;
	float bottom = this->getGlobalBounds().top + this->getGlobalBounds().height;

	// Movemos la pala en función de las teclas pulsada
	// comprobando no salirnos de la pantalla
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && top > 0)
		this->move(0, -delta.asSeconds() * speed);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && bottom < HEIGHT)
		this->move(0, delta.asSeconds() * speed);
}

void Paddle::updateIA(sf::Time& delta, Ball& ball)
{
	// La IA solo mueve la pala si la bola va hacia ella y está en su campo
	if(ball.getSpeedX() >= 0 && ball.getPosition().x >= WIDTH/2.0f)
	{
		if(this->getPosition().y < ball.getPosition().y)
			this->move(0, this->speed * delta.asSeconds());
		if(this->getPosition().y > ball.getPosition().y)
			this->move(0, -this->speed * delta.asSeconds());
	}
}