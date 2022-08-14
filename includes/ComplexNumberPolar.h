#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <fcntl.h>
#include <io.h>

#pragma once

class ComplexNumberPolar
{
	/* Declaracion de los atributos de un objeto de la clase */
	float _module;
	float _angle;

public:

	/* Invocamos losd iferentes constructores, definidos en el archivo cpp */
	ComplexNumberPolar(float module_, float angle);
	ComplexNumberPolar();

	/* Para funciones de una sola línea, hacerlo con inline dentro de la clase,
	 * porque es más rápido.
	 */
	inline float getRealPart() { return _module * cos(_angle * (float)M_PI / 180.0f); }
	inline float getImaginaryPart() { return _module * sin(_angle * (float)M_PI / 180.0f); }
	inline float getModule() { return _module; }
	inline float getAngleRadians() { return _angle * (float)M_PI / 180.0f; }
	inline float getAngleDegrees() { return _angle; }

	inline void setModule(float module_) { _module = module_; }
	inline void setAngle(float angle) { _angle = angle; }

	static void showComplexNumberBinaryForm(ComplexNumberPolar complexNumber)
	{
		float _real = complexNumber.getModule() * cos(complexNumber.getAngleRadians());
		float _imaginary = complexNumber.getModule() * sin(complexNumber.getAngleRadians());

		if (_real == 0 && _imaginary == 0) {
			std::cout << "0" << std::endl;
		}
		else if (_real == 0 && _imaginary != 0) {

			if (_imaginary > 0) {

				if (_imaginary == 1)
					std::cout << "i" << std::endl;
				else
					std::cout << _imaginary << "i" << std::endl;

			}
			else if (_imaginary < 0) {

				if (_imaginary == -1)
					std::cout << "-i" << std::endl;
				else
					std::cout << "-" << std::abs(_imaginary) << "i" << std::endl;

			}
		}
		else {

			std::cout << _real;

			if (_imaginary > 0) {

				if (_imaginary > 0.999 && _imaginary < 1.001)
					std::cout << "+i" << std::endl;
				else
					std::cout << "+" << _imaginary << "i" << std::endl;

			}
			else if (_imaginary < 0) {

				if (_imaginary > -1.001 && _imaginary < -0.999)
					std::cout << "-i" << std::endl;
				else
					std::cout << "-" << std::abs(_imaginary) << "i" << std::endl;

			}
			else {
				std::cout << std::endl;
			}
		}
	}
	void showComplexNumberBinaryForm();

	static void showComplexNumberAngleForm(ComplexNumberPolar complexNumber)
	{
		std::cout << complexNumber.getModule();
		_setmode(_fileno(stdout), _O_U16TEXT);
		std::wcout << L"\x221f";
		_setmode(_fileno(stdout), _O_TEXT);
		std::cout << complexNumber.getAngleDegrees();
		_setmode(_fileno(stdout), _O_U16TEXT);
		std::wcout << L"\x00b0" << std::endl;
		_setmode(_fileno(stdout), _O_TEXT);
	}
	void showComplexNumberAngleForm();

	static void showComplexNumberPolarForm(ComplexNumberPolar complexNumber) {

		std::cout << complexNumber.getModule() << "(cos(" << complexNumber.getAngleDegrees();
		_setmode(_fileno(stdout), _O_U16TEXT);
		std::wcout << L"\x00b0";
		_setmode(_fileno(stdout), _O_TEXT);
		std::cout << ") + isin(" << complexNumber.getAngleDegrees();
		_setmode(_fileno(stdout), _O_U16TEXT);
		std::wcout << L"\x00b0";
		_setmode(_fileno(stdout), _O_TEXT);
		std::cout << "))" << std::endl;
	}
	void showComplexNumberPolarForm();

	static ComplexNumberPolar complexConjugate(ComplexNumberPolar complexNumber)
	{
		float _real = complexNumber.getModule() * cos(complexNumber.getAngleRadians());
		float _imaginary = -1 * complexNumber.getModule() * sin(complexNumber.getAngleRadians());

		float angle = atan2(_imaginary, _real);

		ComplexNumberPolar complexNumber_ = ComplexNumberPolar(complexNumber.getModule(), angle * 180 / M_PI);

		return complexNumber_;
	}
	ComplexNumberPolar complexConjugate();
	void complexConjugate_();
	static void complexConjugatePtr(ComplexNumberPolar &complexNumber)
	{
		float _real = complexNumber.getModule() * cos(complexNumber.getAngleRadians());
		float _imaginary = -1 * complexNumber.getModule() * sin(complexNumber.getAngleRadians());

		complexNumber.setAngle(atan2(_imaginary, _real) * 180 / M_PI);
	}

