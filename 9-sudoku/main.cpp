#include <iostream>
#include <vector>
#include <algorithm>


int helper(std::vector<int>& answer, int sum, int n, int start, const std::vector<int>& extra) 
{
    if (n == 0 && sum == 0) 
    {
        for (int num : answer) 
        {
            std::cout << num << " ";
        }
        std::cout << "\n";
        return 0;
    }

    if (n <= 0 || sum <= 0 || start > 9) {
        return 0;
    }

    if (find(extra.begin(), extra.end(), start) == extra.end()) 
    {
        answer.push_back(start);
        helper(answer, sum - start, n - 1, start + 1, extra);
        answer.pop_back();
    }

    helper(answer, sum, n, start + 1, extra);
    return 0;
}

int main() 
{
    int n, s;
    std::cout << "n: ";
    std::cin >> n;
    std::cout << "S: ";
    std::cin >> s;

    if (n < 1 || n > 9 || s < 1 || s > 45) 
    {
        std::cout << "error\n";
        return 1;
    }

    std::vector<int> extra;
    std::cout << "Exclude: ";
    int num;
    while (std::cin >> num) 
    {
        if (num == 0) 
        {
            break;
        }
        extra.push_back(num);
    }

    std::vector<int> answer;
    helper(answer, s, n, 1, extra);

    return 0;
}