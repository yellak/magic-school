#include <iostream>

class Game
{
private:
    /**
     * @brief The title of the Game.
     */
    std::string title;

public:
    Game();
    std::string getTitle();
};