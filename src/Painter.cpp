#include "Painter.hpp"

namespace platformer
{

Painter::Painter(std::shared_ptr<sf::RenderWindow> aWindow,
                 const StartMenu* aStartMenu) : m_Window(aWindow)
{
    if (!m_Font.loadFromFile("resources/fonts/font.ttf")) {}

    m_SplashScreenHeader.setFont(m_Font);
    m_SplashScreenHeader.setString("Platformer");
    m_SplashScreenHeader.setCharacterSize(44);
    m_SplashScreenHeader.setColor(sf::Color::Red);

    sf::FloatRect sRect = m_SplashScreenHeader.getLocalBounds();
    m_SplashScreenHeader.move((m_Window->getSize().x-sRect.width) / 2,
                              (m_Window->getSize().y-sRect.height) / 2);

    m_MenuRect = sf::RectangleShape(sf::Vector2f(aStartMenu->width(),
                                                 aStartMenu->height()));
    m_MenuRect.setPosition(aStartMenu->left(), aStartMenu->top());
    m_MenuRect.setFillColor(sf::Color::Black);
    m_MenuRect.setOutlineThickness(1);
    m_MenuRect.setOutlineColor(sf::Color::Red);

    sf::Text sText;
    sText.setFont(m_Font);
    sText.setCharacterSize(28);
    sText.setColor(sf::Color::Red);

    for (auto& opt: aStartMenu->options())
    {

        sText.setString(opt.first);
        sText.setPosition(opt.second.left +
                          (opt.second.width-sText.getLocalBounds().width)/2,
                          opt.second.top+10);

        m_MenuTitles.push_back(sText);
    }
}

void Painter::drawSplashScreen() const
{
    m_Window->clear(sf::Color::Black);
    m_Window->draw(m_SplashScreenHeader);
    m_Window->display();
}

void Painter::drawStartMenu(OptsEnum aCoveredOption)
{
    m_Window->clear(sf::Color::Black);
    m_Window->draw(m_MenuRect);

    for (std::size_t i = 0; i < m_MenuTitles.size(); ++i)
        m_MenuTitles[i].setColor(sf::Color::Red);

    if (aCoveredOption != optNot)
        m_MenuTitles[aCoveredOption].setColor(sf::Color::Green);

    for (auto& title: m_MenuTitles)
        m_Window->draw(title);

    m_Window->display();
}

} // namespace platformer
