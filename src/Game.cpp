#pragma once

#include"../include/Game.h"

void Game::loadPawns() {
	int n = 0;
	int m = 12;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (tab[i][j] != 0) {
				if (tab[i][j] == 1) {
					pawns[n]->setTexture(whitePawnTexture);
					pawns[n]->setKingTexture(whiteKingTexture);
					pawns[n]->setCoordinates(j, i);
					pawns[n]->setScale(pawns[n]->calculateScale(Checkerboard.getSize().x, Checkerboard.getSize().y));
					pawns[n]->setSize(pawns[n]->getScale());
					pawns[n]->setPosition(Vector2f(Checkerboard.getPosition().x + (2 * j + 1) * Checkerboard.getSize().x / 16.f - pawns[n]->getSize().x / 2.f, Checkerboard.getPosition().y + (2 * i + 1) * Checkerboard.getSize().y / 16.f - pawns[n]->getSize().y / 2.f));
					pawns[n]->hasCapture(tab);

					n++;
				}
				else if (tab[i][j] == -1) {
					pawns[m]->setBlack();
					pawns[m]->setTexture(blackPawnTexture);
					pawns[m]->setKingTexture(blackKingTexture);
					pawns[m]->setCoordinates(j, i);
					pawns[m]->setScale(pawns[m]->calculateScale(Checkerboard.getSize().x, Checkerboard.getSize().y));
					pawns[m]->setSize(pawns[m]->getScale());
					pawns[m]->setPosition(Vector2f(Checkerboard.getPosition().x + (2 * j + 1) * Checkerboard.getSize().x / 16.f - pawns[m]->getSize().x / 2.f, Checkerboard.getPosition().y + (2 * i + 1) * Checkerboard.getSize().y / 16.f - pawns[m]->getSize().y / 2.f));
					pawns[m]->hasCapture(tab);

					m++;
				}
				else if (tab[i][j] == -2) {
					
					pawns[m]->setBlack();
					pawns[m]->setTexture(blackKingTexture);
					pawns[m]->setKingTexture(blackKingTexture);
					pawns[m]->setKing();
					pawns[m]->setCoordinates(j, i);
					pawns[m]->setScale(pawns[m]->calculateScale(Checkerboard.getSize().x, Checkerboard.getSize().y));
					pawns[m]->setSize(pawns[m]->getScale());
					pawns[m]->setPosition(Vector2f(Checkerboard.getPosition().x + (2 * j + 1) * Checkerboard.getSize().x / 16.f - pawns[m]->getSize().x / 2.f, Checkerboard.getPosition().y + (2 * i + 1) * Checkerboard.getSize().y / 16.f - pawns[m]->getSize().y / 2.f));
					pawns[m]->hasCapture(tab);
					m++;
				}
				else if (tab[i][j] == 2) {
					pawns[n]->setTexture(whiteKingTexture);
					pawns[n]->setKingTexture(whiteKingTexture);
					pawns[n]->setKing();
					pawns[n]->setCoordinates(j, i);
					pawns[n]->setScale(pawns[n]->calculateScale(Checkerboard.getSize().x, Checkerboard.getSize().y));
					pawns[n]->setSize(pawns[n]->getScale());
					pawns[n]->setPosition(Vector2f(Checkerboard.getPosition().x + (2 * j + 1) * Checkerboard.getSize().x / 16.f - pawns[n]->getSize().x / 2.f, Checkerboard.getPosition().y + (2 * i + 1) * Checkerboard.getSize().y / 16.f - pawns[n]->getSize().y / 2.f));
					pawns[n]->hasCapture(tab);

					n++;
				}
			}
		}
	}

	for (int i = 0; i < 24; i++) {
		pawnsSprites.addElement(i,pawns[i]->createSprite());
	}
}

void Game::loadTexturesAndFont() {
	try {
		font.loadFromFile("Fonts/arial.ttf") ? 1 : throw TextureException();
		whitePawnTexture.loadFromFile("Texture/WhitePawn.png") ? 1 : throw TextureException();
		blackPawnTexture.loadFromFile("Texture/BlackPawn.png") ? 1 : throw TextureException();
		whiteKingTexture.loadFromFile("Texture/WhiteKing.png") ? 1 : throw TextureException();
		blackKingTexture.loadFromFile("Texture/BlackKing.png") ? 1 : throw TextureException();
		woodBackgroundTexture.loadFromFile("Texture/Background25.png") ? 1 : throw TextureException();
		boardTexture.loadFromFile("Texture/Board.png") ? 1 : throw TextureException();
	}
	catch (TextureException & e) {
		e.what();
	}
}

