#pragma once
#include "../include/Mainmenu.h"


Mainmenu::Mainmenu(float width, float height) {
	try {
		font.loadFromFile("Fonts/arial.ttf") ? 1 : throw TextureException();
		backgroundtexture.loadFromFile("Texture/Menu.png") ? 1 : throw TextureException();
	}
	catch (TextureException & e) {
		e.what();
	}
	
	backgroundtexture.loadFromFile("Texture/Menu.png");
	background.setTexture(backgroundtexture);

	Vector2u background_size = backgroundtexture.getSize();
	Vector2f background_scale = Vector2f((float)width / (float)background_size.x, (float)height / (float)background_size.y);

	background.setScale(background_scale);

	text[0].setFont(font);
	text[0].setFillColor(Color::Yellow);
	text[0].setString("New Game");
	FloatRect textRect0 = text[0].getLocalBounds();
	text[0].setOrigin(textRect0.left + textRect0.width / 2.0f,textRect0.top + textRect0.height / 2.0f);
	text[0].setPosition(sf::Vector2f(width / 2.0f, height / 5*1));

	text[1].setFont(font);
	text[1].setFillColor(Color::White);
	text[1].setString("Load Last Game");
	FloatRect textRect1 = text[1].getLocalBounds();
	text[1].setOrigin(textRect1.left + textRect1.width / 2.0f, textRect1.top + textRect1.height / 2.0f);
	text[1].setPosition(sf::Vector2f(width / 2.0f, height / 5 * 2));

	text[2].setFont(font);
	text[2].setFillColor(Color::White);
	text[2].setString("Rules");
	FloatRect textRect2 = text[2].getLocalBounds();
	text[2].setOrigin(textRect2.left + textRect2.width / 2.0f, textRect2.top + textRect2.height / 2.0f);
	text[2].setPosition(sf::Vector2f(width / 2.0f, height / 5 * 3));

	text[3].setFont(font);
	text[3].setFillColor(Color::White);
	text[3].setString("Exit");
	FloatRect textRect3 = text[3].getLocalBounds();
	text[3].setOrigin(textRect3.left + textRect3.width / 2.0f, textRect3.top + textRect3.height / 2.0f);
	text[3].setPosition(sf::Vector2f(width / 2.0f, height / 5 * 4));

	nick[0].setFont(font);
	nick[0].setFillColor(Color::Yellow);
	nick[0].setString("Imie pierwszego gracza");
	FloatRect textRect4 = nick[0].getLocalBounds();
	nick[0].setOrigin(textRect4.left + textRect4.width / 2.0f, textRect4.top + textRect4.height / 2.0f);
	nick[0].setPosition(sf::Vector2f(width / 2.0f, height / 5 * 1));

	nick[1].setFont(font);
	nick[1].setFillColor(Color::Yellow);
	nick[1].setString("Imie drugiego gracza");
	FloatRect textRect5 = nick[1].getLocalBounds();
	nick[1].setOrigin(textRect5.left + textRect5.width / 2.0f, textRect5.top + textRect5.height / 2.0f);
	nick[1].setPosition(sf::Vector2f(width / 2.0f, height / 5 * 3));

	player[0].setFont(font);
	player[0].setString("Player 1");
	player[0].setFillColor(sf::Color::White);
	player[0].setStyle(sf::Text::Italic);
	FloatRect textRect6 = player[0].getLocalBounds();
	player[0].setOrigin(textRect6.left + textRect6.width / 2.0f, textRect6.top + textRect6.height / 2.0f);
	player[0].setPosition(sf::Vector2f(width / 2.0f, height / 5 * 2));

	player[1].setFont(font);
	player[1].setString("Player 2");
	player[1].setFillColor(sf::Color::White);
	player[1].setStyle(sf::Text::Italic);
	FloatRect textRect7 = player[1].getLocalBounds();
	player[1].setOrigin(textRect7.left + textRect7.width / 2.0f, textRect7.top + textRect7.height / 2.0f);
	player[1].setPosition(sf::Vector2f(width / 2.0f, height / 5 * 4));
	
	selectedItemIndex = 0;

	zasadytxt[0].setFont(font);
	zasadytxt[0].setFillColor(Color::Yellow);
	zasadytxt[0].setString("Zasady Gry");
	FloatRect textRectz0 = zasadytxt[0].getLocalBounds();
	zasadytxt[0].setOrigin(textRectz0.left + textRectz0.width / 2.0f, textRectz0.top + textRectz0.height / 2.0f);
	zasadytxt[0].setPosition(sf::Vector2f(width / 2.0f, height / 7 * 1));

	zasadytxt[1].setFont(font);
	zasadytxt[1].setFillColor(Color::White);
	zasadytxt[1].setString("1. Bicie jest przymusowe.");
	FloatRect textRectz1 = zasadytxt[1].getLocalBounds();
	zasadytxt[1].setOrigin(textRectz1.left + textRectz1.width / 2.0f, textRectz1.top + textRectz1.height / 2.0f);
	zasadytxt[1].setPosition(sf::Vector2f(width / 2.0f, height / 7 * 2));

	zasadytxt[2].setFont(font);
	zasadytxt[2].setFillColor(Color::White);
	zasadytxt[2].setString("2. Jest mozliwe bicie do tylu.");
	FloatRect textRectz2 = zasadytxt[2].getLocalBounds();
	zasadytxt[2].setOrigin(textRectz2.left + textRectz2.width / 2.0f, textRectz2.top + textRectz2.height / 2.0f);
	zasadytxt[2].setPosition(sf::Vector2f(width / 2.0f, height / 7 * 3));

	zasadytxt[3].setFont(font);
	zasadytxt[3].setFillColor(Color::White);
	zasadytxt[3].setString("3. Damki moga poruszac sie dowolna ilosc pol.");
	FloatRect textRectz3 = zasadytxt[3].getLocalBounds();
	zasadytxt[3].setOrigin(textRectz3.left + textRectz3.width / 2.0f, textRectz3.top + textRectz3.height / 2.0f);
	zasadytxt[3].setPosition(sf::Vector2f(width / 2.0f, height / 7 * 4));

	zasadytxt[4].setFont(font);
	zasadytxt[4].setFillColor(Color::White);
	zasadytxt[4].setString("4. Wygrywa gracz ktory pozbawi przeciwnika jego figur, badz mozliwosci ruchu.");
	FloatRect textRectz4 = zasadytxt[4].getLocalBounds();
	zasadytxt[4].setOrigin(textRectz4.left + textRectz4.width / 2.0f, textRectz4.top + textRectz4.height / 2.0f);
	zasadytxt[4].setPosition(sf::Vector2f(width / 2.0f, height / 7 * 5));

	zasadytxt[5].setFont(font);
	zasadytxt[5].setFillColor(Color::Yellow);
	zasadytxt[5].setString("Powrot do menu");
	FloatRect textRectz5 = zasadytxt[5].getLocalBounds();
	zasadytxt[5].setOrigin(textRectz5.left + textRectz5.width / 2.0f, textRectz5.top + textRectz5.height / 2.0f);
	zasadytxt[5].setPosition(sf::Vector2f(width / 2.0f, height / 7 * 6));
}
Mainmenu::~Mainmenu(){
}
void Mainmenu::loadPlayersNames(Event event) {
	if (event.type == sf::Event::TextEntered && !playerHasName1)
	{
		if (event.text.unicode == '\b' && (playerInput.size() > 0))
			playerInput.erase(playerInput.size() - 1, 1);
		else if (event.text.unicode == '\b' && (playerInput.size() == 0))
			playerInput = "";
		else if (event.text.unicode > 31 && event.text.unicode < 128)
			playerInput += event.text.unicode;
		if (playerInput.size() > 7) {
			playerInput.erase(playerInput.size() - 1, 1);
		}
		player[0].setString(playerInput);
		player[0].setPosition(sf::Vector2f(width1 / 2.0f, height1 / 5 * 2));
		
	}
	if (event.type == sf::Event::KeyPressed) {

		if (event.key.code == sf::Keyboard::Return && !playerHasName1 && playerInput.length() > 0) {
			playerHasName1 = true;
			playerInput = "";
		}
	}

	if (event.type == sf::Event::TextEntered && !playerHasName2 && playerHasName1)
	{
		if (event.text.unicode == '\b' && (playerInput.size() > 0))
			playerInput.erase(playerInput.size() - 1, 1);
		else if (event.text.unicode == '\b' && (playerInput.size() == 0))
			playerInput = "";
		else if (event.text.unicode > 31 && event.text.unicode < 128)
			playerInput += event.text.unicode;

		if (playerInput.size() > 7) {
			playerInput.erase(playerInput.size() - 1, 1);
		}

		player[1].setString(playerInput);
		FloatRect textRect6 = player[1].getLocalBounds();
		player[1].setPosition(sf::Vector2f(width1 / 2.0f, height1 / 5 * 4));
		
	}
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Return && playerHasName1 && playerInput.length() > 0) {
			playerHasName2 = true;
			playerInput = "";
		}
	}
}
void Mainmenu::zasady(RenderWindow& window) {
	Event event;
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	while (window.isOpen()) {
		mouse_position = Mouse::getPosition(window);
		if (zasadytxt[5].getGlobalBounds().contains(mouse_position.x, mouse_position.y)) {
			zasadytxt[5].setFillColor(Color::Magenta);
		}
		else {
			zasadytxt[5].setFillColor(Color::Yellow);
		}
		window.clear();
		window.draw(background);
		for (int i = 0; i < 6; i++) {
			window.draw(zasadytxt[i]);
		}
		window.draw(zasadytxt[5]);
		window.display();
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			

			if (event.type == Event::MouseButtonPressed && event.key.code == Mouse::Left) {
				if (zasadytxt[5].getGlobalBounds().contains(mouse_position.x, mouse_position.y)) {
					
					return;
				}
			}
		}
	}
}
void Mainmenu::draw(RenderWindow& window) {
	window.clear();
	window.draw(background);
	for (int i = 0; i < 4; i++) {
		window.draw(text[i]);
	}
}

