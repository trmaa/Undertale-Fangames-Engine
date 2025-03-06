#ifndef WINDOW_CHARACTER_HPP
#define WINDOW_CHARACTER_HPP

#include <SFML/Graphics.hpp>
#include <engine/character/animation.hpp>

namespace Engine //all the file
{

class Character {
private:
    sf::Texture m_buffer;
    sf::Sprite m_sprite;

    sf::Vector2f m_position;

    Engine::Animation m_animation;

    int m_animation_sprite_tick;

public:
    const sf::Sprite &get_sprite() const { return this->m_sprite; }

    Character(std::string sprite_path, sf::Vector2f pos, sf::Vector2f size) {
        this->m_position = pos;

        this->m_buffer.loadFromFile(sprite_path);
        this->m_sprite.setTexture(this->m_buffer);
    }
};

}

#endif
