#include <utility>

#include "StartMenu.hpp"

namespace platformer
{

StartMenu::StartMenu(const sf::Vector2u& aSize)
{
    float sWidth  = static_cast<float>(aSize.x);
    float sHeight = static_cast<float>(aSize.y);

    m_MainRect = sf::FloatRect(0.25*sWidth, 0.3*sHeight,
                               0.5 *sWidth, 0.4*sHeight);

    sf::FloatRect sRects[4];
    float delta = m_MainRect.height / 4;
    for (int i = 0; i < 4; ++i)
        sRects[i] = sf::FloatRect(m_MainRect.left, m_MainRect.top + delta*i,
                                  m_MainRect.width, delta);

    m_Options =
    {
        std::make_pair("Singleplayer", sRects[0]),
        std::make_pair(" Multiplayer", sRects[1]),
        std::make_pair("   Options  ", sRects[2]),
        std::make_pair("    Quit    ", sRects[3])
    };
}

OptsEnum StartMenu::contains(float aX, float aY) const
{
    if (!m_MainRect.contains(aX, aY))
        return optNot;

    if (m_Options[0].second.contains(aX, aY))
        return optSingle;
    if (m_Options[1].second.contains(aX, aY))
        return optMulti;
    if (m_Options[2].second.contains(aX, aY))
        return optOpts;

    return optQuit;
}

OptsEnum StartMenu::contains(const sf::Vector2i& aVector) const
{
    return contains(static_cast<float>(aVector.x),
                    static_cast<float>(aVector.y));
}

} // namespace platformer
