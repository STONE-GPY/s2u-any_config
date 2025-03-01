/**
 * vim: set ts=4 sw=4 tw=99 noet :
 * ======================================================
 * Source 2 util to read a config of any format.
 * Written by Wend4r (2024).
 * ======================================================

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef _INCLUDE_ANY_CONFIG_KEYVALUES_TYPES_HPP_
#define _INCLUDE_ANY_CONFIG_KEYVALUES_TYPES_HPP_

#pragma once

#include <any_config/base/types.hpp>

#include <tier1/keyvalues3.h>

namespace AnyConfig
{
	struct CKV1TextEscape_t
	{
		KV1TextEscapeBehavior_t m_eBehavior;
	}; // CKV1TextEscape_t

	template<typename T>
	struct CKV1Unk_t
	{
		T m_aValue;
	}; // CKV1Unk_t<T>

	template<class T>
	struct CKV1Proccessor_t : public CIO_t<const T>
	{
	}; // CKV1Proccessor_t<T>
}; // AnyConfig

#endif // _INCLUDE_ANY_CONFIG_KEYVALUES_TYPES_HPP_
