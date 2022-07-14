# Introduction to ReactiveX
+ Based on the Tutorial [](https://www.youtube.com/watch?v=PhggNGsSQyg)

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
+ Upcoming next

## Javascript
+ Functions can be defined either before ***or*** after they are invoked in the code.
    - The javascript interpreter looks through the file and loads all functions before a line of the script is executed
+ `var interval_id = setInterval(fnc, timer_in_ms);`:
    - Can be used to execute code in endless while loop
    - Stop it with `clearInterval(interval_id);`
+ `setTimeout(fnc: any, timeout: number)`:
    - The `fnc` gets invoked after the defined timeout