#pragma once

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

#include <cstdint>
#include <iostream>

namespace peano
{
	//
	// natural_number
	//

	template< std::intmax_t integer >
	struct natural_number
	{
		static constexpr std::intmax_t value = integer;
	};

	//
	// zero
	//

	// Axiom 1: 0 is a natural number
	constexpr natural_number<0> zero;

	//
	// operator ==
	//

	// 2. For every natural number x, x = x.That is, equality is reflexive.
	// 3. For all natural numbers x and y, if x = y, then y = x.That is, equality is symmetric.
	// 4. For all natural numbers x, y and z, if x = y and y = z, then x = z.That is, equality is transitive.
	// 5. For all a and b, if b is a natural number and a = b, then a is also a natural number.That is, the natural numbers are closed under equality.
	template< std::intmax_t left_value, std::intmax_t right_value >
	constexpr bool operator ==(natural_number<left_value>, natural_number<right_value>) noexcept
	{
		return (left_value == right_value);
	}

	//
	// operator <<
	//

	template< std::intmax_t integer >
	std::ostream & operator <<(std::ostream & stream, natural_number<integer>)
	{
		stream << "natural_number<";
		stream << integer;
		stream << ">";
		return stream;
	}
}