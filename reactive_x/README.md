# Introduction to ReactiveX
+ Based on the Tutorial [](https://www.youtube.com/watch?v=PhggNGsSQyg)

## Requirements
Tested under Windows 10 with:
+ node v16.15.1
+ yarn 1.22.19

## Setup of the basic node project with yarn
+ "yarn" is an alternative package manager for javascript, developed by facebook
+ Installation: [](https://linuxize.com/post/how-to-install-yarn-on-ubuntu-20-04/)

### Starting the project
+ Init the project with ```$ yarn init -y```
+ Install dependencies: ```yarn add typescript tsloader webpack webpack-dev-server rxjs```
+ Install development dependencies (which are not get deployed): ```yarn install webpack-cli --dev```
+ On every yarn project, we have a `package.json` within which we can define dependencies (which get resolved on purpose) and scripts. 
    - Scripts define what should be executed if we type ```$ yarn run <script-name>```
#### Further `yarn`
+ Removing package from the project: `$ yarn remove <package_name>`
+ Installing packages from the `package.json`: ```$ yarn install # from within the folder where the package.json is```

# Reactive X

## Observables and Streams
+ Observables: 
    - Concept of values/events that are emitted over time.
    - Observables facilitate in which order and how changes of values should be processed over time
    - The producer of an observable is the `subscribe` function, which is the parameter that is handed over while calling `Observable.create(function subscribe(): void {// producer code})`
    - Observables are basically asynchronous operations
    - Once an observable is completed or an error occures, it can ***not*** be reactivated
+ Observers:
    - Are instances that invoke their associated function (aka callback function) every time the observable emmitts a value/an event
    - One observable could have multiple observers and every one of them could do with the emmitted events whatever they wanta
    - Every observer has the methods 
        * `.next(arg: any)`: Normal event happens to the observable
        * `.error(arg:any)`: Invoked on error of the observable
        * `.complete(arg:any)`: Invoked if the observer is completed
+ Basic Idea: 
    - The higher order business logic is implemented in the observable definiton
    - The observable distributes its high level information to all observers
    - Every observer could handle the information from the observable differently (since all are created with individual `next`, `complete` and `error` functions)
    - An observable is like a Publisher-Subscriber system with a push principle from the publisher to the subscribers on code basis
    - It is possible to couple two or more subscribers together

### Hot vs Cold Observables
+ Cold Observables: 
    - The producer is called on every subscription
+ Hot Observables: 
    - If the producer is emmitting values outside of the observable
    - E.g. from events on the DOM or by receiving a promise
    - The subscription does not invoke a next execution immediatly, it waits until something happens and then executes the next function 

### Subjects
+ Subjects are a special type of observables
+ Subjects are able to receive messages from an observer and also are able to emit values to a stream/another observable
+ Subjects are more convenient then regular observables, since we can call the ``subj.next("Data");` method from the Subject instance after construction.
    - That means, the subject can emmit data whenever the next method is called on the subject object.
    - The data will be received by all subscribers to the subject
+ Subscribers to subjects are always in a hot observer manner!
    - That means: Only when the `next("data");` method is called on the Subject object, the subscriber / observer will invoke its next function 
#### Subtypes of Subjects
+ There are three subject types: 
##### Behaviour Subject:
+ Emit the last value upon a subscribers subscription
##### Replay Subject:
+ Dispatches a designated number of previous messages
+ We can also hand over a time horizon that should be replayed if there are not enough messages on the subject
    - Details: see code_replay_subject.ts

##### Async Subject: 
+ Returns only the last value on the subject and will only invoke the next function on its subscribers if the `Subject.complete()` method is called on the `AsyncSubject` object

### RxJs Operators
+ Operators are methods that can applied to subjects
    - They modify and then return a new subject instance after they are applied to the subject
+ We differenciate between
    - *Static Operators*: Used to create observables
    - *Instance Operators*: Methods on observable instances
        * Mostly used
+ Marbel-Diagrams: 
    - Shows the basic logic of one or more observables that form an output observable
    - Should help to understand the temporal lapse of the rxjs operator(s)
    - There is no defined scheme how to interpret a marbel diagram. Mostly you need to reason about the diagram and then read the documentation to the corresponding operator to get the full understanding of the operator
    - Reference: [This medium post](https://zach-gollwitzer.medium.com/how-to-read-an-rxjs-marble-diagram-f6e8dfa29781)
+ Choose your operators wisely: [Operator Decision Tree](https://rxjs-dev.firebaseapp.com/operator-decision-tree)
+ We can use observables, subjects and operators together. See `code_obs_subj_op_example.ts`

## Observable creation operators
+ Observables could be instanciated from different functions/methods, e.g. by the `from(json_obj)` function
    - The function uses the handed over javascript object and emmits it's values as the `.next(data)` date
    - See `code_operator_pluck_example.ts`

## Javascript
+ Functions can be defined either before ***or*** after they are invoked in the code.
    - The javascript interpreter looks through the file and loads all functions before a line of the script is executed
+ `var interval_id = setInterval(fnc, timer_in_ms);`:
    - Can be used to execute code in endless while loop
    - Stop it with `clearInterval(interval_id);`
+ `setTimeout(fnc: any, timeout: number)`:
    - The `fnc` gets invoked after the defined timeout
+ Arrow Functions:
    - Shorter syntax for defining functions but with some limitations
    - The `this` object could not be bound to the arrow function
    - Parameters are references to the calling scope. The do *not* reference an exclusively owned copy of the parameters ==> Arrow functions could not be used as parameters if we want to follow the functional programming paradigm
    - They should not be used to define class methods
+ `var` vs `let`
    + `var`: The scope for a variable that is declared with `var` is the complete enclosing scope
    + `let`: The scope for a variable that is declared with `let` is its own scope and its subordinate scopes. *Not* the enclosing scope