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

#ifndef _INCLUDE_ANY_CONFIG_KEYVALUES_READER_HPP_
#define _INCLUDE_ANY_CONFIG_KEYVALUES_READER_HPP_

#pragma once

#include "types.hpp"

#include <any_config/base/reader.hpp>

namespace AnyConfig
{
	class CKeyValuesReader : public CBaseReader
	{
	public:
		//
		// Load ones (globals).
		//
		static bool _LoadFromKV1File(const LoadFromKV1File_t &aParams);
		static bool _LoadFromKV1Text(const LoadFromKV1Text_t &aParams);
		static bool _LoadFromKV1Text_Translated(const LoadFromKV1Text_Translated_t &aParams);

	public:
		//
		// Load ones (members).
		//
		bool LoadFromKV1File(const LoadFromKV1FileNoContext_t &aParams);
		bool LoadFromKV1Text(const LoadFromKV1TextNoContext_t &aParams);
		bool LoadFromKV1Text_Translated(const LoadFromKV1Text_TranslatedNoContext_t &aParams);
	}; // CKeyValuesReader
}; // AnyConfig

#endif //_INCLUDE_ANY_CONFIG_KEYVALUES_READER_HPP_
