import { Observable, Observable as Rx } from "rxjs"

// global variables
let interval_id;

// Create the observable
var observable = Observable.create(
    function subscription_fcn(observer: any): void { // Whenever an observer is created from the observable, this function is invoked
        try {
            observer.next('Hello World!'); // The observer that is created from the observable invokes its .next() function with the parameter defined on the observable  
            observer.next('FooBar');
            interval_id = setInterval(() => {
                observer.next("next");
            }, 2000);
            // observer.complete();
            observer.next(); // not invoked since the .complete() method of the observer was invoked before
        } catch (err) {
            observer.error(err);
        }
    }
);

// Create the observers
var obs1 = observable.subscribe(
    (x: any): void => { // next function
        addItem(x);
    },
    (x: any): void => { // error function
        addItem("Error function invoked");
    },
    (x: any): void => { // complete function
        addItem("Completed function invoked");
    }
);

var obs2 = observable.subscribe(
    (x: any): void => { // next function
        addItem(x + " - obs2");
    },
    (x: any): void => { // error function
        addItem("Error function invoked - obs2");
    },
    (x: any): void => { // complete function
        addItem("Completed function invoked - obs2");
    }
);

obs1.add(obs2); // couple the observer 2 to the observer 1 --> if obs1 gets unsubscribed, obs2 gets unsubscribed as well

setTimeout(() => {
    obs1.unsubscribe();
}, 10000);

function addItem(val: any): void {
    var node = document.createElement("li"); // document is vanilla javascript (available without imports)
    var textnode = document.createTextNode(val);
    node.appendChild(textnode);
    document.getElementById("output").appendChild(node); // document.getElementById("output") references the ul tag of the index.html 
}