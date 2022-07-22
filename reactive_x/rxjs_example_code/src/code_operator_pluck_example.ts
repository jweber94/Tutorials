import { Observable } from "rxjs";
import { from } from "rxjs";
import { pluck } from 'rxjs/operators';
import { map } from 'rxjs/operators'


from([
        {first_name: 'Jens', last_name: 'Weber', age: 27},
        {first_name: 'Selina', last_name: 'Guth', age: 27},
        {first_name: 'Leni', last_name: 'Weber', age: 15}
    ])
    .pipe(pluck('first_name'))
    .pipe(map((x: any) => x.toUpperCase()))
    .subscribe((x: any): void => addItem(x));

// manipulate website
function addItem(val: any): void {
    var node = document.createElement("li"); // document is vanilla javascript (available without imports)
    var textnode = document.createTextNode(val);
    node.appendChild(textnode);
    document.getElementById("output").appendChild(node); // document.getElementById("output") references the ul tag of the index.html 
}
