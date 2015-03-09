#ifndef PLATFORMER_STARTMENU_HPP
#define PLATFORMER_STARTMENU_HPP

#include <SFML/Graphics/Rect.hpp>

namespace platformer
{

enum OptsEnum
{
    optNot = -1,
    optSingle,
    optMulti,
    optOpts,
    optQuit
};


class StartMenu
{
public:
    typedef std::vector<std::pair<std::string, sf::FloatRect>> Options;

public:
    StartMenu(const sf::Vector2u& aSize);

    float top() const { return m_MainRect.top; }
    float left() const { return m_MainRect.left; }
    float width() const { return m_MainRect.width; }
    float height() const { return m_MainRect.height; }
    const Options& options() const { return m_Options; }

    OptsEnum contains(float aX, float aY) const;
    OptsEnum contains(const sf::Vector2i& aVector) const;

private:
    sf::FloatRect m_MainRect;
    Options       m_Options;
};

} // namespace platformer

#endif // PLATFORMER_STARTMENU_HPP
