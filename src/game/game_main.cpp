#include <engine/window.hpp>
#include <game/game_main.hpp>

static Window::Text_box player_stats("LV 1", 16, sf::Vector2f(0, 0), sf::Vector2f(300, 100));

void game::loop() {}

void game::start() {
	window().drawable_add(1, player_stats.get_sprite());
}
