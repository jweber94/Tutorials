#!/usr/bin/node
var customer1 = {
    name: "Jens",
    money: 1000000,
    pay_in: function (sumval) {
        this.money = this.money + sumval;
    }
};
customer1.pay_in(10);
console.log(customer1.money);
