import { AsyncSubject, Subject } from "rxjs"

var my_async_subject = new AsyncSubject();

var obs_1 = my_async_subject.subscribe(function (data: any): void {
        console.log("obs_1: next is called");
        addItem("obs_1: next, data = " + data);
    },
    (data: any): void => {
        console.log("obs_1: error is called");
        addItem("obs_1: error, data = " + data);
    }, 
    (): void => {
        console.log("obs_1: complete is called");
        addItem("obs_1 complete");
    }
);

let i = 1;
let interval_counter = setInterval(() => {my_async_subject.next(i++)}, 200);

setTimeout(
    (): void => {
        var obs_2 = my_async_subject.subscribe(
            data => addItem("obs_2: " + data)
        )

        my_async_subject.complete();
    },
    500
);

function addItem(val: any): void {
    var node = document.createElement("li"); // document is vanilla javascript (available without imports)
    var textnode = document.createTextNode(val);
    node.appendChild(textnode);
    document.getElementById("output").appendChild(node); // document.getElementById("output") references the ul tag of the index.html 
}