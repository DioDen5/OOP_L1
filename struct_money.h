#ifndef STRUCT_MONEY_H
#define STRUCT_MONEY_H

struct money {
 unsigned int hrn;
 unsigned short int kop;

 void addMoney(const money& other);
 void multyMoney(unsigned short int count);
 void aroundMoney();
 void printMoney() const;
};

#endif