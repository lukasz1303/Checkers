#include "../include/Scaleable.h"

using namespace sf;


Texture Scaleable::getTexture()
{
	return texture;
}

Vector2f Scaleable::getSize()
{
	return size;
}

Vector2f Scaleable::getScale()
{
	return scale;
}

Vector2f Scaleable::getPosition()
{
	return position;
}

void Scaleable::setTexture(Texture t)
{
	texture = t;
	textureSize = t.getSize();
}

void Scaleable::setSize(Vector2f scale)
{
	size = Vector2f(textureSize.x * scale.x, textureSize.y * scale.y);
}

void Scaleable::setScale(Vector2f s)
{
	scale = s;
}

void Scaleable::setPosition(Vector2f p)
{
	position = p;
}

Sprite Scaleable::createSprite()
{
	Sprite sprite = Sprite(texture);
	sprite.setScale(scale);
	sprite.setPosition(position);
	return sprite;
}