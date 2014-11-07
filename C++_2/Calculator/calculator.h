/*
 * Name        : calculator.h
 * Author      : Luke Sathrum
 * TEST TAKER  : GARY PACHECO
 * Description : Class Header File for Midterm #1 Calculator Class
 */
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <sstream>
using std::string;
using std::stringstream;

/*
 * Class Calculator.
 * Performs basic arithmetic operations
 */
class Calculator {
 public:
  /*
   * Default Constructor.
   * Sets the calculator's value to 0
   */
  Calculator();

  /*
   * Overloaded Constructor.
   * Sets the calculator's value to the value passed in.
   * @param double value - The value to set the calculator to
   */
  Calculator(double value);

  /*
   * Accessor
   * Gets the current value of the calculator
   * @return double - The current value of the calculator
   */
  double value();

  /*
   * Mutator
   * Sets the value of the calculator
   * @param double value - The value to set the calculator to.
   */
  void set_value(double value);

  /*
   * Adds the parameter to the current value of the calculator
   * @param double value - The value to add.
   */
  void Add(double value);

  /*
   * Subtracts the parameter from the current value of the calculator
   * @param double value - The value to subtract.
   */

  void Subtract(double value);
  /*
   * Multiplies the parameter by the current value of the calculator
   * @param double value - The value to multiply.
   */

  void Multiply(double value);
  /*
   * Divides the current value of the calculator by the parameter
   * @param double value - The value to divide.
   */

  void Divide(double value);
  /*
   * Takes the current value of the calculator to the power of the parameter
   * Don't forget: x ^ 0 = 1
   * @param double value - The power.
   */

  void Exponent(double value);
  /*
   * Resets the current value of the calculator to zero.
   */

  void Reset();
  /*
   * HELPFUL:
   *  .setf(std::ios::showpoint | std::ios::fixed)
   *  .precision()
   * @return string - The current value of the calculator to 4 decimal places
   */
  string ToString();
  
 private:
  double value_;
};

#endif /* CALCULATOR_H */
