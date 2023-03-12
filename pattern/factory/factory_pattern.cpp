#include <iostream>
#include <string>
#include <vector>
#include <memory>

class IShape {
    public:
        virtual std::string getName() = 0;
};

class Triangle : public IShape {
    public:
        std::string getName() override {
            return "Triangle";
        }
};

class Square : public IShape {
    public:
        std::string getName() override {
            return "Square";
        }
};

class Circle : public IShape {
    public: 
        std::string getName() override {
            return "Circle";
        }
};

enum Type {
    TRIANGLE,
    SQUARE,
    CIRCLE
};

// Resonsible for createing and returning shape instances 
class Factory {
    public:
        ~Factory() = delete;
        Factory(const Factory&) = delete;
        Factory(const Factory&&) = delete;
        static Factory& getInstance() {
            if (nullptr == m_factoryInstance)
                m_factoryInstance = new Factory();
            return *m_factoryInstance;
        }
        
        // Factory method
        std::shared_ptr<IShape> createShape(Type t) {
            m_created++;
            switch (t) {
                case TRIANGLE:
                    return std::make_shared<Triangle>();
                    break;
                case SQUARE:
                    return std::make_shared<Square>();
                    break;
                case CIRCLE:
                    return std::make_shared<Circle>();
                    break;
                default:
                    std::cout << "Invalid instance requested" << std::endl;
                    return nullptr;
            }
        }

        std::size_t getNumCreated() const {
            return m_created;
        }

    private:
        Factory() {
            std::cout << "Factory constructor was called" << std::endl;
        }
        static Factory* m_factoryInstance;
        static std::size_t m_created;
        
};

Factory* Factory::m_factoryInstance = nullptr;
std::size_t Factory::m_created = 0;

int main() {

    // create some shapes
    std::vector<std::shared_ptr<IShape>> my_shapes;
    my_shapes.push_back(Factory::getInstance().createShape(TRIANGLE));
    my_shapes.push_back(Factory::getInstance().createShape(CIRCLE));
    my_shapes.push_back(Factory::getInstance().createShape(SQUARE));

    std::cout << "Created " << Factory::getInstance().getNumCreated() << std::endl;
    for (auto it : my_shapes) {
        std::cout << "Calling " << it->getName() << std::endl;
    }
    my_shapes.clear();

    std::cout << "Finished program" << std::endl;
    return 0;
}