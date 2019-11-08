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
#include "peano_successor.h"

namespace peano
{
	//
	// addition
	//

	template< typename LeftType, typename RightType >
	struct addition;

	// a + 0 = a
	template< typename LeftType >
	struct addition<LeftType, natural_number<0>>
	{
		using type = LeftType;

		static constexpr std::intmax_t value = type::value;
	};

	// a + 0 = a
	template< typename RightType >
	struct addition<natural_number<0>, RightType>
	{
		using type = RightType;

		static constexpr std::intmax_t value = type::value;
	};

	// a + S(b) = S(a + b)
	template< typename LeftType, typename RightType >
	struct addition<LeftType, successor<RightType>>
	{
		using type = successor<typename addition<LeftType, RightType>::type>;

		static constexpr std::intmax_t value = type::value;
	};

	//
	// addition_type
	//

	template< typename LeftType, typename RightType >
	using addition_type = typename addition<LeftType, RightType>::type;

	//
	// operator +
	//

	template< typename LeftType, typename RightType >
	constexpr auto operator +(successor<LeftType>, successor<RightType>) -> addition<successor<LeftType>, successor<RightType>>
	{
		return {};
	}

	template< typename LeftType, std::intmax_t right_integer >
	constexpr auto operator +(successor<LeftType>, natural_number<right_integer>) -> addition<successor<LeftType>, natural_number<right_integer>>
	{
		return {};
	}

	template< std::intmax_t left_integer, typename RightType >
	constexpr auto operator +(natural_number<left_integer>, successor<RightType>) -> addition<natural_number<left_integer>, successor<RightType>>
	{
		return {};
	}

	template< std::intmax_t left_integer, std::intmax_t right_integer >
	constexpr auto operator +(natural_number<left_integer>, natural_number<right_integer>) -> addition<natural_number<left_integer>, natural_number<right_integer>>
	{
		return {};
	}

	//
	// operator <<
	//

	template< typename LeftType, typename RightType >
	std::ostream & operator <<(std::ostream & stream, addition<LeftType, RightType>)
	{
		stream << "addition<";
		stream << LeftType();
		stream << ", ";
		stream << RightType();
		stream << ">";
		return stream;
	}
}