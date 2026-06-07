#include <iostream>
#include <cmath>
#include "bond_yield.h"

int main () {
	std::cout << "Please insert bond price:";
	float p{};
	std::cin >> p;
	std::cout << "Please insert par price:";
	float par{};
	std::cin >> par;
	std::cout << "Please insert coupon:";
	float c{};
	std::cin >> c;
	std::cout << "Please insert no. of years to maturity:";
	float n{};
	std::cin >> n;
	std::cout << "Please insert coupon frequency:";
	int m{};
	std::cin >> m;
	std::cout << '\n';
	
	int no_per = static_cast<int>(std::floor(n * m));
	float payment_dates[no_per];
	float yield_guess{0.05};
	float yield_adjust{0.0025};
	float err{0.000001};

	float calculated_price{calculate_bond_price(no_per, c, m, par, yield_guess)};
	while(std::abs(p - calculated_price) > err) {
		float price_diff = p - calculated_price;
		std::cout << "The current yield is: " << yield_guess << " and the current price difference is: " << price_diff << '\n';

		if(price_diff > 0) {
			yield_guess -= yield_adjust;
			calculated_price = calculate_bond_price(no_per, c, m, par, yield_guess);
			if(p - calculated_price < 0) {
				yield_adjust /= 2.0f;
			}
		}
		else {
			yield_guess += yield_adjust;
			calculated_price = calculate_bond_price(no_per, c, m, par, yield_guess);
			if(p - calculated_price > 0) {
				yield_adjust /= 2.0f;
			}
		}
	}

	std::cout << "The final yield found is: " << yield_guess << '\n';

	return 0;
}
