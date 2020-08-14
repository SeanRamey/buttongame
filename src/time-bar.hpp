#pragma once

#include "observer.hpp"
#include "SFML/System/Clock.hpp"

class TimeBar : public Observer
{
public:
	void update() override;

private:
	sf::Clock timer;
};
