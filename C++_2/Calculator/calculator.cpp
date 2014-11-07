#include "calculator.h"

  Calculator::Calculator() {
    value_ = 0;
  }

  Calculator::Calculator(double value) {
    value_ = value;
  }

  double Calculator::value() {
    return value_;
  }

  void Calculator::set_value(double value) {
    value_ = value;
  }

  void Calculator::Add(double value) {
    value_ = value_ + value;
  }

  void Calculator::Subtract(double value) {
    value_ = value_ - value;
  }

  void Calculator::Multiply(double value) {
    value_ = value_ * value;
  }

  void Calculator::Divide(double value) {
    if (value == !0)
	  value_ = value_ / value;
  }

  void Calculator::Exponent(double value) {
    double num = value_;
	if (value == 0) {
	  value_ = 1;
	} else {
	for (int i = 1; i < value; i++)
	  value_ = value_ * num;
	}	
  }

  void Calculator::Reset() {
    value_ = 0;
  }
 
  string Calculator::ToString() {
    stringstream ss;
	ss.setf(std::ios::showpoint | std::ios::fixed);
	ss.precision(4);
	ss << value_;
	string s = ss.str();
	return s;
   }