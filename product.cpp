#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

class Product {
public:
    std::string name;
    std::string category;
    double price;

    Product(std::string n, std::string c, double p) : name(n), category(c), price(p) {}
};

int main() {
    std::vector<Product> products = {
        {"Laptop", "Electronics", 1200.0},
        {"Smartphone", "Electronics", 800.0},
        {"Tablet", "Electronics", 500.0},
        {"Chair", "Furniture", 150.0},
        {"Desk", "Furniture", 300.0},
        {"Sofa", "Furniture", 700.0},
        {"T-Shirt", "Clothing", 30.0},
        {"Jeans", "Clothing", 50.0}
    };

    // Grouping products by category
    std::map<std::string, std::vector<Product>> category_map;
    for (const auto &product : products) {
        category_map[product.category].push_back(product);
    }

    // Finding the most expensive product in each category
    std::cout << "Most expensive product in each category:\n";
    for (const auto &[category, product_list] : category_map) {
        auto max_product = *std::max_element(product_list.begin(), product_list.end(), [](const Product &a, const Product &b) {
            return a.price < b.price;
        });
        std::cout << category << ": " << max_product.name << " - $" << max_product.price << "\n";
    }

    // Calculating the average price of all products
    double total_price = std::accumulate(products.begin(), products.end(), 0.0, [](double sum, const Product &p) {
        return sum + p.price;
    });
    double average_price = total_price / products.size();
    std::cout << "\nAverage price of all products: $" << average_price << "\n";
    
    return 0;
}