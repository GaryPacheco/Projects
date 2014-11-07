/*
 * Author: Gary Pacheco
 * Description: Creates a dynamic array and sets a maximum capacity of list
 * 				list items. Allows users to add values to array as well as 
 *				delete values. Sums and averages values in the array.
 */
 #ifndef PACHECO_NATURAL_LIST_H
 #define PACHECO_NATURAL_LIST_H
 
 #include <iostream>
 #include <string>
 #include <sstream>
 using std::stringstream;
 using std::string;
 using std::cout;
 using std::endl;
 
 class NaturalList {
  public:
    /* Constructor 
	 * Creates dynamic array and sets the size to the value in capacity, sets
	 * size_ to 0, and capcity_ to value in capacity
	 * @param unsigned int capacity - Value to set the array size to.
	 */
    NaturalList(unsigned int capacity);
	/* Deconstructor 
	 * Destructs and delets the array.
	 */
	~NaturalList();
	/* Add
	 * Adds the passed in value to the array. Places at the end of the list and
	 * returns true. If array size is at capacity returns false for list to big.
	 * @param unsigned int value - value to be added to the list
	 * @return bool - True if value added to list, false if unable too.
	 */
	bool Add(unsigned int value);
	/* GetNumber
	 * Returns the value store in the list_ at the indexed location.
	 * @param unsigned int index - Location of item wanted.
	 * @return unsigned int - value at location index
	 */
	unsigned int GetNumber(unsigned int index);
	/* ToString
	 * Uses stringstream to print all values seperated by a ", " 
	 * @return string - output of the list
	 */
	string ToString();
	/* GetSize
	 * Returns the size of the array
	 * @return unsigned int - size of the array
	 */
	unsigned int GetSize();
	/* GetCapacity
	 * Returns the maximum capacity of the array
	 * @return unsigned int - maximum capacity of the array
	 */
	unsigned int GetCapacity();
	/* Sum
	 * Adds all list values together and returns the sum.
	 * @return unsigned int - sum of all list_ values.
	 */
	unsigned int Sum();
	/* Average
	 * Finds the average of all values in the list.
	 * @return unsigned int - average of all list_ values.
	 */
	double Average();
	/* Clear
	 * Deletes the array and sets the array to a new max capcity.
	 * @param unsigned int new_size - New capacity of the array.
	 */
	void Clear(unsigned int new_size);
	
  private: 
    unsigned int* list_;
	unsigned int size_;
	unsigned int capacity_;
 };
 #endif //PACHECO_NATURAL_LIST_H
  