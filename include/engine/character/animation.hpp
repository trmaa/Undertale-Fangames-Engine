#ifndef ENGINE_CHARACTER_ANIMATION_HPP
#define ENGINE_CHARACTER_ANIMATION_HPP

#include <SFML/Graphics.hpp>
#include <vector>

namespace Engine
{

class Animation
{
private:
	std::vector<sf::Vector2f> key_frames;
	std::vector<sf::Time> key_times;

public:
	Animation();
};

}

#endif