void Game::loadLettersAndNumbers() {
	for (int i = 0; i < 8; i++) {
		Text letter;
		letter.setFont(font);
		letter.setString((char)(int('A') + i));
		letter.setCharacterSize(40);
		letter.setFillColor(sf::Color::White);
		letter.setStyle(sf::Text::Bold);
		letter.setPosition(Checkerboard.getPosition() + Vector2f(Checkerboard.getSize().x / 16 - 16 + Checkerboard.getSize().x / 8 * i, -44));
		letters.addElement(i, letter);

		Text number;
		number.setFont(font);
		number.setString((char)(int('1') + i));
		number.setCharacterSize(40);
		number.setFillColor(sf::Color::White);
		number.setStyle(sf::Text::Bold);
		number.setPosition(Checkerboard.getPosition() + Vector2f(-28, Checkerboard.getSize().x / 16 - 22 + Checkerboard.getSize().x / 8 * i));
		numbers.addElement(i, number);
	}
	winner.setFont(font);
	winner.setCharacterSize(80);
	winner.setFillColor(sf::Color::Black);
	winner.setStyle(sf::Text::Bold);
	winner.setPosition(270, 270);
}

void Game::loadPlayers() {
	player1.setFont(font);
	player1.setCharacterSize(48);
	player1.setFillColor(sf::Color::White);
	player1.setStyle(sf::Text::Italic);
	player1.setPosition(centerOfMenuSectionX - player1.getLocalBounds().width / 2, Checkerboard.getPosition().y);

	player2.setFont(font);
	player2.setCharacterSize(48);
	player2.setFillColor(sf::Color::White);
	player2.setStyle(sf::Text::Italic);
	player2.setPosition(centerOfMenuSectionX - player2.getLocalBounds().width / 2, Checkerboard.getPosition().y + Checkerboard.getSize().y - (screen_height - Checkerboard.getSize().y)/1.5f);

	colorPawnPlayer1.setTexture(whitePawnTexture);
	colorPawnPlayer1.setScale(pawns[0]->calculateScale(Checkerboard.getSize().x, Checkerboard.getSize().y));
	colorPawnPlayer1.setPosition(centerOfMenuSectionX - colorPawnPlayer1.getLocalBounds().width * colorPawnPlayer1.getScale().x / 2, Checkerboard.getPosition().y + (screen_height - Checkerboard.getSize().y) / 1.3f);

	colorPawnPlayer2.setTexture(blackPawnTexture);
	colorPawnPlayer2.setScale(pawns[0]->calculateScale(Checkerboard.getSize().x, Checkerboard.getSize().y));
	colorPawnPlayer2.setPosition(centerOfMenuSectionX - colorPawnPlayer2.getLocalBounds().width * colorPawnPlayer2.getScale().x / 2, Checkerboard.getPosition().y + Checkerboard.getSize().y - (screen_height - Checkerboard.getSize().y) / 1.5f - colorPawnPlayer2.getLocalBounds().height*colorPawnPlayer2.getScale().y);

	amountOfWhiteText.setFont(font);
	amountOfWhiteText.setString("Amount of pawns: " + to_string(amountOfWhite));
	amountOfWhiteText.setCharacterSize(24);
	amountOfWhiteText.setFillColor(sf::Color::White);
	amountOfWhiteText.setPosition(centerOfMenuSectionX - amountOfWhiteText.getLocalBounds().width / 2, colorPawnPlayer1.getPosition().y + colorPawnPlayer1.getLocalBounds().height * colorPawnPlayer1.getScale().y + amountOfWhiteText.getLocalBounds().height * 0.5);

	amountOfBlackText.setFont(font);
	amountOfBlackText.setString("Amount of pawns: " + to_string(amountOfBlack));
	amountOfBlackText.setCharacterSize(24);
	amountOfBlackText.setFillColor(sf::Color::White);
	amountOfBlackText.setPosition(centerOfMenuSectionX - amountOfBlackText.getLocalBounds().width / 2, colorPawnPlayer2.getPosition().y - amountOfBlackText.getLocalBounds().height * 1.8);

	turnText.setFont(font);
	turnText.setString("Turn");
	turnText.setCharacterSize(48);
	turnText.setFillColor(sf::Color::White);
	turnText.setStyle(sf::Text::Bold);
	turnText.setPosition(centerOfMenuSectionX - turnText.getLocalBounds().width / 2, centerOfMenuSectionY - turnText.getLocalBounds().height * 2);

	powrot.setFont(font);
	powrot.setString("Main Menu");
	powrot.setCharacterSize(48);
	powrot.setFillColor(sf::Color::White);
	powrot.setStyle(sf::Text::Bold);
	powrot.setPosition(centerOfMenuSectionX - powrot.getLocalBounds().width / 2, Checkerboard.getPosition().y + Checkerboard.getSize().y / 1.6 - powrot.getLocalBounds().height * 0.8);
	
	if (turn) {
		turnSprite.setTexture(blackPawnTexture);
	}
	else {
		turnSprite.setTexture(whitePawnTexture);
	}
	turnSprite.setScale(pawns[0]->calculateScale(Checkerboard.getSize().x, Checkerboard.getSize().y));
	turnSprite.setPosition(centerOfMenuSectionX - turnSprite.getLocalBounds().width * turnSprite.getScale().x / 2, turnText.getPosition().y + turnSprite.getLocalBounds().height * turnSprite.getScale().y);
}

