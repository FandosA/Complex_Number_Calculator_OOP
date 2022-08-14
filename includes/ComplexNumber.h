#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <fcntl.h>
#include <io.h>

#pragma once

class ComplexNumber
{
	/* Declaracion de los atributos de un objeto de la clase */
	float _real;
	float _imaginary;

public:

	/* Invocamos losd iferentes constructores, definidos en el archivo cpp */
	ComplexNumber(float real, float imaginary);
	ComplexNumber();

	/* Para funciones de una sola línea, hacerlo con inline dentro de la clase,
	 * porque es más rápido.
	 */
	inline float getRealPart() { return _real; }
	inline float getImaginaryPart() { return _imaginary; }
	inline float getModule() { return sqrt(_real * _real + _imaginary * _imaginary); }
	inline float getAngleRadians() { return atan2(_imaginary, _real); }
	inline float getAngleDegrees() { return 180.0f * atan2(_imaginary, _real) / (float)M_PI; }

	inline void setRealPart(float real) { _real = real; }
	inline void setImaginaryPart(float imaginary) { _imaginary = imaginary; }

	/* Declaración de las funciones del archivo cpp */
	static void showComplexNumberBinaryForm(ComplexNumber complexNumber)
	{
		if (complexNumber.getRealPart() == 0 && complexNumber.getImaginaryPart() == 0) {
			std::cout << "0" << std::endl;
		}
		else if (complexNumber.getRealPart() == 0 && complexNumber.getImaginaryPart() != 0) {

			if (complexNumber.getImaginaryPart() > 0) {

				if (complexNumber.getImaginaryPart() == 1)
					std::cout << "i" << std::endl;
				else
					std::cout << complexNumber.getImaginaryPart() << "i" << std::endl;

			}
			else if (complexNumber.getImaginaryPart() < 0) {

				if (complexNumber.getImaginaryPart() == -1)
					std::cout << "-i" << std::endl;
				else
					std::cout << "-" << std::abs(complexNumber.getImaginaryPart()) << "i" << std::endl;

			}
		}
		else {

			std::cout << complexNumber.getRealPart();

			if (complexNumber.getImaginaryPart() > 0) {

				if (complexNumber.getImaginaryPart() == 1)
					std::cout << "+i" << std::endl;
				else
					std::cout << "+" << complexNumber.getImaginaryPart() << "i" << std::endl;

			}
			else if (complexNumber.getImaginaryPart() < 0) {

				if (complexNumber.getImaginaryPart() == -1)
					std::cout << "-i" << std::endl;
				else
					std::cout << "-" << std::abs(complexNumber.getImaginaryPart()) << "i" << std::endl;

			}
			else {
				std::cout << std::endl;
			}
		}
	}
	void showComplexNumberBinaryForm();

	static void showComplexNumberAngleForm(ComplexNumber complexNumber) {

		float module_ = sqrt(complexNumber.getRealPart() * complexNumber.getRealPart() +
			complexNumber.getImaginaryPart() * complexNumber.getImaginaryPart());
		float angle = 0.0f;

		if (complexNumber.getRealPart() != 0 || complexNumber.getImaginaryPart() != 0) {
			angle = atan2(complexNumber.getImaginaryPart(), complexNumber.getRealPart());
		}

		std::cout << module_;
		_setmode(_fileno(stdout), _O_U16TEXT);
		std::wcout << L"\x221f";
		_setmode(_fileno(stdout), _O_TEXT);
		std::cout << angle * 180 / M_PI;
		_setmode(_fileno(stdout), _O_U16TEXT);
		std::wcout << L"\x00b0" << std::endl;
		_setmode(_fileno(stdout), _O_TEXT);
	}
	void showComplexNumberAngleForm();

	static void showComplexNumberPolarForm(ComplexNumber complexNumber) {

		float module_ = sqrt(complexNumber.getRealPart() * complexNumber.getRealPart() +
			complexNumber.getImaginaryPart() * complexNumber.getImaginaryPart());
		float angle = atan2(complexNumber.getImaginaryPart(), complexNumber.getRealPart());

		std::cout << module_ << "(cos(" << angle * 180 / M_PI;
		_setmode(_fileno(stdout), _O_U16TEXT);
		std::wcout << L"\x00b0";
		_setmode(_fileno(stdout), _O_TEXT);
		std::cout << ") + isin(" << angle * 180 / M_PI;
		_setmode(_fileno(stdout), _O_U16TEXT);
		std::wcout << L"\x00b0";
		_setmode(_fileno(stdout), _O_TEXT);
		std::cout << "))" << std::endl;
	}
	void showComplexNumberPolarForm();

