#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

void process_array(const std::vector<double>& arr) {
    if (arr.size() != 30) {
        std::cerr << "����� �� ������ ���� 30 ��������." << std::endl;
        return;
    }

    // ����������� ���������� � ���������� ��������
    auto minmax = std::minmax_element(arr.begin(), arr.end());
    double min_element = *minmax.first;
    double max_element = *minmax.second;

    // ���������� ���������� ������������� ��� ������� ��������
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

    // ����� ������ 15 �������� �� ������ 15
    std::vector<double> modified_arr = arr;
    std::swap_ranges(modified_arr.begin(), modified_arr.begin() + 15, modified_arr.end() - 15);

    // ���� ����������
    std::cout << "��������� ������� ������: " << min_element << std::endl;
    std::cout << "��������� ������� ������: " << max_element << std::endl;
    std::cout << "������ ����������� ������� ��������: " << average_positive << std::endl;

    std::cout << "������������� �����: ";
    for (double num : modified_arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
int main() {
    std::vector<double> arr(30);
    std::cout << "������ 30 ������ �����: ";
    for (int i = 0; i < 30; ++i) {
        std::cin >> arr[i];
    }

    process_array(arr);

    return 0;
}
