#include <iostream>
#include <string>

namespace UnitTest
{
	template<typename T>
	bool IsEquals(T p_First, T p_Second){
		return p_First == p_Second;
	}

	template<typename T>
	bool IsLower(T p_First, T p_Second){
		return p_First < p_Second;
	}

	template<typename T>
	bool IsHigher(T p_First, T p_Second){
		return p_First > p_Second;
	}

	template<typename T>
	void TestEqual(T p_Expected, T p_Got, const std::string &p_sMessage){
		if (IsEquals(p_Expected, p_Got))
		{
			std::cout << p_sMessage << " ... was put to the test and Passed!" << std::endl;
			return;
		}
		std::cout << p_sMessage << " ... failed the kings test. Expected: " << p_Expected << ", Got: " << p_Got << std::endl;
	}

	template<typename T>
	void TestLower(T p_First, T p_Second, const std::string &p_sMessage){
		if (IsLower(p_First, p_Second))
		{
			std::cout << p_sMessage << "... was put to the test and Passed!" << std::endl;
			return;
		}
		std::cout << p_sMessage << " " << p_First << " is not smaller than " << p_Second << std::endl;
	}

	template<typename T>
	void TestHigher(T p_First, T p_Second, const std::string &p_sMessage){
		if (IsHigher(p_First, p_Second))
		{
			std::cout << p_sMessage << "... was put to the test and Passed!" << std::endl;
			return;
		}
		std::cout << p_sMessage << " " << p_First << " is not higher than " << p_Second << std::endl;
	}
}
	