#!/usr/bin/node

interface ICustomer {
	name: string;
	money: number;
	pay_in: Function;
}

let customer1: ICustomer = {
	name: "Jens",
	money: 1000000,
	pay_in: function (sumval: number): void {
		this.money = this.money + sumval;
	},
}

customer1.pay_in(10);
console.log(customer1.money);

