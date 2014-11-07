/*
 * Name        : exercise_2.cpp
 * Author      : Gary Pacheco
 * Description : Using Arithmetic to finish the functions MakeChange() and
 *               LaunchHumanCannonball()
 */

// Please note the header above. You need to include the name of the file, the
// author, a description of the program and any sources used
#include <iostream>
#include <cmath>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

// For testing (DO NOT ALTER)
void UnitTest();
void Test(bool test, int number, string more_info = "");

// Function Prototypes (DO NOT ALTER)
void MakeChange(int initial_value, int &quarters, int &dimes, int &nickels,
                int &pennies);
double LaunchHumanCannonball(double initial_velocity, double launch_angle);

// Create a Constant named kPI which is initialized to 3.1415927
const double kPI = 3.1415927;

// Program Execution Starts Here
int main() {
  // To test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

/*
 * Given an initial integer value (representing change to be given, such as in a
 * financial transaction), break the value down into the number of quarters,
 * dimes, nickels, and pennies that would be given as change.
 * @param int initial_value - The amount of change to be broken down
 * @param int quarters  - The number of quarters that come out of initial_value
 * @param int dimes - The number of dimes that come out of initial_value,
 *                    after quarters have been taken out
 * @param int nickels - The number of nickels that come out of initial_value,
 *                      after quarters and dimes have been taken out
 * @param int pennies - The number of pennies that come out of initial_value,
 *                      after quarters, dimes, and nickels have been taken out
 */
void MakeChange(int initial_value, int &quarters, int &dimes, int &nickels,
                int &pennies) {
  quarters = initial_value / 25;
  initial_value = initial_value % 25;
  dimes = initial_value / 10;
  initial_value = initial_value % 10;
  nickels = initial_value / 5;
  initial_value = initial_value % 5;
  pennies = initial_value / 1;
  initial_value = initial_value % 1;
}

/*
 * Computes the horizontal distance traveled by a human cannonball given an
 * initial velocity and launch angle. Simplified -- does not account for many
 * factors that affect projectile motion.
 * @param double initial_velocity - Represents the initial velocity of the
 *                                  human cannonball in meters/second
 * @param double launch_angle -  Represents the launch angle of the human
 *                               cannonball in degrees
 * @return double  - Represents the horizontal distance the human cannonball
 *                   will travel
 */
double LaunchHumanCannonball(double initial_velocity, double launch_angle) {
  // (1) Convert launch_angle from degrees to radians
  //     [radangle = degangle * (kPI/180)]
  double radian_angle = launch_angle * (kPI/180);
  
  // (2) Compute final horizontal/x velocity
  //     [xveloc = initialVelocity * cos(radangle)]
  double x_velocity = initial_velocity * cos(radian_angle);
  
  // (3) Compute final vertical/y velocity
  //     [yveloc = initialVecity * sin(radangle) * -1]
  double y_velocity = initial_velocity * sin(radian_angle) * -1;

  // (4) Compute time of flight [flighttime = (yveloc) * 2 / -9.8]
  double flight_time = y_velocity * 2 / -9.8;
  
  // (5) Compute horizontal/x distance traveled
  //     [xdistance = xveloc * flighttime]
  double distance = x_velocity * flight_time;

 return distance;
 }

// For testing (DO NOT ALTER)
void UnitTest() {
  string temp = "This unit test will test some of your code:\n";
  cout << temp << string(temp.length() - 1, '-') << endl;

  int q = -1, n = -1, d = -1, p = -1;
  MakeChange(0, q, d, n, p);
  Test(((q == 0) && (d == 0) && (n == 0) && (p == 0)), 1, "Change of $0.00");

  MakeChange(41, q, d, n, p);
  Test(((q == 1) && (d == 1) && (n == 1) && (p == 1)), 2, "Change of $0.41");

  MakeChange(99, q, d, n, p);
  Test(((q == 3) && (d == 2) && (n == 0) && (p == 4)), 3, "Change of $0.99");

  double value = LaunchHumanCannonball(25.0, 45.0);
  double scale = 0.01;  // round to nearest one-hundredth

  value = (int) (value / scale) * scale;
  Test((value <= 63.9) && (value >= 63.5), 4, "Launch with (25, 45)");

  value = LaunchHumanCannonball(40.0, 60.0);
  value = (int) (value / scale) * scale;
  Test((value <= 141.5) && (value >= 141.1), 5, "Launch with (40, 60)");

  value = LaunchHumanCannonball(10.0, 30.0);
  value = (int) (value / scale) * scale;
  Test((value <= 9.0) && (value >= 8.6), 6, "Launch with (10, 30)");

  value = LaunchHumanCannonball(10.0, 90.0);
  value = (int) (value / scale) * scale;
  Test((value <= 0.2) && (value >= -0.2), 7, "Launch with (10, 90)");

}
// For testing (DO NOT ALTER)
void Test(bool test, int number, string more_info) {
  if (test)
    cout << "PASSSED TEST ";
  else
    cout << "FAILED  TEST ";
  cout << number << " " << more_info << "!\n";
}
