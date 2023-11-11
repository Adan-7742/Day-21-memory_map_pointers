//=======================================================================================================
//                                                                                                      =
//............................Program Memory Map .......................................................=
//                                                                                                      =
//=======================================================================================================

#include <iostream>
using namespace std;

// in this lec we will discuss about memory management using c++

//We will discuss how to manage the memory in C++

//.............Virtual memory.................................

//It will tell the computer that it have enough memory space to run the program
//as how it do not have physical memory
//each program is abstracted to processes
//processes have memory Range of 1 to 2^n - 1
// 
// it tel the computer to anything that it want to doo
// 
// all the program is not loaded into the memory but it load the only part that will execute
// will load on to the memory
// 
// ............|......Memory Sections....|..........................
//             |                         |
//             |      System             |
// ------------|-------------------------|---------------------------
//             |      Stack              |
// ------------|-------------------------|---------------------------
//             |      Heap               |
// ------------|-------------------------|---------------------------
//             |      Data               |
// ------------|-------------------------|---------------------------
//             |      Text               |
//-------------|-------------------------|----------------------------


// Stack: we will use stack to store the intilized variables in the program
// local variable and functin call

// Heap:  we will use to store the variable that are not intilized in the program it will use at the runtime
// it is used to store dynamically alocated memory 
// aditional memory that can be ued at run time 

// Text : that is used to store the binary form of data



//=======================================================================================================
//                                                                                                      =
//.......................................Dynamic memory allocation......................................=
//                                                                                                      =
//=======================================================================================================


int pointer() {
	//how we have use pointer so far

	cout << "================================================================================================================" << endl;


	int number{ 22 };    // ..................stack........................

	int* p_number = &number;

	cout << endl;
	cout << "Declearing pointer and adressing it a number : " << endl;
	cout << "number :" << number << endl;

	cout << "p_number :" << p_number << endl;

	cout << "& number :" << &number << endl;

	cout << "* p_number :" << *p_number << endl;


	cout << "================================================================================================================" << endl;

	int* p_number1{};  // uninitilized pointer containing junk adress

	int number1{ 12 };

	p_number1 = &number1;// make it point to valid adress

	cout << endl;
	cout << "unintilized pointers : " << endl;
	cout << "* p_number1" << *p_number1 << endl;

	//.....................................Things to Avoid...........................
	//....................................using pointers.............................


	// directly writing into a junk adress is bad compiler is not going to print it 
	// ............as..........p_number=44;................
	//we are just trying to write into a junk adress

	//...........................................................................
	//if we siply initilized  A pointer to no value
	// .......................as.............int * p{}; ..............
	//and now we are storing a value in it so our program is going to crash 
	// this is a bad thing


	//-------------------------------------------------------------------------|
	//........................Dynamic heap memory..............................|
	//_________________________________________________________________________|

	//dynamic......

	cout << "================================================================================================================" << endl;

	int* p_inter{ nullptr };
	p_inter = new int;
	// this memory belong to our program from now own
	// cant use it for antthing else until we return it 
	// after this ine execute we will have a valid memory loacation aocated
	// the size of allocatwd meory will be such that it can store
	// the type pointed to the pointer



	*p_inter = 77;       // writing into dynamically allocated memory
	cout << endl;
	cout << "dynamicaly allocating memory : " << endl;
	cout << "* p_inter" << *p_inter << endl;

	// return memory to operating sstem
	delete p_inter;
	p_inter = nullptr;
	// if we return a memory then we cant not use it again ti initilize any other value
	//.........................................................................................
	// after returning a value we an again reuse the variablr pointer for storing another value
	//..........................................................................................
	// if we initilize it we have to delete it again
	// and reset into a nul pointer
	//..........................................................................................
	//it is really bad to cal delete a pointer twice
	//......................................................................
	//it will crash the program will not run it properly
	// so dont delete your memory twice ................................


	return 0;


}


int main()
{
	pointer();
}