	static ComplexNumber complexConjugate(ComplexNumber complexNumber)
	{
		float imaginary = -1 * complexNumber.getImaginaryPart();

		ComplexNumber complexNumber_ = ComplexNumber(complexNumber.getRealPart(), imaginary);

		return complexNumber_;
	}
	ComplexNumber complexConjugate();
	void complexConjugate_();
	static void complexConjugatePtr(ComplexNumber &complexNumber)
	{
		complexNumber.setImaginaryPart(-1 * complexNumber.getImaginaryPart());
	}

	static ComplexNumber sumComplexNumbers(ComplexNumber complexNumber1, ComplexNumber complexNumber2)
	{
		ComplexNumber complexNumberSum;

		complexNumberSum.setRealPart(complexNumber1.getRealPart() + complexNumber2.getRealPart());
		complexNumberSum.setImaginaryPart(complexNumber1.getImaginaryPart() + complexNumber2.getImaginaryPart());

		return complexNumberSum;
	}
	ComplexNumber sumComplexNumber(ComplexNumber complexNumber);
	void sumComplexNumbers_(ComplexNumber complexNumber1, ComplexNumber complexNumber2);

	static ComplexNumber subtractComplexNumbers(ComplexNumber minuend, ComplexNumber subtrahend)
	{
		ComplexNumber complexNumberSub;

		complexNumberSub.setRealPart(minuend.getRealPart() - subtrahend.getRealPart());
		complexNumberSub.setImaginaryPart(minuend.getImaginaryPart() - subtrahend.getImaginaryPart());

		return complexNumberSub;
	}
	ComplexNumber subtractComplexNumber(ComplexNumber complexNumber);
	void subtractComplexNumbers_(ComplexNumber complexNumber1, ComplexNumber complexNumber2);

	static ComplexNumber multiplyComplexNumbers(ComplexNumber complexNumber1, ComplexNumber complexNumber2)
	{
		ComplexNumber complexNumberMult;

		complexNumberMult.setRealPart(complexNumber1.getRealPart() * complexNumber2.getRealPart() -
									  complexNumber1.getImaginaryPart() * complexNumber2.getImaginaryPart());
		complexNumberMult.setImaginaryPart(complexNumber1.getRealPart() * complexNumber2.getImaginaryPart() +
										   complexNumber1.getImaginaryPart() * complexNumber2.getRealPart());

		return complexNumberMult;
	}
	ComplexNumber multiplyByComplexNumber(ComplexNumber complexNumber);
	void multiplyComplexNumbers_(ComplexNumber complexNumber1, ComplexNumber complexNumber2);

	static ComplexNumber divideComplexNumbers(ComplexNumber numerator, ComplexNumber denominator)
	{
		ComplexNumber complexNumberConjugate = denominator;
		complexNumberConjugate.complexConjugate_();

		float denominator_ = denominator.getRealPart() * denominator.getRealPart() +
							complexNumberConjugate.getImaginaryPart() * complexNumberConjugate.getImaginaryPart();
		ComplexNumber complexNumberDivision;

		complexNumberDivision.setRealPart((numerator.getRealPart() * complexNumberConjugate.getRealPart() -
										   numerator.getImaginaryPart() * complexNumberConjugate.getImaginaryPart()) / denominator_);

		complexNumberDivision.setImaginaryPart((numerator.getRealPart() * complexNumberConjugate.getImaginaryPart() +
												numerator.getImaginaryPart() * complexNumberConjugate.getRealPart()) / denominator_);

		return complexNumberDivision;
	}
	ComplexNumber divideByComplexNumber(ComplexNumber complexNumber);
	void divideComplexNumbers_(ComplexNumber complexNumber1, ComplexNumber complexNumber2);

	static ComplexNumber raiseComplexNumberToPower(ComplexNumber complexNumber, int power)
	{
		if (power == 0) {
			ComplexNumber complexNumberRaised = ComplexNumber(1.0f, 0.0f);
			return complexNumberRaised;
		}

		ComplexNumber complexNumberRaised = complexNumber;

		for (int i = 0; i < power - 1; i++)
		{
			complexNumberRaised = multiplyComplexNumbers(complexNumberRaised, complexNumber);
		}

		return complexNumberRaised;
	}
	ComplexNumber raiseComplexNumberToPower(int power);
	void raiseComplexNumberToPower_(ComplexNumber complexNumber, int power);
	void raiseComplexNumberToPower_(int power);
	static void raiseComplexNumberToPowerPtr(ComplexNumber &complexNumber, int power)
	{
		if (power == 0) {
			complexNumber.setRealPart(1.0f);
			complexNumber.setImaginaryPart(0.0f);
		}

		ComplexNumber complexNumberRaised = complexNumber;

		for (int i = 0; i < power - 1; i++)
		{
			complexNumber = multiplyComplexNumbers(complexNumberRaised, complexNumber);
		}
	}
};