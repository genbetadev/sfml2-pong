#include "Pong.hpp"
#include "config.hpp"

Pong::Pong()
{
	// Creamos la ventana
	window.create(sf::VideoMode(WIDTH, HEIGHT, BPP), "Pong GenbetaDev", sf::Style::Close);
	// Activa la sincronización vertical (60 fps)
	window.setVerticalSyncEnabled(true);

	// Cargamos la textura desde un archivo
	texture_back.loadFromFile("data/background.png");
	// Asignamos la textura al sprite de fondo
	background.setTexture(texture_back);

	// Se ajusta las posiciones de cada pala
	pad_player.setPosition(40, HEIGHT/2);
	pad_ia.setPosition(WIDTH - 40, HEIGHT/2);

	// Se carga la música de fondo
	music.openFromFile("data/back_music.ogg");
	music.setLoop(true);
	music.play();
}

void Pong::run()
{
	// Game Loop mientras la ventana esté abierta
	while (window.isOpen())
	{
		// Reiniciamos el reloj almacenando el tiempo pasado
		time = clock.restart();

		// Creamos un objeto evento
		sf::Event event;
		// Procesamos la pila de eventos
		while (window.pollEvent(event))
		{
			// Si el evento es de tipo Closed cerramos la ventana
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Actualizamos los elementos del  juego
		pad_player.updateHuman(time);
		pad_ia.updateIA(time, ball);
		ball.update(time, pad_player.getGlobalBounds(), pad_ia.getGlobalBounds(), score);

		// Dibujamos los elementos del juego
		window.draw(background);
		window.draw(ball);
		window.draw(pad_player);
		window.draw(pad_ia);
		score.show(window);
 
		// Actualizamos la ventana
		window.display();
	}
}