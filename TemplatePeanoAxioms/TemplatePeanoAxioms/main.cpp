//
//  Copyright (C) 2019 Pharap (@Pharap)
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#include <cstdlib>
#include <iostream>

#include "peano.h"

void test0()
{
	using namespace peano;
	
	auto a = zero;

	std::cout << a << '\n';
	std::cout << value_of(a) << '\n';
	std::cout << to_natural_number(a) << '\n';
}

void test1()
{
	using namespace peano;

	auto a = succ(zero);

	std::cout << a << '\n';
	std::cout << value_of(a) << '\n';
	std::cout << to_natural_number(a) << '\n';
}

void test2()
{
	using namespace peano;

	auto a = succ(succ(zero));
	auto b = succ(succ(succ(zero)));
	auto c = (a + b);

	std::cout << a << '\n';
	std::cout << b << '\n';
	std::cout << c << '\n';

	std::cout << value_of(a) << '\n';
	std::cout << value_of(b) << '\n';
	std::cout << value_of(c) << '\n';

	std::cout << to_natural_number(a) << '\n';
	std::cout << to_natural_number(b) << '\n';
	std::cout << to_natural_number(c) << '\n';
}

void test3()
{
	using namespace peano;

	auto a = succ(succ(zero));
	auto b = succ(succ(succ(zero)));
	auto c = (a * b);

	std::cout << a << '\n';
	std::cout << b << '\n';
	std::cout << c << '\n';

	std::cout << value_of(a) << '\n';
	std::cout << value_of(b) << '\n';
	std::cout << value_of(c) << '\n';

	std::cout << to_natural_number(a) << '\n';
	std::cout << to_natural_number(b) << '\n';
	std::cout << to_natural_number(c) << '\n';
}

void test4()
{
	using namespace peano;

	auto a = succ(succ(zero));
	auto b = successor_of<2>();

	std::cout << std::boolalpha;
	std::cout << (a == b) << '\n';

	std::cout << a << '\n';
	std::cout << b << '\n';

	std::cout << value_of(a) << '\n';
	std::cout << value_of(b) << '\n';

	std::cout << to_natural_number(a) << '\n';
	std::cout << to_natural_number(b) << '\n';
}

using test_function = void(*)();

constexpr test_function test_functions[]
{
	test0,
	test1,
	test2,
	test3,
	test4,
};

int main()
{
	for(auto & test : test_functions)
	{
		test();
		std::cin.get();
	}

	return EXIT_SUCCESS;
}