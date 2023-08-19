#include <iostream>
#include <vector>
#include <algorithm>

unsigned long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    unsigned long long max_product = 0;
    int n = numbers.size();

    // for (int first = 0; first < n; ++first) {
    //     for (int second = first + 1; second < n; ++second) {
    //         max_product = std::max(max_product,
    //             numbers[first] * numbers[second]);
    //     }
    // }

    unsigned long long largest_num = 0;
    unsigned long long second_largest_num = 0;
    unsigned long long largest_flag = 0;

    for (int i = 0; i < n; i++)
    {
        if(numbers[i] > largest_num)
        {
            largest_num = numbers[i];
            largest_flag = i;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(numbers[i] > second_largest_num)
        {
            if(numbers[i] == largest_num && i != largest_flag)
            {
            second_largest_num = numbers[i];
            }
            else if(numbers[i] == largest_num && i == largest_flag){
                
            }
            else{
                second_largest_num = numbers[i];
            }
        }
    }

    max_product = largest_num * second_largest_num;

    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
