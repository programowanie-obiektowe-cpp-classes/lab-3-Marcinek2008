#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
	if (towar == 0)
		return 0;

	Stocznia stocznia{};
	unsigned int liczbaZaglowcow=0;

	while (Stocznia::getTotalCap() < towar) {
		Statek* statek = stocznia();
		statek->transportuj();

		if (dynamic_cast< Zaglowiec* >(statek))
			++liczbaZaglowcow;

		delete statek;
	}

	return liczbaZaglowcow;
}
