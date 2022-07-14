import { fromEvent, Observable, Observable as Rx } from "rxjs"

var hot_observable = fromEvent(document, 'click');
    // fromEvent is a function of rxjs and triggers the subscribers from the defined event
    // can be fromEvent(promise);

setTimeout(() => {
    var subscription = hot_observable.subscribe(
        (x: any) => {
            console.log("next callback");
            addItem(x);
        },
        (x: any) => {
            console.log("error callback");
        }
    );
}, 1000);

function addItem(val: any): void {
    var node = document.createElement("li"); // document is vanilla javascript (available without imports)
    var textnode = document.createTextNode(val);
    node.appendChild(textnode);
    document.getElementById("output").appendChild(node); // document.getElementById("output") references the ul tag of the index.html 
}