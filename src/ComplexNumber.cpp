#include "../includes/ComplexNumber.h"


/* Constructors definition */
ComplexNumber::ComplexNumber(float real, float imaginary) :
	_real(real),
	_imaginary(imaginary)
{
	_real = real;
	_imaginary = imaginary;
}

ComplexNumber::ComplexNumber() :
	_real(),
	_imaginary()
{
	_real = 0.0f;
	_imaginary = 0.0f;
}


/* Functions definition */
void ComplexNumber::showComplexNumberBinaryForm()
{
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

			if (_imaginary == 1)
				std::cout << "+i" << std::endl;
			else
				std::cout << "+" << _imaginary << "i" << std::endl;

		}
		else if (_imaginary < 0) {

			if (_imaginary == -1)
				std::cout << "-i" << std::endl;
			else
				std::cout << "-" << std::abs(_imaginary) << "i" << std::endl;

		}
		else {
			std::cout << std::endl;
		}
	}
}

void ComplexNumber::showComplexNumberAngleForm() {

	float module_ = sqrt(_real * _real + _imaginary * _imaginary);
	float angle = 0.0f;

	if (_real != 0 || _imaginary != 0) {
		angle = atan2(_imaginary, _real);
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

void ComplexNumber::showComplexNumberPolarForm() {

	float module_ = sqrt(_real * _real + _imaginary * _imaginary);
	float angle = atan2(_imaginary, _real);

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

ComplexNumber ComplexNumber::complexConjugate()
{
	float imaginary = -1 * _imaginary;

	ComplexNumber complexNumber = ComplexNumber(_real, imaginary);

	return complexNumber;
}
void ComplexNumber::complexConjugate_()
{
	_imaginary = -1.0f * _imaginary;
}

ComplexNumber ComplexNumber::sumComplexNumber(ComplexNumber complexNumber)
{
	ComplexNumber complexNumberSum;

	complexNumberSum.setRealPart(complexNumber.getRealPart() + _real);
	complexNumberSum.setImaginaryPart(complexNumber.getImaginaryPart() + _imaginary);

	return complexNumberSum;
}
void ComplexNumber::sumComplexNumbers_(ComplexNumber complexNumber1, ComplexNumber complexNumber2)
{
	_real = complexNumber1.getRealPart() + complexNumber2.getRealPart();
	_imaginary = complexNumber1.getImaginaryPart() + complexNumber2.getImaginaryPart();
}

ComplexNumber ComplexNumber::subtractComplexNumber(ComplexNumber complexNumber)
{
	ComplexNumber complexNumberSub;

	complexNumberSub.setRealPart(_real - complexNumber.getRealPart());
	complexNumberSub.setImaginaryPart(_imaginary - complexNumber.getImaginaryPart());

	return complexNumberSub;
}
void ComplexNumber::subtractComplexNumbers_(ComplexNumber minuend, ComplexNumber subtrahend)
{
	_real = minuend.getRealPart() - subtrahend.getRealPart();
	_imaginary = minuend.getImaginaryPart() - subtrahend.getImaginaryPart();
}

ComplexNumber ComplexNumber::multiplyByComplexNumber(ComplexNumber complexNumber)
{
	ComplexNumber complexNumberMult;

	complexNumberMult.setRealPart(_real * complexNumber.getRealPart() -
		_imaginary * complexNumber.getImaginaryPart());
	complexNumberMult.setImaginaryPart(_real * complexNumber.getImaginaryPart() +
		_imaginary * complexNumber.getRealPart());

	return complexNumberMult;
}
void ComplexNumber::multiplyComplexNumbers_(ComplexNumber complexNumber1, ComplexNumber complexNumber2)
{
	_real = complexNumber1.getRealPart() * complexNumber2.getRealPart() - complexNumber1.getImaginaryPart() * complexNumber2.getImaginaryPart();
	_imaginary = complexNumber1.getRealPart() * complexNumber2.getImaginaryPart() + complexNumber1.getImaginaryPart() * complexNumber2.getRealPart();
}

ComplexNumber ComplexNumber::divideByComplexNumber(ComplexNumber complexNumber)
{
	ComplexNumber complexNumberConjugate = complexNumber;
	complexNumberConjugate.complexConjugate_();

	float denominator_ = complexNumber.getRealPart() * complexNumber.getRealPart() +
		complexNumberConjugate.getImaginaryPart() * complexNumberConjugate.getImaginaryPart();

	ComplexNumber complexNumberDivision;

	complexNumberDivision.setRealPart((_real * complexNumberConjugate.getRealPart() -
		_imaginary * complexNumberConjugate.getImaginaryPart()) / denominator_);

	complexNumberDivision.setImaginaryPart((_real * complexNumberConjugate.getImaginaryPart() +
		_imaginary * complexNumberConjugate.getRealPart()) / denominator_);

	return complexNumberDivision;
}
void ComplexNumber::divideComplexNumbers_(ComplexNumber numerator, ComplexNumber denominator)
{
	float denominator_ = denominator.getRealPart() * denominator.getRealPart() + denominator.getImaginaryPart() * denominator.getImaginaryPart();
	
	_real = (numerator.getRealPart() * denominator.getRealPart() + numerator.getImaginaryPart() * denominator.getImaginaryPart()) / denominator_;
	_imaginary = (-1 * numerator.getRealPart() * denominator.getImaginaryPart() + numerator.getImaginaryPart() * denominator.getRealPart()) / denominator_;
}

ComplexNumber ComplexNumber::raiseComplexNumberToPower(int power)
{
	if (power == 0) {
		_real = 1.0f;
		_imaginary = 0.0f;
		ComplexNumber complexNumber = ComplexNumber(_real, _imaginary);
		return complexNumber;
	}
	else {
		ComplexNumber complexNumberRaised = ComplexNumber(_real, _imaginary);
		ComplexNumber complexNumberTemp = ComplexNumber(_real, _imaginary);

		for (int i = 0; i < power - 1; i++)
		{
			complexNumberRaised = multiplyComplexNumbers(complexNumberRaised, complexNumberTemp);
		}

		return complexNumberRaised;
	}
}
void ComplexNumber::raiseComplexNumberToPower_(ComplexNumber complexNumber, int power)
{
	if (power == 0) {
		_real = 1.0f;
		_imaginary = 0.0f;
	}
	else {
		ComplexNumber complexNumberRaised = complexNumber;

		for (int i = 0; i < power - 1; i++)
		{
			complexNumberRaised.multiplyComplexNumbers_(complexNumberRaised, complexNumber);
		}

		_real = complexNumberRaised.getRealPart();
		_imaginary = complexNumberRaised.getImaginaryPart();
	}
}
void ComplexNumber::raiseComplexNumberToPower_(int power)
{
	if (power == 0) {
		_real = 1.0f;
		_imaginary = 0.0f;
	}
	else {
		ComplexNumber complexNumberRaised = ComplexNumber(_real, _imaginary);
		ComplexNumber complexNumberTmp = ComplexNumber(_real, _imaginary);

		for (int i = 0; i < power - 1; i++)
		{
			complexNumberRaised.multiplyComplexNumbers_(complexNumberRaised, complexNumberTmp);
		}

		_real = complexNumberRaised.getRealPart();
		_imaginary = complexNumberRaised.getImaginaryPart();
	}
}