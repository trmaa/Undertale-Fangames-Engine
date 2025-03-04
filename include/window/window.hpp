#ifndef WINDOW_WINDOW_HPP
#define WINDOW_WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

namespace Window
{

class Display : public sf::RenderWindow {
private:
    std::vector<sf::Sprite> m_drawables;
    std::vector<sf::Texture> m_normalmaps;
    sf::Shader m_lighting;

private:
    void m_toggle_fullscreen(); //to do

public:
    Display() {
        this->create(sf::VideoMode(800, 600), "alicia_roguelike", sf::Style::Fullscreen);

        if (!this->m_lighting.loadFromFile("shaders/lighting.fsh", sf::Shader::Fragment)) {
			std::cerr << "Failed to load lighting shader!" << std::endl;
        }
    }

public:
    void render() {
        this->clear();

        for (size_t i = 0; i < m_drawables.size(); i++) {
            this->m_lighting.setUniform("texture", *m_drawables[i].getTexture());
            this->m_lighting.setUniform("position", m_drawables[i].getPosition());
            this->draw(m_drawables[i], &this->m_lighting);
        }

        this->display();
    }

    void drawable_add(int z_index, sf::Sprite spr) {
        this->m_drawables.push_back(spr);
        this->m_normalmaps.push_back(*spr.getTexture());
    }

    void drawable_destroy(int z_index) {
        this->m_drawables.erase(this->m_drawables.begin() + z_index);
        this->m_normalmaps.erase(this->m_normalmaps.begin() + z_index);
    }
};

}

#endif
