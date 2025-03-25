#include "struct_money.h"
#include <iostream>

void money::addMoney(const money& other) {
    unsigned int total_kop = hrn * 100 + kop +
                                  other.hrn * 100 + other.kop;
    hrn = total_kop / 100;
    kop = total_kop % 100;
}

void money::multyMoney(unsigned short int count) {
    unsigned int total_kop = (hrn * 100 + kop) * count;
    hrn = total_kop / 100;
    kop = total_kop % 100;
}

void money::aroundMoney() {
    if (kop % 10 < 5) {
        kop = (kop / 10) * 10;
    } else {
        kop = ((kop / 10) + 1) * 10;
        if (kop >= 100) {
            hrn++;
            kop = 0;
        }
    }
}

void money::printMoney() const {
    printf("%u грн %02hu коп", hrn, kop);
}