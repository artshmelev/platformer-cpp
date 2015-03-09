#include <functional>

#include <SFML/Window/Event.hpp>

#include "App.hpp"

namespace platformer
{

App::App()
{
    m_Window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600),
                                                  "PlatformerCPP");
    m_StartMenu.reset(new StartMenu(m_Window->getSize()));
    m_Painter = std::make_shared<Painter>(m_Window, m_StartMenu.get());
    m_Game.reset(new Game);
}

void App::run()
{
    m_IsRunning = true;
    showSplashScreen();
    showStartMenu();
}

void App::showSplashScreen()
{
    sf::Clock sClock;
    while (m_Window->isOpen())
    {
        sf::Event sEvent;
        while (m_Window->pollEvent(sEvent))
        {
            if (sEvent.type == sf::Event::Closed)
                m_Window->close();
        }

        m_Painter->drawSplashScreen();

        if (sClock.getElapsedTime().asSeconds() >= 3.0)
            break;
    }
}

void App::showStartMenu()
{
    while (m_IsRunning)
    {
        OptsEnum sSelectedOption = waitMenuActions();

        switch (sSelectedOption)
        {
        case optSingle:
            m_Game->start();
            break;
        case optQuit:
            m_Window->close();
            m_IsRunning = false;
            break;
        default:
            break;
        }
    }
}

OptsEnum App::waitMenuActions()
{
    sf::Event sEvent;
    OptsEnum sPressedOption, sCoveredOption;

    while (m_Window->isOpen())
    {
        while (m_Window->pollEvent(sEvent))
        {
            switch (sEvent.type)
            {
            case sf::Event::Closed:
                m_Window->close();
                break;
            case sf::Event::MouseButtonPressed:
                sPressedOption = m_StartMenu->contains(sEvent.mouseButton.x,
                                                       sEvent.mouseButton.y);
                if (sPressedOption != optNot)
                    return sPressedOption;
                break;
            default:
                break;
            }
        }

        sf::Vector2i sMousePos = sf::Mouse::getPosition(*(m_Window.get()));
        sCoveredOption = m_StartMenu->contains(sMousePos);

        m_Painter->drawStartMenu(sCoveredOption);
    }

    return optQuit;
}

} // namespace platformer
