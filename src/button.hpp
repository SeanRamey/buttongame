#pragma once

#include "SFML/Graphics.hpp"
#include "subject.hpp"

class Button : public sf::Drawable, sf::Transformable, Subject
{
public:
	Button();
	~Button();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        target.draw(sprite, states);
    }

sf::Sprite sprite;

};
