#include "../includes/ComplexNumberPolar.h"


/* Constructors definition */
ComplexNumberPolar::ComplexNumberPolar(float module_, float angle) :
	_module(module_),
	_angle(angle)
{
	_module = module_;
	_angle = angle;
}

ComplexNumberPolar::ComplexNumberPolar() :
	_module(),
	_angle()
{
	_module = 0.0f;
	_angle = 0.0f;
}

/* Functions definition */
void ComplexNumberPolar::showComplexNumberBinaryForm()
{
	float _real = _module * cos(_angle * M_PI / 180);
	float _imaginary = _module * sin(_angle * M_PI / 180);

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

void ComplexNumberPolar::showComplexNumberAngleForm()
{
	std::cout << _module;
	_setmode(_fileno(stdout), _O_U16TEXT);
	std::wcout << L"\x221f";
	_setmode(_fileno(stdout), _O_TEXT);
	std::cout << _angle;
	_setmode(_fileno(stdout), _O_U16TEXT);
	std::wcout << L"\x00b0" << std::endl;
	_setmode(_fileno(stdout), _O_TEXT);
}

void ComplexNumberPolar::showComplexNumberPolarForm() {

	std::cout << _module << "(cos(" << _angle;
	_setmode(_fileno(stdout), _O_U16TEXT);
	std::wcout << L"\x00b0";
	_setmode(_fileno(stdout), _O_TEXT);
	std::cout << ") + isin(" << _angle;
	_setmode(_fileno(stdout), _O_U16TEXT);
	std::wcout << L"\x00b0";
	_setmode(_fileno(stdout), _O_TEXT);
	std::cout << "))" << std::endl;
}

ComplexNumberPolar ComplexNumberPolar::complexConjugate()
{
	float _real = _module * cos(_angle * M_PI / 180);
	float _imaginary = -1 * _module * sin(_angle * M_PI / 180);

	float angle = atan2(_imaginary, _real);

	ComplexNumberPolar complexNumber = ComplexNumberPolar(_module, angle * 180 / M_PI);

	return complexNumber;
}
void ComplexNumberPolar::complexConjugate_()
{
	float _real = _module * cos(_angle * M_PI / 180);
	float _imaginary = -1 * _module * sin(_angle * M_PI / 180);

	float angle = atan2(_imaginary, _real);

	_angle = angle * 180 / M_PI;
}

ComplexNumberPolar ComplexNumberPolar::sumComplexNumber(ComplexNumberPolar complexNumber)
{
	ComplexNumberPolar complexNumberSum;

	float real = _module * cos(_angle * M_PI / 180) + complexNumber.getRealPart();
	float imaginary = _module * sin(_angle * M_PI / 180) + complexNumber.getImaginaryPart();

	complexNumberSum.setModule(sqrt(real * real + imaginary * imaginary));
	complexNumberSum.setAngle(atan2(imaginary, real) * 180 / M_PI);

	return complexNumberSum;
}
void ComplexNumberPolar::sumComplexNumbers_(ComplexNumberPolar complexNumber1, ComplexNumberPolar complexNumber2)
{
	float real = complexNumber1.getModule() * cos(complexNumber1.getAngleRadians()) +
		complexNumber2.getModule() * cos(complexNumber2.getAngleRadians());
	float imaginary = complexNumber1.getModule() * sin(complexNumber1.getAngleRadians()) +
		complexNumber2.getModule() * sin(complexNumber2.getAngleRadians());

	_module = sqrt(real * real + imaginary * imaginary);
	_angle = atan2(imaginary, real) * 180 / M_PI;
}

ComplexNumberPolar ComplexNumberPolar::subtractComplexNumber(ComplexNumberPolar complexNumber)
{
	ComplexNumberPolar complexNumberSum;

	float real = _module * cos(_angle * M_PI / 180) - complexNumber.getRealPart();
	float imaginary = _module * sin(_angle * M_PI / 180) - complexNumber.getImaginaryPart();

	complexNumberSum.setModule(sqrt(real * real + imaginary * imaginary));
	complexNumberSum.setAngle(atan2(imaginary, real) * 180 / M_PI);

	return complexNumberSum;
}
void ComplexNumberPolar::subtractComplexNumbers_(ComplexNumberPolar minuend, ComplexNumberPolar subtrahend)
{
	float real = minuend.getModule() * cos(minuend.getAngleRadians()) -
		subtrahend.getModule() * cos(subtrahend.getAngleRadians());
	float imaginary = minuend.getModule() * sin(minuend.getAngleRadians()) -
		subtrahend.getModule() * sin(subtrahend.getAngleRadians());

	_module = sqrt(real * real + imaginary * imaginary);
	_angle = atan2(imaginary, real) * 180 / M_PI;
}

ComplexNumberPolar ComplexNumberPolar::multiplyByComplexNumber(ComplexNumberPolar complexNumber)
{
	ComplexNumberPolar complexNumberMult;

	float angle = _angle + complexNumber.getAngleDegrees();

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

	complexNumberMult.setModule(_module * complexNumber.getModule());
	complexNumberMult.setAngle(angle);

	return complexNumberMult;
}
void ComplexNumberPolar::multiplyComplexNumbers_(ComplexNumberPolar complexNumber1, ComplexNumberPolar complexNumber2)
{
	_module = complexNumber1.getModule() * complexNumber2.getModule();
	_angle = complexNumber1.getAngleDegrees() + complexNumber2.getAngleDegrees();

	if (_angle > 180) {
		while (_angle > 180) {
			_angle = _angle - 360;
		}
	}
	else if (_angle < -180) {
		while (_angle < -180) {
			_angle = _angle + 360;
		}
	}
}

ComplexNumberPolar ComplexNumberPolar::divideByComplexNumber(ComplexNumberPolar complexNumber)
{
	ComplexNumberPolar complexNumberDiv;

	float angle = _angle - complexNumber.getAngleDegrees();

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

	complexNumberDiv.setModule(_module / complexNumber.getModule());
	complexNumberDiv.setAngle(angle);

	return complexNumberDiv;
}
void ComplexNumberPolar::divideComplexNumbers_(ComplexNumberPolar numerator, ComplexNumberPolar denominator)
{
	_module = numerator.getModule() / denominator.getModule();
	_angle = numerator.getAngleDegrees() - denominator.getAngleDegrees();

	if (_angle > 180) {
		while (_angle > 180) {
			_angle = _angle - 360;
		}
	}
	else if (_angle < -180) {
		while (_angle < -180) {
			_angle = _angle + 360;
		}
	}
}

ComplexNumberPolar ComplexNumberPolar::raiseComplexNumberToPower(int power)
{
	if (power == 0) {
		ComplexNumberPolar complexNumberRaised = ComplexNumberPolar(1.0f, 0.0f);
		return complexNumberRaised;
	}

	ComplexNumberPolar complexNumberTemp = ComplexNumberPolar(_module, _angle);
	ComplexNumberPolar complexNumberRaised = complexNumberTemp;

	for (int i = 0; i < power - 1; i++)
	{
		complexNumberRaised = multiplyComplexNumbers(complexNumberRaised, complexNumberTemp);
	}

	return complexNumberRaised;
}
void ComplexNumberPolar::raiseComplexNumberToPower_(ComplexNumberPolar complexNumber, int power)
{
	if (power == 0) {
		_module = 1.0f;
		_angle = 0.0f;
	}
	else {
		ComplexNumberPolar complexNumberRaised = complexNumber;

		for (int i = 0; i < power - 1; i++)
		{
			complexNumberRaised.multiplyComplexNumbers_(complexNumberRaised, complexNumber);
		}

		_module = complexNumberRaised.getModule();
		_angle = complexNumberRaised.getAngleDegrees();
	}
}
void ComplexNumberPolar::raiseComplexNumberToPower_(int power)
{
	if (power == 0) {
		_module = 1.0f;
		_angle = 0.0f;
	}
	else {
		ComplexNumberPolar complexNumberRaised = ComplexNumberPolar(_module, _angle);
		ComplexNumberPolar complexNumberTmp = ComplexNumberPolar(_module, _angle);

		for (int i = 0; i < power - 1; i++)
		{
			complexNumberRaised.multiplyComplexNumbers_(complexNumberRaised, complexNumberTmp);
		}

		_module = complexNumberRaised.getModule();
		_angle = complexNumberRaised.getAngleDegrees();
	}
}
