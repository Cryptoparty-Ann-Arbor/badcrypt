// display vector example

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>

void display_vector(const std::vector<std::string> &v)
{
    std::copy(v.begin(), v.end(),
        std::ostream_iterator<std::string>(std::cout, " "));
}