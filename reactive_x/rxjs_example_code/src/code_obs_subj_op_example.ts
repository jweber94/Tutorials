import { Observable } from "rxjs"
import { Subject } from 'rxjs'
import { skipUntil } from 'rxjs/operators'

// create continuesly sending observable
var obs_1 = Observable.create(
    (x: any) => { // Whenever an observer subscribes to this observable, this function will be invoked
        var i = 1;
        setInterval(() => {x.next(i++)}
        , 1000); // executes every second
    }
);

// Create observable as a subject that sends after 5 seconds
var obs_2 = new Subject(); // subjects can produce data into an observable whenever they want/whenever they call .next(data_for_obs);
setTimeout(
    () => {
        obs_2.next("Start");
    }
    ,
    5000 // Is done after 5 seconds
);

// second observable that is created by the skipUntil rxjs operator
const obs_3 = obs_1
    .pipe(skipUntil(obs_2))
    .subscribe((x: any) => addItem(x));

// manipulate website
function addItem(val: any): void {
    var node = document.createElement("li"); // document is vanilla javascript (available without imports)
    var textnode = document.createTextNode(val);
    node.appendChild(textnode);
    document.getElementById("output").appendChild(node); // document.getElementById("output") references the ul tag of the index.html 
}