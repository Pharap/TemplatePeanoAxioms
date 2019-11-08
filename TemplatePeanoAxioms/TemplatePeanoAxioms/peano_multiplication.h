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
#include "peano_addition.h"

namespace peano
{
	//
	// multiplication
	//

	template< typename LeftType, typename RightType >
	struct multiplication;

	// a * 0 = 0
	template< typename LeftType >
	struct multiplication<LeftType, natural_number<0>>
	{
		using type = natural_number<0>;

		static constexpr std::intmax_t value = 0;
	};

	// a * 0 = 0
	template< typename RightType >
	struct multiplication<natural_number<0>, RightType>
	{
		using type = natural_number<0>;

		static constexpr std::intmax_t value = 0;
	};

	// a * S(b) = a + (a * b)
	template< typename LeftType, typename RightType >
	struct multiplication<LeftType, successor<RightType>>
	{
		using type = addition<LeftType, multiplication<LeftType, RightType>>;

		static constexpr std::intmax_t value = (LeftType::value + multiplication<LeftType, RightType>::value);
	};

	//
	// multiplication_type
	//

	template< typename LeftType, typename RightType >
	using multiplication_type = typename multiplication<LeftType, RightType>::type;

	//
	// operator +
	//

	template< typename LeftType, typename RightType >
	constexpr auto operator *(successor<LeftType>, successor<RightType>) -> multiplication<successor<LeftType>, successor<RightType>>
	{
		return {};
	}

	template< typename LeftType, std::intmax_t right_integer >
	constexpr auto operator *(successor<LeftType>, natural_number<right_integer>) -> multiplication<successor<LeftType>, natural_number<right_integer>>
	{
		return {};
	}

	template< std::intmax_t left_integer, typename RightType >
	constexpr auto operator *(natural_number<left_integer>, successor<RightType>) -> multiplication<natural_number<left_integer>, successor<RightType>>
	{
		return {};
	}

	template< std::intmax_t left_integer, std::intmax_t right_integer >
	constexpr auto operator *(natural_number<left_integer>, natural_number<right_integer>) -> multiplication<natural_number<left_integer>, natural_number<right_integer>>
	{
		return {};
	}

	//
	// operator <<
	//

	template< typename LeftType, typename RightType >
	std::ostream & operator <<(std::ostream & stream, multiplication<LeftType, RightType>)
	{
		stream << "multiplication<";
		stream << LeftType();
		stream << ", ";
		stream << RightType();
		stream << ">";
		return stream;
	}
}