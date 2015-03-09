#ifndef PLATFORMER_PAINTER_HPP
#define PLATFORMER_PAINTER_HPP

#include <memory>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#include "StartMenu.hpp"

namespace platformer
{

class Painter
{
public:
    Painter(std::shared_ptr<sf::RenderWindow> aWindow,
            const StartMenu* aStartMenu);

    void drawSplashScreen() const;
    void drawStartMenu(OptsEnum aCoveredOption);

private:
    std::shared_ptr<sf::RenderWindow> m_Window;
    sf::Font                          m_Font;
    sf::Text                          m_SplashScreenHeader;
    sf::RectangleShape                m_MenuRect;
    std::vector<sf::Text>             m_MenuTitles;
};

} // namespace platformer

#endif // PLATFORMER_PAINTER_HPP
