# Typescript Introduction
+ I wanted to learn typescript because I want to build a CRUD app with angular 17. After starting with an angular 17 tutorial, I realized that I need to have some basic knowlage about typescript to work productively with angular.
+ I did the Tutorial on Youtube (caution: german language) here: https://www.youtube.com/watch?v=8AX6CgXlSEk

## Notes:
+ Typescript makes it possible to define datatypes for function parameters
  - This ensures, that no invalid data goes into a _function_!
+ Since nodejs or browsers could not interpret typescript directly, we need to compile/transpile our code to plain javascript
+ Typescript is the main frontend language!
  - Plain javascript is not the way to go today
+ Basic Type Script Project:
  - ```$ npm init && npm install typescript --save-dev```
    * `--save-dev` is for the typescript dev dependencies
+ Initialize typescript project
  - ```$ npx tsc --init```
  - Creates a basic typescript project in the current folder
  - npx is a convenience tool for createing projects with npm
+ Compile typescript to javascript:
  - ```$ npx tsc my_file.ts```
  - Run the file:
    * ```$ node my_file.js```
+ Typescript checks during compile time if we assign a variable a different datatype furter down the program
```
let a = 1;
a = "1";
```
==> This would result in a compiler error!
+ If we want to define a type for our variable, we can do it by
  * ```let b : string = "Hello World!";```
  * ***We just can use basic javascript datatypes!***
  * Define multiple possible datatypes: ```let c : string | number = 12;```
+ Best practice:
  - A variable should retain its initial type. We commonly do not assign concrete types to local variables!
  - A good IDE / VSCode shows our type inference in that case if we hower over the datatype
+ Functions:
  - Modern javascript function syntax:
```
const add_fcn = (a: number, b: number): number => {
  return a + b;
};
```
  - Datatypes for functionparameters are mandatory in typescript if we want our code to compile!
  - The `): number` defines the return type of our function
  - The `=> {};` syntax is a modern version of `var my_fcn = function(){}`
+ Tuples:
  - `let tup: [string, number] = ["Hello", 2];`
+ Objects storing as variables:
  - To store objects, we need to define an interface for the class to let the type inference work properly
  - Done with the keyword `interface`
    * Example:
```
interface ICustomer {
  name: string;
  money: number;
  pay_in: function;
}

let customer1: ICustomer = {
  name: "Jens";
  money: 1000000;
  pay_in: function (sum: number): void {
    this.money = this.money + sum;
  }
}
```
  * Caution: The `=>` notation only works for assignment of functions, where the function is on the rhs of the equal sign. If we want to define a datatype, we need to tell it the `function` datatype
  * Interfaces are very important to typescript!

+ Classes:
  - Defining a class
```
class Customer {
public: name: string;
public: is_valid: bool;
private: money: number;

constructor(name: string, money: number) {
  this.name = name;
  this.money = money;
}

getInfo(): void {
  console.log('Name: $(this.name) has $(this.money)');
}
}
```
  - Classes often use interfaces!
    * Define interface and then
```
interface ICustomer {
  name: string;
  money: number;
  pay_in: function;
}

class Customer implements ICustomer {
  constructor (public: name: string, private: money: number, public: pay_in: function) {
    // ...
  }
  // ...
}
```
+ Generics:
  - Exists in typescript
    * Like templates in C++
+ Decorators:
  - Are functions that can enhance functions or methods of classes

## Decorators
+ Are used to enhance functionallities of classes
+ Decorator names are written with a capital letter in front of its name
+ Decorators are just functions that are defined anywhere with an argument of the type `function`
  - Most decorators use closures to work properly! (*1)
+ If your typescript code (independend of angular) does not compile while you programmed your own decorator, you need to incomment the line "experimental-decorators" in the `tsconfig.json` file.
  - If this still does not surfice, you need to compile your code with a flag: `npx tsc decorators_example.ts --experimentalDecorators "true"`
  - Then, your code will be correclty compiled

## Furter Javascript and Typescript Tipps
+ Template Strings:
  - Can be used like a bash string!
  - Defined by a backtick instead of a normal tick
  - Example:
    * `console.log("Message: ${this.message}") // does not work, since we do not use backticks`
    * `console.log(`Message: ${this.message}`) // works`
      - Requirement: message is a variable (i.e. class member variable)

### Closures in javascript / typescript: (*1)
+ A closure is an object that contains the function as well as its context with what it was created!
  - The returned object saves its creation context!
+ Example:
```
function makeFunc() {
  let name = "Jens";
  function displayName() {
    alert(name);
  }
  return displayName;
}

let myFunc: function = makeFunc();

myFunc(); // knows the name "Jens" even if name is out of scope now
```
