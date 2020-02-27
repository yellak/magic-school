#include <Listenable.hpp>

void Listenable::addListener(std::string type, std::function<void(void)> listener)
{
    listeners[type].addListener(listener);
}

void Listenable::notifyListeners(std::string type)
{
    try
    {
        listeners.at(type).notifyListeners();
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << type << " listener not found: " << e.what() << std::endl;
    }
}

void ListenerContainer::addListener(std::function<void(void)> listener)
{
    listeners.push_back(listener);
}

void ListenerContainer::notifyListeners()
{
    for (auto listener : listeners)
    {
        listener();
    }
}