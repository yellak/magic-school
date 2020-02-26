#include <functional>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <map>

/**
 * @brief Container of listeners.
 * This class has a container os listeners that will be run
 * in the apropriate moment depending on the object that is
 * listened.
 */
class ListenerContainer
{
    public:
        inline ~ListenerContainer()
        {
            listeners.clear();
            listeners.shrink_to_fit();
        }

        /**
         * @brief Add a listener to the listeners container.
         */
        void addListener(std::function<void(void)>);

        /**
         * @brief Notify all the listeners.
         * Work by executing each listener in the listeners container
         */
        void notifyListeners();

    private:
        std::vector<std::function<void(void)>> listeners;
};

/**
 * @brief Defines an object that can be listened.
 */
class Listenable
{
    public:
        inline ~Listenable()
        {
            listeners.clear();
        }

    protected:
        /**
         * @brief Add a new listener to the listeners map.
         * 
         * @param type The type of the listener (click ou value change listener for example).
         * @param listener The listener to add.
         */
        void addListener(std::string type, std::function<void(void)> listener);

        /**
         * @brief Notify listeners.
         * Notify all the listeners that matches the type specified.
         */
        void notifyListeners(std::string);

    private:
        std::map<std::string, ListenerContainer> listeners;
};