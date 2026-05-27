#include <algorithm> // for std::for_each
#include <functional> // for std::function, std::less, std::less_equal, std::greater, std::greater_equal
#include <iostream> // for std::cout

int main(){
    std::vector<std::function<bool(double, double)>> comparators = {
        std::less<double>(),
        std::less_equal<double>(),
        std::greater<double>(),
        std::greater_equal<double>()
    };

    double x = 10, y = 10;

    auto compare = [&x, &y](const std::function<bool(double, double)> &comparators){
        bool result = comparators(x, y);
        std::cout << (result? "TRUE" : "FALSE") << std::endl;
    };

    std::for_each(comparators.begin(), comparators.end(), compare);

    return 0;
}