void Game::loadBoard() {
	Checkerboard.setTexture(boardTexture);
	Checkerboard.setScale(Checkerboard.calculateScale((float)screen_height, (float)screen_height));
	Checkerboard.setSize(Checkerboard.getScale());
	Checkerboard.setPosition(Checkerboard.calculatePosition((float)screen_height, (float)screen_height));

	boardSprite = Checkerboard.createSprite();
}

void Game::loadBackground() {
	woodBackground.setTexture(woodBackgroundTexture);

	Vector2u background_size = woodBackgroundTexture.getSize();
	Vector2f background_scale = Vector2f((float)screen_width / (float)background_size.x, (float)screen_height / (float)background_size.y);

	woodBackground.setScale(background_scale);
}

void Game::move(int i) {
	isMove = true;
	k = i;
	dx = mouse_position.x - pawnsSprites.getElement(k).getPosition().x;
	dy = mouse_position.y - pawnsSprites.getElement(k).getPosition().y;
}

void Game::checkCaptures() {
	if (!turn) {
		for (int i = 0; i < 12; i++)
		{
			if (!pawns[i]->isCaptured() && pawns[i]->getCanCapture()) {
				whiteCanCapture = true;
				break;
			}
		}
	}
	else {
		for (int i = 12; i < 24; i++)
		{
			if (!pawns[i]->isCaptured() && pawns[i]->getCanCapture()) {
				blackCanCapture = true;
				break;
			}
		}
	}
}

void Game::checkMoves() {
	if (!turn) {
		if (!whiteCanCapture) {
			amountWhiteCanMove = 0;
			for (int i = 0; i < 12; i++)
			{
				if (!pawns[i]->isCaptured()) {
					if (pawns[i]->canMove(tab)) {
						amountWhiteCanMove += 1;
					}
				}
			}
			if (amountWhiteCanMove == 0) {
				winner.setString("Winner\n Black");
				theEnd = true;
			}
		}
	}
	else {
		if (!blackCanCapture) {
			amountBlackCanMove = 0;
			for (int i = 12; i < 24; i++)
			{
				if (!pawns[i]->isCaptured()) {
					if (pawns[i]->canMove(tab)) {
						amountBlackCanMove += 1;
					}
				}
			}
			if (amountBlackCanMove == 0) {
				winner.setString("Winner\n White");
				theEnd = true;
			}
		}
	}
}

