#include "../includes/ComplexNumber.h"
#include "../includes/ComplexNumberPolar.h"
#include <iostream>
#include <vector>


int main()
{
	/* Addition of two complex numbers declared in binary form */

	ComplexNumber numComplejo = ComplexNumber(-2.0f, -3.0f);
	ComplexNumber numComplejo2 = ComplexNumber(-1.0f, 2.0f);
	ComplexNumber numComplejoSuma = ComplexNumber::sumComplexNumbers(numComplejo, numComplejo2);

	std::cout << "Complex number: ";
	numComplejoSuma.showComplexNumberBinaryForm();
	std::cout << "Complex number: ";
	numComplejoSuma.showComplexNumberAngleForm();
	std::cout << "Complex number: ";
	numComplejoSuma.showComplexNumberPolarForm();
	std::cout << std::endl;


	/* Addition of two complex numbers declared in polar form */

	ComplexNumberPolar numComplejoPolar = ComplexNumberPolar(numComplejo.getModule(), numComplejo.getAngleDegrees());
	ComplexNumberPolar numComplejoPolar2 = ComplexNumberPolar(numComplejo2.getModule(), numComplejo2.getAngleDegrees());
	ComplexNumberPolar numComplejoSumaPolar = ComplexNumberPolar::sumComplexNumbers(numComplejoPolar, numComplejoPolar2);

	std::cout << "Complex number: ";
	ComplexNumberPolar::showComplexNumberBinaryForm(numComplejoSumaPolar);
	std::cout << "Complex number: ";
	numComplejoSumaPolar.showComplexNumberAngleForm();
	std::cout << "Complex number: ";
	numComplejoSumaPolar.showComplexNumberPolarForm();

	return 0;
}