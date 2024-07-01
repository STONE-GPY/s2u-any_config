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

#ifndef _INCLUDE_ANY_CONFIG_BASE_READER_HPP_
#define _INCLUDE_ANY_CONFIG_BASE_READER_HPP_

#pragma once

#include "base.hpp"
#include "types.hpp"

namespace AnyConfig
{
	class CBaseReader : public CBase
	{
	public:
		//
		// Load ones (globals).
		//
		static bool _Load(const Load_t &aParams);
		static bool _Load(const Load2_t &aParams);
		static bool _Load(const Load3_t &aParams);

		static bool _LoadFromFile(const LoadFromFile_t &aParams);
		static bool _LoadFromFile(const LoadFromFile2_t &aParams);

		static bool _LoadNoHeader(const LoadNoHeader_t &aParams);

	public:
		//
		// Load ones (members).
		//
		bool Load(const LoadNoContext_t &aParams);
		bool Load(const Load2NoContext_t &aParams);
		bool Load(const Load3NoContext_t &aParams);

		bool LoadFromFile(const LoadFromFileNoContext_t &aParams);
		bool LoadFromFile(const LoadFromFile2NoContext_t &aParams);

		bool LoadNoHeader(const LoadNoHeaderAndContext_t &aParams);
	}; // CBaseReader
}; // AnyConfig

#endif //_INCLUDE_ANY_CONFIG_BASE_READER_HPP_