void Game::drawSprites(RenderWindow& window) {
	window.clear();
	window.draw(woodBackground);
	window.draw(boardSprite);

	for (int i = 0; i < 24; i++) {
		window.draw(pawnsSprites.getElement(i));
	}
	window.draw(pawnsSprites.getElement(k));
	for (int i = 0; i < 8; i++) {
		window.draw(letters.getElement(i));
		window.draw(numbers.getElement(i));
	}
	if (theEnd) {
		window.draw(winner);
	}

	window.draw(colorPawnPlayer1);
	window.draw(colorPawnPlayer2);
	window.draw(player1);
	window.draw(player2);
	window.draw(amountOfWhiteText);
	window.draw(amountOfBlackText);
	window.draw(turnText);
	window.draw(turnSprite);
	window.draw(powrot);
	window.display();
}

void Game::loadPlayersNames() {
	ifstream file;
	file.open("saved game/imiona.dat");
	if (!file.is_open())
		throw LoadException();
	string tekst;
	file >> tekst;
	player1.setString(tekst);
	file >> tekst;
	
	player2.setString(tekst);
}

void Game::savegame() {
	ofstream file;
	file.open("saved game/savepawns.dat");
	if (!file.is_open())
		throw LoadException();
		
	file<<amountWhiteCanMove << '\n';
	file << amountBlackCanMove << '\n';
	file << centerOfMenuSectionX << '\n';
	file << centerOfMenuSectionY << '\n';
		
	file << k << '\n';
	if (isMove) {
		file << 1 << '\n';
	}
	else {
		file << 0 << '\n';
	}
	if (turn) {
		file << 1 << '\n';
	}
	else {
		file << 0 << '\n';
	}
	if (whiteCanCapture) {
		file << 1 << '\n';
	}
	else {
		file << 0 << '\n';
	}
	if (blackCanCapture) {
		file << 1 << '\n';
	}
	else {
		file << 0 << '\n';
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			file << tab[i][j] << '\n';
		}	
	}
	file.close();
}

Game::Game()
{
	for (int i = 0; i < 24; i++)
	{
		pawns[i] = new Pawn();
	}
	loadTexturesAndFont();

	loadBoard();

	centerOfMenuSectionX = Checkerboard.getPosition().x + Checkerboard.getSize().x + (screen_width - Checkerboard.getPosition().x - Checkerboard.getSize().x) / 2;
	centerOfMenuSectionY = Checkerboard.getPosition().y + Checkerboard.getSize().y / 2;

	loadLettersAndNumbers();

	loadBackground();

	loadPawns();
	
	loadPlayersNames();

	loadPlayers();
}


Game::~Game()
{
}

