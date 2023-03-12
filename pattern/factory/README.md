# Factory design pattern
+ Comes from the gang of four book
+ Is a ***creational*** design pattern

## Basic idea
+ Create different instances of an (abstract) base class and hide the implementation details of the derived classes
+ We do not call the constructors of the classes that are instanciated. This will be done by the factory method of our factory class.
+ We can only create instances on the heap --> From our factory method, we just get pointers to the instances that are created by it.
+ For the application developer/the user of the factory, it does not matter which concrete manifestation an instance that came from the factory has. It implements the interface which is everything we need to know in order to use the instance from the factory.

## Background
+ We use the object oriented programming paradigm heavily, especially polymorphism, since our factory returns instances that are referenced by the abstract base class!
    - In our main program (where we use the instances that are created by our factory), we call the instances just by the interface, even if they are a derived class.
+ Keep in mind: Interface classes/abstract base classes do ***NOT*** have memory associated with it!
    - Members of the instances that are needed to be accessed by the interface class are only defined in the derived classes and are allocated while createing a concrete instance of the base class (which is a derviced class).

## Best practices
+ Name the factory as a factory, i.e. `FooBarFactory`
+ To define what instance should be created, you should use an enum class to do this. Thereby you avoiding typo errors which would result in a `nullptr`.
    - Logouts are useful whenever an instance is instanciated by our factory
    - In this way, you use the compiler logic and the fact that C++ is a strongly typed language a little more
+ The base class implements an abstract method that returns an identifier of which derived class an instances that was created by the factory is
+ Use smartpointers in order to avoid memory leaks
    - This way, you will not forget the delete keyword
+ Or implement the factory as a singleton
    - Link in the coding example in factory_pattern.cpp

# References
+ https://www.youtube.com/watch?v=usmdZniV_Yw
+ https://www.youtube.com/watch?v=vAmDQKeC99g&list=PLvv0ScY6vfd9wBflF0f6ynlDQuaeKYzyc&index=3
+ https://www.youtube.com/watch?v=eLAvry56vLU&list=PLvv0ScY6vfd9wBflF0f6ynlDQuaeKYzyc&index=2