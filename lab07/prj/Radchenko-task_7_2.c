#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

void process_array(const std::vector<double>& arr) {
    if (arr.size() != 30) {
        std::cerr << "Масив має містити рівно 30 елементів." << std::endl;
        return;
    }

    // Знаходження найбільшого і найменшого елементів
    auto minmax = std::minmax_element(arr.begin(), arr.end());
    double min_element = *minmax.first;
    double max_element = *minmax.second;

    // Обчислення середнього арифметичного всіх додатніх елементів
    std::vector<double> positive_elements;
    for (double num : arr) {
        if (num > 0) {
            positive_elements.push_back(num);
        }
    }
    double average_positive = 0.0;
    if (!positive_elements.empty()) {
        average_positive = std::accumulate(positive_elements.begin(), positive_elements.end(), 0.0) / positive_elements.size();
    }

    // Заміна перших 15 елементів на останні 15
    std::vector<double> modified_arr = arr;
    std::swap_ranges(modified_arr.begin(), modified_arr.begin() + 15, modified_arr.end() - 15);

    // Вивід результатів
    std::cout << "Найменший елемент масиву: " << min_element << std::endl;
    std::cout << "Найбільший елемент масиву: " << max_element << std::endl;
    std::cout << "Середнє арифметичне додатніх елементів: " << average_positive << std::endl;

    std::cout << "Модифікований масив: ";
    for (double num : modified_arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
int main() {
    std::vector<double> arr(30);
    std::cout << "Введіть 30 дійсних чисел: ";
    for (int i = 0; i < 30; ++i) {
        std::cin >> arr[i];
    }

    process_array(arr);

    return 0;
}
