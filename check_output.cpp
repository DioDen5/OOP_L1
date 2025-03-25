#include "check_output.h"

void printCal() {
    std::ifstream file("products.txt");
    if (!file.is_open()) {
        std::cerr << "Помилка відкриття файлу" << std::endl;
        return;
    }

    money total {0, 0};
    std::string line;

    while (std::getline(file, line)) {

        std::regex price_pattern(R"(.*?(\d+)\s*грн\s*(\d+)\s*коп,\s*(\d+)\s*шт)");
        std::regex simple_pattern(R"((\d+)\s+(\d+)\s+(\d+))");
        std::smatch matches;

        money product {0, 0};
        unsigned short int quantity = 1;

        if (std::regex_search(line, matches, price_pattern)) {
            product.hrn = std::stoi(matches[1]);
            product.kop = std::stoi(matches[2]);
            quantity = std::stoi(matches[3]);
        }
        else if (std::regex_search(line, matches, simple_pattern)) {
            product.hrn = std::stoi(matches[1]);
            product.kop = std::stoi(matches[2]);
            quantity = std::stoi(matches[3]);
        }
        else {
            std::cerr << "Не вдалося розпарсити рядок: " << line << std::endl;
            continue;
        }

        multyMoney(product, quantity);
        addMoney(total, product);
    }
    file.close();


    std::cout << "\nЗагальна сума: ";
    printMoney(total);
    std::cout << std::endl;

    aroundMoney(total);
    std::cout << "Сума після заокруглення: ";
    printMoney(total);
    std::cout << std::endl;
}

