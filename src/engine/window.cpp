#include <engine/window.hpp>

float dt = 0.f;
float &Engine::delta_time() { return dt; }

Engine::Window display;
Engine::Window &Engine::window() { return display; }
