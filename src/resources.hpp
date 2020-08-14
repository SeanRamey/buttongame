#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

namespace Resources {

	extern sf::RenderWindow* window;

	enum TextureID : int {
		BUTTON_GREEN_PRESSED,
		BUTTON_GREEN_RELEASED,
		NUM_TEXTURES
	};

	enum SoundID : int {
		NUM_SOUNDS
	};

	void load();
	void unload();
	void playSound(SoundID id);
	sf::Sound* getSound(SoundID id);
	sf::Texture* getTexture(TextureID id);
	sf::SoundBuffer* getSoundBuffer(SoundID id);
}
