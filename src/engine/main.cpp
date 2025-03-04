#include <SFML/Graphics.hpp>
#include <engine/window.hpp>
#include <game/game_main.hpp>

void loop() {
    game::loop();

    window().render();
}

int main() {
    game::start();

    while (window().isOpen()) {
        sf::Event event;
        while (window().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window().close();
            }
        }

        loop();
    }
}
