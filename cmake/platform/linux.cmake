# Any Config
# Copyright (C) 2024 Wend4r
# Licensed under the GPLv3 license. See LICENSE file in the project root for details.

# Warnings
set(PLATFORM_COMPILER_OPTIONS
	-Wall -Wno-uninitialized -Wno-switch -Wno-unused
	-Wno-conversion-null -Wno-write-strings
	-Wno-invalid-offsetof -Wno-reorder
	-Wno-register

	# Others
	-mfpmath=sse -msse -fno-strict-aliasing
	-fno-threadsafe-statics -fvisibility=default
)

set(PLATFORM_LINKER_OPTIONS)
set(PLATFORM_COMPILE_DEFINITIONS)