	static ComplexNumberPolar sumComplexNumbers(ComplexNumberPolar complexNumber1, ComplexNumberPolar complexNumber2)
	{
		ComplexNumberPolar complexNumberSum;

		float real = complexNumber1.getRealPart() + complexNumber2.getRealPart();
		float imaginary = complexNumber1.getImaginaryPart() + complexNumber2.getImaginaryPart();

		complexNumberSum.setModule(sqrt(real * real + imaginary * imaginary));
		complexNumberSum.setAngle(atan2(imaginary, real) * 180 / M_PI);

		return complexNumberSum;
	}
	ComplexNumberPolar sumComplexNumber(ComplexNumberPolar complexNumber);
	void sumComplexNumbers_(ComplexNumberPolar complexNumber1, ComplexNumberPolar complexNumber2);

	static ComplexNumberPolar subtractComplexNumbers(ComplexNumberPolar minuend, ComplexNumberPolar subtrahend)
	{
		ComplexNumberPolar complexNumberSum;

		float real = minuend.getRealPart() - subtrahend.getRealPart();
		float imaginary = minuend.getImaginaryPart() - subtrahend.getImaginaryPart();

		complexNumberSum.setModule(sqrt(real * real + imaginary * imaginary));
		complexNumberSum.setAngle(atan2(imaginary, real) * 180 / M_PI);

		return complexNumberSum;
	}
	ComplexNumberPolar subtractComplexNumber(ComplexNumberPolar complexNumber);
	void subtractComplexNumbers_(ComplexNumberPolar minuend, ComplexNumberPolar subtrahend);

	static ComplexNumberPolar multiplyComplexNumbers(ComplexNumberPolar complexNumber1, ComplexNumberPolar complexNumber2)
	{
		ComplexNumberPolar complexNumberMult;

		complexNumberMult.setModule(complexNumber1.getModule() * complexNumber2.getModule());

		float angle = complexNumber1.getAngleDegrees() + complexNumber2.getAngleDegrees();

		if (angle > 180) {
			while (angle > 180) {
				angle = angle - 360;
			}
		}
		else if (angle < -180) {
			while (angle < -180) {
				angle = angle + 360;
			}
		}

		complexNumberMult.setAngle(angle);

		return complexNumberMult;
	}
	ComplexNumberPolar multiplyByComplexNumber(ComplexNumberPolar complexNumber);
	void multiplyComplexNumbers_(ComplexNumberPolar complexNumber1, ComplexNumberPolar complexNumber2);

	static ComplexNumberPolar divideComplexNumbers(ComplexNumberPolar numerator, ComplexNumberPolar denominator)
	{
		ComplexNumberPolar complexNumberMult;

		float angle = numerator.getAngleDegrees() - denominator.getAngleDegrees();

		if (angle > 180) {
			while (angle > 180) {
				angle = angle - 360;
			}
		}
		else if (angle < -180) {
			while (angle < -180) {
				angle = angle + 360;
			}
		}

		complexNumberMult.setModule(numerator.getModule() / denominator.getModule());
		complexNumberMult.setAngle(angle);

		return complexNumberMult;
	}
	ComplexNumberPolar divideByComplexNumber(ComplexNumberPolar complexNumber);
	void divideComplexNumbers_(ComplexNumberPolar numerator, ComplexNumberPolar denominator);

	static ComplexNumberPolar raiseComplexNumberToPower(ComplexNumberPolar complexNumber, int power)
	{
		if (power == 0) {
			ComplexNumberPolar complexNumberRaised = ComplexNumberPolar(1.0f, 0.0f);
			return complexNumberRaised;
		}

		ComplexNumberPolar complexNumberRaised = complexNumber;

		for (int i = 0; i < power - 1; i++)
		{
			complexNumberRaised = multiplyComplexNumbers(complexNumberRaised, complexNumber);
		}

		return complexNumberRaised;
	}
	ComplexNumberPolar raiseComplexNumberToPower(int power);
	void raiseComplexNumberToPower_(ComplexNumberPolar complexNumber, int power);
	void raiseComplexNumberToPower_(int power);
	static void raiseComplexNumberToPowerPtr(ComplexNumberPolar& complexNumber, int power)
	{
		if (power == 0)
		{
			complexNumber.setModule(1.0f);
			complexNumber.setAngle(0.0f);
		}
		else
		{
			ComplexNumberPolar complexNumberRaised = complexNumber;
			
			for (int i = 0; i < power - 1; i++)
			{
				complexNumber.multiplyComplexNumbers_(complexNumber, complexNumberRaised);
			}
		}
	}
};