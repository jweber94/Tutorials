#!/usr/bin/node

// define custom decorator
function Logger(target: Function) {
	console.log(target);
}


function LoggerWithClosure(str: string) {
	return function(target: Function) {
		console.log("Logging: " + str);
	}
}

// define the class
@Logger
@LoggerWithClosure("Our Class")
class Greeter {
	message: string;

	constructor(message: string) {
		this.message = message;
	}

	sayHi() {
		console.log(`Hello! ${this.message}`);
	}
}

let greet1 = new Greeter("Hello World!");
greet1.sayHi();
