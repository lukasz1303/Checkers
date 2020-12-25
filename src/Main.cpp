#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include "../include/Pawn.h"
#include "../include/Board.h"
#include "../include/Mainmenu.h"
#include "../include/Game.h"
#include "../include/Loadgame.h"
#include "../include/Main.h"
#include "../include/LoadException.h"

using namespace sf;
using namespace std;

int screen_width = 1100;
int screen_height = 800;

int main()
{
	RenderWindow window(VideoMode(screen_width, screen_height), "Warcaby");

		Mainmenu menu(window.getSize().x, window.getSize().y);

		while (window.isOpen()) {
			Event event;
			menu.draw(window);
			window.display();
			while (window.waitEvent(event)) {

				if (event.type == Event::Closed)
				{
					window.close();
				}

				menu.ustawmyszke(window);

				menu.draw(window);
				window.display();

				if (event.type == Event::MouseButtonPressed && event.key.code == Mouse::Left) {
					switch (menu.wybranaopcja())
					{
					case 0: {
						menu.oknonickname(window);

						Game* newGame = new Game();
						newGame->run(window);
						
						delete newGame;
						
						break;
					}
					case 1: {
					
						try {
							Loadgame* loaded = new Loadgame();
							loaded->run(window);
							delete loaded;
						}
						catch (LoadException & e) {							
							e.what();
							break;
						}
						break;
					}
					case 2: {
						
						menu.zasady(window);
						break;
					}

					case 3:
						
						return 0;
						break;
					case 4:
						
						break;
					}
				}
			}
			if (event.type == Event::Closed)
				window.close();
		}
	return 0;
}