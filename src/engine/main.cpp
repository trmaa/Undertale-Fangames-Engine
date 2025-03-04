#include <SFML/Graphics.hpp>
#include <engine/window.hpp>
#include <game/game_main.hpp>

void loop() {
    game::loop();

    Engine::window().render();
}

int main() {
    game::start();

    while (Engine::window().isOpen()) {
        sf::Event event;
        while (Engine::window().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                Engine::window().close();
            }
        }

        loop();
    }
}
