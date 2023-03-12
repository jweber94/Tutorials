# Singleton pattern

## Basics
+ Singleton is a creational pattern --> How we instanciate instances in our program
+ Creation of exactly ***one*** instance of an object
    - The pattern enforces the creation of exactly one instance and forbids the creation of a second (or multiple) instances
+ Commonly used in loggers, filesystems, ...

## The `static` keyword in C++
+ A static variable is located in a special place in the (virtual) memory of our system. Therefore it is preserved and once the value is initialized, it will be there until the program terminates!
    - Even if the initialization is called multiple times, the initialization is *NOT* done everytime!
        * Example: (`i` will be 0 just on the first call of `counter()`)
```
void counter() {
    static int i = 0;
    std::cout << "i is " << i << std::endl;
    i++;
}
```
+ ***CAUTION***: Static members of a class *must* be initialized outside of the class!
    - Because the value is preserved during the complete runtume of the programm!
```
class TestClass {
    ...
    public:
        static m_myStaticMember;
};

TestClass::m_myStaticMember;

```

## Common pitfalls
+ The `static myClass* getInstance()` method returns a pointer and it is freed in the business logic of the program
    - This can be avoided by returning a reference to the static instance, i.e.: `static myClass& getInstance()`
+ The base implementation in the `singleton_pattern.cpp` is ***NOT*** thread safe!

# References
+ https://www.youtube.com/watch?v=eLAvry56vLU&list=PLvv0ScY6vfd9wBflF0f6ynlDQuaeKYzyc&index=2
+ https://refactoring.guru/design-patterns/singleton/cpp/example