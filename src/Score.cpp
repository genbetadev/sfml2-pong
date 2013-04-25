#include "Score.hpp"
#include "config.hpp"
#include <sstream>

Score::Score()
{
	// Establecemos los puntos a 0
	points_player = 0;
	points_ia = 0;
	// Cargamos la fuente
	font.loadFromFile("data/OpenSans.ttf");
	// Establecemos la fuente cargafa a los textos
	text_player.setFont(font);
	text_ia.setFont(font);
	// Establecemos el tamaño de letra de los textos
	text_player.setCharacterSize(30);
	text_ia.setCharacterSize(30);
	// Establecemos el color de los texto
	text_player.setColor(sf::Color::White);
	text_ia.setColor(sf::Color::White);
	// Establecemos las posiciones en cada esquina superior
	text_player.setPosition(20, 20);
	text_ia.setPosition(WIDTH - 20 - text_ia.getLocalBounds().width, 20);
}

void Score::addPointPlayer()
{
	points_player++;
}

void Score::addPointIA()
{
	points_ia++;
}

void Score::show(sf::RenderWindow& window)
{
	// Creamos 2 streams para pasar de int a string
	std::stringstream ia;
	std::stringstream ju;
	// Obtenemos las cadenas desde los puntos
	ia << points_ia;
	ju << points_player;
	// Establecemos las cadenas en los textos
	text_ia.setString(ia.str());
	text_player.setString(ju.str());

	// Recalculamos la posición del texto derecho para que se mantenga alineado
	text_ia.setPosition(WIDTH - 20 - text_ia.getLocalBounds().width, 20);

	// dibujamos los textos en la ventana
	window.draw(text_player);
	window.draw(text_ia);
}