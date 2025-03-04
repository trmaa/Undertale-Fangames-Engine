#include <SFML/Graphics.hpp>
#include <engine/window.hpp>

Window::Display window;

void loop() {
    window.render();
}

int main() {
    Window::Text_box text_box("Hello :)", 16, sf::Vector2f(0, 0), sf::Vector2f(300, 100));

    window.drawable_add(0, text_box.get_sprite());

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        loop();
    }
}
