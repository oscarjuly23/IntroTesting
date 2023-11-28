#include <stdio.h>
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <math.h>

unsigned int Factorial(unsigned int n) {
    return n <= 1 ? n : Factorial(n-1)*n;
}
int mathFunction (int n1) {
	int resultat;
	resultat = (((pow(n1,2))+n1+1)/((Factorial(n1))-1));
	return resultat;
}
TEST_CASE( "5 factorials > 1", "[factorial]") {
	REQUIRE( Factorial(1) == 1 );
	REQUIRE( Factorial(2) == 2 );
	REQUIRE( Factorial(3) == 6 );
	REQUIRE( Factorial(6) == 720 );
	REQUIRE( Factorial(10) == 3628800 );
}

TEST_CASE( "0 factorial", "[factorial]") {
	REQUIRE( Factorial(0) == 1);
}

TEST_CASE( "Op Mat. <= 1", "[mathFunction]"){ // No pot ser ja que donarà infinit
//	REQUIRE( mathFunction(0)==!
// 	REQUIRE( mathFunction(1)==!
}

TEST_CASE( "Op Mat. 3 num > 1", "[mathFunction]") {
	REQUIRE( mathFunction(2)==7);
	REQUIRE( mathFunction(3)==2); // Utilitzem int i no tenim en compte els decimals
	REQUIRE( mathFunction(4)==0);
}
