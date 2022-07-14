import { Subject } from "rxjs"

var my_subject = new Subject();

var obs_1 = my_subject.subscribe(
    (x: any) => {
        console.log("next - obs1");
        addItem("obs1 " + x);
    }, 
    (x: any) => {
        console.log("error - obs1");
        addItem(x);
    },
    () => {
        console.log("complete - obs1");
    }
);

setTimeout(() => {
    my_subject.next("Foo"); // This was NOT possible for a regular observable, since we need to define the execution function on construction

    var obs2 = my_subject.subscribe(
        function (x: any): void {
            console.log("next - obs2");
            addItem("obs2 " + x);
        },
        function(x: any): void {
            console.log("error - obs2");
            addItem("obs2 " + x);
        },
        function(): void {
            console.log("complete - obs2");
        }
    );

    my_subject.next("Second thing has been send");
    obs2.unsubscribe();
    my_subject.next("Third thing has been send");
}, 1000);

function addItem(val: any): void {
    var node = document.createElement("li"); // document is vanilla javascript (available without imports)
    var textnode = document.createTextNode(val);
    node.appendChild(textnode);
    document.getElementById("output").appendChild(node); // document.getElementById("output") references the ul tag of the index.html 
}