#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Logger {
    public:
        /* 
           Retrieve the single instance of the object and 
           create exactly one if it does not exist on its 
           first call 
        */
        static Logger& getInstance() { // return a reference in order to forbit the user of the logger to free its (static) memory
            if (m_loggerInstance == nullptr)
                m_loggerInstance = new Logger();
            return *m_loggerInstance;
        }
        
        void printMessage(std::string&& message) {
            std::cout << "LOGGER: " << message << std::endl;
        }

        void addMessage(std::string&& newMessage) {
            m_messages.push_back(newMessage);
        }

        void printAllStoredMessages() {
            for (auto it : m_messages)
                std::cout << "LOGGER: " << it << std::endl;
        }

    private:
        static Logger * m_loggerInstance;
        std::vector<std::string> m_messages;

        Logger() {
            std::cout << "Logger was created" << std::endl;
        }
        ~Logger() {
            std::cout << "Logger was destructed" << std::endl;
        }
        Logger(const Logger& LoggerToCopy) {
            std::cout << "Copy constructor was called" << std::endl;
        }
}; 

Logger * Logger::m_loggerInstance = nullptr;

int main() {
    Logger::getInstance().printMessage("Test Log");
    
    Logger::getInstance().addMessage("Foo");
    Logger::getInstance().addMessage("Bar");
    Logger::getInstance().printAllStoredMessages();

    return 0;
}