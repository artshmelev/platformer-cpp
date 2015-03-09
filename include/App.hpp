#ifndef PLATFORMER_APP_HPP
#define PLATFORMER_APP_HPP

#include "Game.hpp"
#include "Painter.hpp"
#include "StartMenu.hpp"

namespace platformer
{

class App
{
public:
    App();
    void run();

private:
    void showSplashScreen();
    void showStartMenu();
    OptsEnum waitMenuActions();

    //void showOptionsMenu();

private:
    std::shared_ptr<sf::RenderWindow> m_Window;
    std::shared_ptr<Painter>          m_Painter;
    std::unique_ptr<StartMenu>        m_StartMenu;
    std::unique_ptr<Game>             m_Game;

    bool m_IsRunning = false;
    //std::unique_ptr<Game> m_Game;
    //std::unique_ptr<Config> m_Config;
};

} // namespace platformer

#endif // PLATFORMER_APP_HPP
