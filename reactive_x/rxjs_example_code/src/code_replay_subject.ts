import { ReplaySubject } from "rxjs"

var rpl_subj = new ReplaySubject(2, 5000);

let obs1 = rpl_subj.subscribe(
    (x: any): void => {
        console.log("obs1 - next");
        addItem("obs1 - " + x);   
    }
);

let counter = 1;
let interval_element = setInterval(() => rpl_subj.next(counter++), 100);
    // This is an infinite loop that sends the counter to the subject

setTimeout(() => {
    let obs2 = rpl_subj.subscribe((x: any) => {
        console.log("obs2 - next");
        addItem("obs2 - " + x);
    }); 
}, 1000);

function addItem(val: any): void {
    var node = document.createElement("li"); // document is vanilla javascript (available without imports)
    var textnode = document.createTextNode(val);
    node.appendChild(textnode);
    document.getElementById("output").appendChild(node); // document.getElementById("output") references the ul tag of the index.html 
}