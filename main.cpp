#include <iostream>
#include <vector>
#include <array>


std::array<int, 3> find_sum(const std::vector<int>& in_arr, const int search_sum){

    std::array<int, 3> sum_indices{};

    int sum{in_arr[0] + in_arr[1] + in_arr[2]};

    if (sum == search_sum){
        return {0, 1, 2};
    }

    int l_bound{2};
    int u_bound{static_cast<int>(in_arr.size())-2};

    for (int iii{l_bound}; iii <= u_bound; ++iii){

        sum -= in_arr[iii-2];
        sum += in_arr[iii+1];

        if (sum == search_sum){
            return {iii-1, iii, iii+1};
        }
    }

    return {0, 0, 0};
}


void print_results(const std::array<int, 3>& sum_indices, const std::vector<int>& in_arr){

    if (sum_indices.front()!=sum_indices.back()){

        std::cout << "Sum found between indices " << sum_indices.front() << " and " << sum_indices.back() << ":\n";

        for (int index : sum_indices){
            std::cout << in_arr[index] << ' ';
        }
    }
    else
        std::cout << "Sum was not found in the given array.";

    std::cout << '\n';
}

/*
void find_sum(std::vector<int> in_arr, int search_sum){
    std::array<int, 3> sum_indices = 
}
*/

int main(){

    std::vector<int> in_arr{14, 12, 70, 15, 99, 65, 21, 90};
    int search_sum{97};

    print_results(find_sum(in_arr, search_sum), in_arr);

    return 0;
}