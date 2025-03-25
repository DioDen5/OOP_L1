#ifndef STRUCT_MONEY_H
#define STRUCT_MONEY_H

struct money {
 unsigned int hrn;
 unsigned short int kop;
};
void addMoney(money& total, money& product);
void multyMoney(money& product, unsigned short int count);
void aroundMoney(money& total);
void printMoney(money& total);

#endif

