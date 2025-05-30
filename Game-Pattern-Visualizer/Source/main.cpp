/**
 * @ Author: Foldear
 * @ Filename: main.cpp
 * @ Modified time: 2025-05-22 14:35:36
 * @ Description: Main file
 */

#include <SFML/Graphics.hpp>

#include "Application/Application.hpp"
#include "Components/Button/Button.hpp"
#include "States/MenuState.hpp"

#define SCREEN_RESOLUTION_WIDTH 1920
#define SCREEN_RESOLUTION_HEIGHT 1080
#define APPLICATION_NAME "GAME-PATTERN-VISUALIZER"

int main()
{
    sf::RenderWindow window(sf::VideoMode({SCREEN_RESOLUTION_WIDTH, SCREEN_RESOLUTION_HEIGHT}), APPLICATION_NAME,
                            sf::Style::Default);
    GPV::Application application(std::make_unique<GPV::MenuState>(), window);

    application.run();
}