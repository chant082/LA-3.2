#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions_to_implement.cpp"
#include <vector>

TEST_CASE ( "Factorials are computed", "[factorial]") // tag
{
  CHECK( Factorial(0) == 1 ); // assertion
  REQUIRE( Factorial(1) == 1 );
  REQUIRE( Factorial(2) == 2 );
  REQUIRE( Factorial(3) == 6 );
  REQUIRE( Factorial(10) == 3628800 );
}

TEST_CASE("incrementing values in integer vector", "[addN]")
{
	std::vector<int> v{1,2,3,5,6,7,8,10};

	SECTION("checking with +ve n")
  {
		int n=5;
		std::vector<int> res = AddN(v, n);
		srand(time(NULL));
		int random = rand()%v.size();
		REQUIRE(v.size() == res.size());
		REQUIRE( res[0] == 6 );
		REQUIRE( res[v.size()-1] == 15 );
		REQUIRE(res[random] == v[random]+n);
	}
	SECTION("checking with -ve n")
  {
		int n=-5;
		std::vector<int> res = AddN(v, n);
		srand(time(NULL));
		int random = rand()%v.size();
		REQUIRE(v.size() == res.size());
		REQUIRE( res[0] == -4 );
		REQUIRE( res[v.size()-1] == 5 );
		REQUIRE(res[random] == v[random]+n);
	}

}

TEST_CASE("Sums all numbers in a vector and returns the resulting value", "[Sum]")
{
	std::vector<double> v{1.1,2.2,3.3,5.5,6.6,7.7,8.8,10.1};

	SECTION("check +ve values")
	{
		REQUIRE(Sum(v) == Approx(45.3).margin(0.01));
	}

	std::vector<double> w{-1.1, -2.2, -3.3, -5.5, -6.6, -7.7, -8.8,-10.1};
	
	SECTION("check -ve values")
	{
		REQUIRE(Sum(w) == Approx(-45.3).margin(0.01));
	}

		std::vector<double> y{-1.1, 2.2, -3.3, 5.5, -6.6, 7.7, -8.8,10.1};
	
	SECTION("check -ve values")
	{
		REQUIRE(Sum(y) == Approx(5.7).margin(0.01));
	}
}

TEST_CASE("divides an input integer by 2 until it is impossible to do so, then returns the final number","[RemoveTwos]")
{
	CHECK(RemoveTwos(2) == 1);
	REQUIRE(RemoveTwos(16) == 1);
	REQUIRE(RemoveTwos(26) == 13);
	REQUIRE(RemoveTwos(52) == 13);
	REQUIRE(RemoveTwos(8) == 1);
	REQUIRE(RemoveTwos(-11) == -11);
}

TEST_CASE("Takes two strings and returns a new string that is the result of removing all occurrences of s2 from s1.", "[RemoveAllSubstrings]")
{
	CHECK(RemoveAllSubstrings("Hello World", "l") == "Heo Word");
	CHECK(RemoveAllSubstrings("banana", "na") == "ba");
	CHECK(RemoveAllSubstrings("aaaaaaa", "a") == "");
	CHECK(RemoveAllSubstrings("test", "z") == "test");
	CHECK(RemoveAllSubstrings("Major", "Majors") == "Major");
}

TEST_CASE("takes two strings and returns a new string that is the result of removing the first occurrence of s2 from s1.", "[RemoveFirstSubstring]")
{
	CHECK(RemoveFirstSubstring("Hello World", "l") == "Helo World");
	CHECK(RemoveFirstSubstring("banana", "na") == "bana");
	CHECK(RemoveFirstSubstring("aaaaaaa", "a") == "aaaaaa");
	CHECK(RemoveFirstSubstring("test", "z") == "test");
	CHECK(RemoveFirstSubstring("Major", "Majors") == "Major");
}
