#include "struct_money.h"
#include <iostream>

void addMoney(money& total, money& product) {
    total.hrn += product.hrn;
    total.kop += product.kop;

    total.hrn += total.kop / 100;
    total.kop = total.kop % 100;
}

void multyMoney(money& product, unsigned short int count) {
    product.hrn *= count;
    product.kop *= count;

    product.hrn += product.kop / 100;
    product.kop = product.kop % 100;
}

void aroundMoney(money& total) {
    if (total.kop % 10 < 5) {
        total.kop = (total.kop / 10) * 10;
    } else {
        total.kop = ((total.kop / 10) + 1) * 10;
        if (total.kop >= 100) {
            total.hrn++;
            total.kop = 0;
        }
    }
}

void printMoney(money& total) {
    std::cout << total.hrn << " грн " << total.kop << " коп" << std::endl;
}

