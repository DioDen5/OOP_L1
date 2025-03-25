#include "check_output.h"
#include "struct_money.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <regex>

void printCal() {
    std::ifstream file("products.txt");
    if (!file.is_open()) {
        std::cerr << "Помилка відкриття файлу" << std::endl;
        return;
    }

    std::vector<std::pair<money, unsigned short int>> items;
    std::string line;
    bool is_zero_input = true;

    while (std::getline(file, line)) {
        if (line.empty() || line == "0 0 0") {
            continue;
        }

        std::regex price_pattern(R"(.*?(\d+)\s*грн\s*(\d+)\s*коп,\s*(\d+)\s*шт)");
        std::regex simple_pattern(R"((\d+)\s+(\d+)\s+(\d+))");
        std::smatch matches;

        unsigned int hrn;
        unsigned short int kop, quantity;

        if (std::regex_search(line, matches, price_pattern)) {
            is_zero_input = false;
            hrn = std::stoi(matches[1]);
            kop = std::stoi(matches[2]);
            quantity = std::stoi(matches[3]);
        }
        else if (std::regex_search(line, matches, simple_pattern)) {
            is_zero_input = false;
            hrn = std::stoi(matches[1]);
            kop = std::stoi(matches[2]);
            quantity = std::stoi(matches[3]);
        }
        else {
            std::cerr << "Не вдалося розпарсити рядок: " << line << std::endl;
            continue;
        }

        money item;
        item.hrn = hrn;
        item.kop = kop;
        items.push_back({item, quantity});
    }
    file.close();

    if (is_zero_input) {
        money zero = {0, 0};
        std::cout << "Загальна сума: ";
        zero.printMoney();
        std::cout << std::endl;
        return;
    }

    if (items.empty()) {
        std::cerr << "Жодного товару не було зчитано!" << std::endl;
        return;
    }

    std::cout << "Товари у чеку:" << std::endl;
    for (const auto& item : items) {
        item.first.printMoney();
        std::cout << ", " << item.second << " шт" << std::endl;
    }

    money total_sum = {0, 0};
    for (const auto& item : items) {
        money temp = item.first;
        temp.multyMoney(item.second);
        total_sum.addMoney(temp);
    }

    std::cout << "\nЗагальна сума: ";
    total_sum.printMoney();
    std::cout << std::endl;

    total_sum.aroundMoney();
    std::cout << "Сума після заокруглення: ";
    total_sum.printMoney();
    std::cout << std::endl;
}