void Game::run(RenderWindow& window)
{
	Event event;
	window.setVerticalSyncEnabled(true);

	while (window.isOpen())
	{
		checkMoves();
		
		mouse_position = Mouse::getPosition(window);
		if (powrot.getGlobalBounds().contains(mouse_position.x, mouse_position.y)) {
			powrot.setFillColor(Color::Yellow);
		}
		else
		{
			powrot.setFillColor(Color::White);
		}
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
	
			if (turn) {
				whiteCanCapture = false;
			}
			else {
				blackCanCapture = false;
			}
			checkCaptures();
			if (event.type == Event::MouseButtonPressed && event.key.code == Mouse::Left) {
				
				if (powrot.getGlobalBounds().contains(mouse_position.x, mouse_position.y)) {
					return;
				}
				if (turn) {
					if (blackCanCapture) {
						if (indexPawn != -1) {
							if (pawnsSprites.getElement(indexPawn).getGlobalBounds().contains(mouse_position.x, mouse_position.y)) {
								move(indexPawn);
							}
						}
						else {
							for (int i = 12; i < 24; i++) {
								if (pawnsSprites.getElement(i).getGlobalBounds().contains(mouse_position.x, mouse_position.y) && pawns[i]->getCanCapture()) {
									move(i);
								}
							}
						}
						blackCanCapture = false;
					}
					else {
						if (indexPawn != -1) {
							if (pawnsSprites.getElement(indexPawn).getGlobalBounds().contains(mouse_position.x, mouse_position.y)) {
								move(indexPawn);
							}
						}
						else {
							for (int i = 12; i < 24; i++) {
								if (pawnsSprites.getElement(i).getGlobalBounds().contains(mouse_position.x, mouse_position.y)) {
									move(i);
								}
							}
						}
					}
				}
				else {
					if (whiteCanCapture) {
						if (indexPawn != -1) {
							if (pawnsSprites.getElement(indexPawn).getGlobalBounds().contains(mouse_position.x, mouse_position.y)) {
								move(indexPawn);
							}
						}
						else {
							for (int i = 0; i < 12; i++) {
								if (pawnsSprites.getElement(i).getGlobalBounds().contains(mouse_position.x, mouse_position.y) && pawns[i]->getCanCapture()) {
									move(i);
								}
							}
						}
						whiteCanCapture = false;
					}
					else {
						if (indexPawn != -1) {
							if (pawnsSprites.getElement(indexPawn).getGlobalBounds().contains(mouse_position.x, mouse_position.y)) {
								move(indexPawn);
							}
						}
						else {
							for (int i = 0; i < 12; i++) {
								if (pawnsSprites.getElement(i).getGlobalBounds().contains(mouse_position.x, mouse_position.y)) {
									move(i);
								}
							}
						}
					}
				}
			}
			
			if (event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left) {
				isMove = false;
			
				Vector2u currentCoordinates = pawns[k]->getCoordinates();
				Vector2f currentPosition = pawnsSprites.getElement(k).getPosition() + Vector2f(pawns[k]->getSize().x / 2, pawns[k]->getSize().y / 2) - Checkerboard.getPosition(); // pozycja œrodka wybranego pionka wzglêdem planszy
				Vector2f newPosition = Vector2f(Checkerboard.getSize().x / 8.0 * int(currentPosition.x / (Checkerboard.getSize().x / 8.0)) + Checkerboard.getPosition().x + ((Checkerboard.getSize().x / 8.0 - pawns[k]->getSize().x) / 2.0),
				Checkerboard.getSize().y / 8.0 * int(currentPosition.y / (Checkerboard.getSize().y / 8.0)) + Checkerboard.getPosition().y + ((Checkerboard.getSize().y / 8.0 - pawns[k]->getSize().y) / 2.0));

				Vector2f correctNewPosition = pawns[k]->calculatePosition(Checkerboard.getPosition(), Checkerboard.getSize(), newPosition, tab);
				Vector2u newCoordinates = pawns[k]->getCoordinates();
				bool capture = false;
				
					for (int i = 0; i < 24; i++) {
						if (tab[pawns[i]->getCoordinates().y][pawns[i]->getCoordinates().x] == 0 && pawns[i]->getCoordinates() != Vector2u(100, 100)) {
							pawns[i]->setCoordinates(100, 100);
							if (pawns[i]->isBlack()) {
								amountOfBlack -= 1;
								amountOfBlackText.setString("Amount of pawns: " + to_string(amountOfBlack));
								if (amountOfBlack == 0) {
									winner.setString("Winner\n White");
									theEnd = true;
								}
							}
							else {
								amountOfWhite -= 1;
								amountOfWhiteText.setString("Amount of pawns: " + to_string(amountOfWhite));
								if (amountOfWhite == 0) {
									winner.setString("Winner\n Black");
									theEnd = true;
								}
							}
							capture = true;
							pawns[i]->setCaptured();
							pawnsSprites.getElement(i).setPosition(Vector2f(-100, -100));
						}
						if (!pawns[i]->isCaptured()) {
							pawns[i]->hasCapture(tab);
						}
					}

					checkCaptures();
					checkMoves();

					if ((!capture && currentCoordinates != newCoordinates) || (capture && !pawns[k]->getCanCapture())) {
						if (pawns[k]->getKingLastTurn() == true) {
							pawns[k]->setKingLastTurn(false);
						}
						turn = !turn;
						if ((pawns[k]->getCoordinates().y == 7 && !pawns[k]->isBlack()) || (pawns[k]->getCoordinates().y == 0 && pawns[k]->isBlack())) {
							pawns[k]->setKing();
							pawns[k]->loadKingTexture();
						}
						checkMoves();
						savegame();

						if (turn) {
							turnSprite.setTexture(blackPawnTexture);
						}
						else {
							turnSprite.setTexture(whitePawnTexture);
						}
						checkCaptures();
						indexPawn = -1;
					}
					else if (capture && pawns[k]->getCanCapture()) {
						indexPawn = k;
					}
					pawnsSprites.getElement(k).setPosition(correctNewPosition);
			}
			if (isMove) {
				pawnsSprites.getElement(k).setPosition(mouse_position.x - dx, mouse_position.y - dy);
			}
		}
		drawSprites(window);
	}
}