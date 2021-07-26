#include <iostream>
#include <vector>
#include <array>


std::array<int, 3> find_sum(std::vector<int> in_arr, int search_sum){

    std::array<int, 3> sum_indices{};

    int sum{in_arr[0] + in_arr[1] + in_arr[2]};

    int l_bound{0};
    int u_bound{in_arr.size()-2};

    for (int iii{l_bound}; iii < u_bound; ++iii){

        if (sum == search_sum){
            return {iii, iii+1, iii+2};
        }

        sum -= in_arr[iii-1];
        sum += in_arr[iii+2];
    }

    if (sum == search_sum){
        return {u_bound, u_bound+1, u_bound+2};
    }
    else{
        return {0, 0, 0};
    }
}


void print_results(std::array<int, 3> sum_indices, std::vector<int> in_arr){

    std::cout << "Sum found between indices " << sum_indices[0] << " and " << sum_indices[2] << '\n';

    for (int index : sum_indices){
        std::cout << in_arr[index] << ' ';
    }

    std::cout << '\n';
}


int main(){

    std::vector<int> in_arr{14, 12, 70, 15, 99, 65, 21, 90};
    int search_sum{97};

    print_results(find_sum(in_arr, search_sum), in_arr);

    return 0;
}