#include <iostream>
#include <vector>

int main()
{
	std::vector<int> nums{10, 40, 30, 60, 90, 70, 20, 50, 80, 100};
	Tree<int> tree{1};
	for (auto num : nums)
		tree.insert(num);
    tree.print();
    std::cout << '\n';

	std::vector<double> nums2{11.23, 41.1, 31.765, 61.76, 97.2, 77.2, 27.2, 57.2, 87.2, 17.20};
	Tree<double> tree2{1.};
	for (auto num : nums2)
		tree2.insert(num);
    tree2.print();
    std::cout << '\n';
    tree2.erase(11.23);
    tree2.print();

    return 0;
}