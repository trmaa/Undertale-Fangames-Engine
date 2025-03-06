#ifndef WINDOW_TEXT_BOX_HPP
#define WINDOW_TEXT_BOX_HPP

#include <SFML/Graphics.hpp>
#include <string>

namespace Engine //all the file
{

class Text_box {
private:
    sf::Font m_font;
    sf::Text m_text;
    sf::RectangleShape m_background;

    sf::RenderTexture m_compiled_buffer;

    sf::Sprite m_sprite;

private:
    void m_font_load() {
        if (!this->m_font.loadFromFile("bin/fnt/comicsans.otf")) {
            throw std::runtime_error("Failed to load font!");
        }
    }

    void m_compile_buffer(sf::Text text, sf::RectangleShape background) {
        float outline_thickness = background.getOutlineThickness();

        sf::Vector2f textureSize(
            background.getSize().x + 2 * outline_thickness,
            background.getSize().y + 2 * outline_thickness
        );

        this->m_compiled_buffer.create(static_cast<unsigned int>(textureSize.x), static_cast<unsigned int>(textureSize.y));
        this->m_compiled_buffer.clear(sf::Color::Transparent);

        background.setPosition(outline_thickness, outline_thickness);
        text.setPosition(text.getPosition() + sf::Vector2f(outline_thickness, outline_thickness));

        this->m_compiled_buffer.draw(background);
        this->m_compiled_buffer.draw(text);

        this->m_compiled_buffer.display();
    }

    void m_sprite_update() {
        this->m_sprite.setTexture(this->m_compiled_buffer.getTexture());
        this->m_sprite.setPosition(
                this->m_background.getPosition()
                - sf::Vector2f(this->m_background.getOutlineThickness(), this->m_background.getOutlineThickness()));
    }

public:
    sf::Sprite *get_sprite() { return &this->m_sprite; }

    Text_box(std::string text, int f_size, sf::Vector2f pos, sf::Vector2f size) {
        this->m_font_load();

        pos += sf::Vector2f(8, 8);
        this->set_text(pos, f_size, text);
        this->set_background(pos, size);

        this->sprite_update();
    }

public:
    void set_text(sf::Vector2f pos, int f_size, std::string text) {
        sf::Vector2f offset(f_size/2.f, f_size/2.f);
        this->m_text.setPosition(pos + offset);
        this->m_text.setFont(this->m_font);
        this->m_text.setString(text);
        this->m_text.setCharacterSize(f_size);
        this->m_text.setFillColor(sf::Color::White);
    }

    void set_background(sf::Vector2f pos, sf::Vector2f size) {
        this->m_background.setPosition(pos);
        this->m_background.setSize(size);
        this->m_background.setFillColor(sf::Color::Black);
        this->m_background.setOutlineColor(sf::Color::White);
        this->m_background.setOutlineThickness(8);
    }

    void sprite_update() {
        this->m_compile_buffer(this->m_text, this->m_background);
        this->m_sprite_update();
    }
};

}

#endif
