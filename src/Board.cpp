#include "../include/Board.h"

Board::Board()
{
}

Board::Board(Texture t) {
	texture = t;
	textureSize = t.getSize();
}

Vector2f Board::calculateScale(float screenWidth, float screenHeight) {
	return Vector2f(screenWidth / (float)textureSize.x * 0.9f, screenHeight / (float)textureSize.y * 0.9f);
}

Vector2f Board::calculatePosition(float screenWidth, float screenHeight) {
	return  Vector2f((screenWidth - size.x) / 2, (screenHeight -size.y) / 2);
}