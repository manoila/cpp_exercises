#include <cmath>
#include "bond_yield.h"

float calculate_bond_price(int no_per, float c, int m, float par, float yield_guess) {
	float calculated_price {0};
	for(int i = 0; i < no_per; i++) {
		if(i == no_per - 1) {
			calculated_price += (c / m + par) * std::exp(- (i + 1) * 1.0f/m * yield_guess);
		}
		else {
			calculated_price += (c / m) * std::exp(- (i + 1) * 1.0f/m * yield_guess);
		}
	}

	return calculated_price;
}

