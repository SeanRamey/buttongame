#include <map>
#include <string>
#include <iostream>
#include <cstdlib>

#include "resources.hpp"

#define FILE_BUTTON_GREEN_PRESSED "data/graphics/green-button-pressed.png"
#define FILE_BUTTON_GREEN_RELEASED "data/graphics/green-button-unpressed.png"

namespace Resources {

	std::map<TextureID, sf::Texture*> textureMap;
	std::map<SoundID, sf::SoundBuffer*> soundBufferMap;
	std::map<SoundID, sf::Sound*> soundMap;
	sf::RenderWindow* window;

	std::string textureFiles[] = {
		FILE_BUTTON_GREEN_PRESSED,
		FILE_BUTTON_GREEN_RELEASED
	};

	///////////////////////////
	void load() {

		for(int i = 0; i < NUM_TEXTURES; i++) {
			sf::Texture *texture = new sf::Texture();
			textureMap[(TextureID)i] = nullptr; // make sure each texture pointer is initialized to null
			if(!texture->loadFromFile(textureFiles[i])) {
				std::cout << "Unable to load texture: " + textureFiles[i] << std::endl;
				std::exit(-1);
			} else {
				textureMap[(TextureID)i] = texture;
			}
		}

		/*for(int i = 0; i < NUM_SOUNDS; i++) {
			sf::SoundBuffer *buffer = new sf::SoundBuffer();
			sf::Sound *sound = new sf::Sound();
			soundBufferMap[(SoundID)i] = nullptr; // make sure each sound pointer is initialized to null
			if(!buffer->loadFromFile(soundFiles[i])) {
				std::cout << "Unable to load sound: " + soundFiles[i] << std::endl;
				std::exit(-1);
			} else {
				soundBufferMap[(SoundID)i] = buffer;
				sound->setBuffer(*buffer);
				soundMap[(SoundID)i] = sound;
			}
		}*/
	}

	///////////////////////////
	void unload() {
		for(int i = 0; i < NUM_TEXTURES; i++) {
			sf::Texture* texture = textureMap[(TextureID)i];
			if(texture != nullptr) {
				delete texture;
			}
		}

		for(int i = 0; i < NUM_SOUNDS; i++) {
			sf::SoundBuffer *buffer = soundBufferMap[(SoundID)i];
			sf::Sound *sound = soundMap[(SoundID)i];

			if(sound != nullptr) {
				delete sound;
			}

			if(buffer != nullptr) {
				delete buffer;
			}
		}
	}

	///////////////////////////
	void playSound(SoundID id) {
		if(soundMap[id] != nullptr) {
			soundMap[id]->play();
		}
	}

	///////////////////////////
	sf::Sound* getSound(SoundID id) {
		if(soundMap[id] == nullptr) {
			return nullptr;
		}
		return soundMap[id];
	}

	///////////////////////////
	sf::Texture* getTexture(TextureID id) {
		if(textureMap[id] == nullptr) {
			return nullptr;
		}
		return textureMap[id];
	}

	///////////////////////////
	sf::SoundBuffer* getSoundBuffer(SoundID id) {
		if(soundBufferMap[id] == nullptr) {
			return nullptr;
		}
		return soundBufferMap[id];
	}

}
