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

#include "peano_natural_number.h"
#include "peano_successor.h"
#include "peano_addition.h"
#include "peano_multiplication.h"

namespace peano
{
	template< typename Type >
	constexpr auto value_of() -> decltype(Type::value)
	{
		return Type::value;
	}

	template< typename Type >
	constexpr auto value_of(Type) -> decltype(value_of<Type>())
	{
		return value_of<Type>();
	}

	template< typename Type >
	constexpr auto to_natural_number() -> natural_number<value_of<Type>()>
	{
		return {};
	}

	template< typename Type >
	constexpr auto to_natural_number(Type) -> decltype(to_natural_number<Type>())
	{
		return to_natural_number<Type>();
	}

	namespace detail
	{
		template< std::intmax_t integer >
		struct succession;

		template< std::intmax_t integer >
		using succession_type = typename succession<integer>::type;

		template< std::intmax_t integer >
		struct succession
		{
			using type = successor<succession_type<integer - 1>>;
		};

		template<>
		struct succession<0>
		{
			using type = natural_number<0>;
		};
	}
	
	template< std::intmax_t integer >
	constexpr auto successor_of() -> detail::succession_type<integer>
	{
		return {};
	}
}