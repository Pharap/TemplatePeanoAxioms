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

#include "peano_natural_number.h"

namespace peano
{
	template< typename Type >
	struct successor
	{
		static constexpr auto value = (Type::value + 1);

		// 6. For every natural number n, S(n) is a natural number.
		operator natural_number<value>() const
		{
			return {};
		}
	};

	//
	// operator ==
	//

	// 7. For all natural numbers m and n, m = n if and only if S(m) = S(n).That is, S is an injection.
	// 8. For every natural number n, S(n) = 0 is false.That is, there is no natural number whose successor is 0.
	template< typename LeftType, typename RightType >
	constexpr bool operator ==(successor<LeftType>, successor<RightType>) noexcept
	{
		return (successor<LeftType>::value == successor<RightType>::value);
	}

	//
	// succ
	//

	template< typename Type >
	constexpr auto succ(Type) -> successor<Type>
	{
		return {};
	}

	//
	// operator <<
	//

	template< typename Type >
	std::ostream & operator <<(std::ostream & stream, successor<Type>)
	{
		stream << "successor<";
		stream << Type();
		stream << ">";
		return stream;
	}
}