void Mainmenu::ustawmyszke(RenderWindow& window) {
	mouse_position = Mouse::getPosition(window);
	selectedItemIndex = 4;
	for (int i = 0; i < 4; i++) {
		if (text[i].getGlobalBounds().contains(mouse_position.x, mouse_position.y)) {
			if(text[i].getFillColor() != Color::Yellow)
				text[i].setFillColor(Color::Yellow);
			selectedItemIndex = i;
		}
		
		else
		{
			if (text[i].getFillColor() != Color::White)
				text[i].setFillColor(Color::White);
		}
		
	}
}

void Mainmenu::savenicknames() {
	ofstream file;
	file.open("saved game/imiona.dat");
	string tekst = player[0].getString();
	string tekst2 = player[1].getString();
	
	file << tekst << '\n' << tekst2 << '\n';
}

void Mainmenu::oknonickname(RenderWindow& window) {

	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	Event event;
	window.clear();
	window.draw(background);
	for (int i = 0; i < 2; i++) {
		window.draw(nick[i]);
		window.draw(player[i]);

	}
	window.display();
	while (window.isOpen()) {
		
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}

			if (!playerHasName2) {
				loadPlayersNames(event);
			}			
		}
		window.clear();
		window.draw(background);
		for (int i = 0; i < 2; i++) {
			window.draw(nick[i]);
			window.draw(player[i]);
		}
		window.display();
		if (playerHasName2) {
			savenicknames();
			player[0].setString("Player1");
			player[1].setString("Player2");
			playerHasName1 = false;
			playerHasName2 = false;
			break;
		}
	}
}