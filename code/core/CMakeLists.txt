# Variables set by the sub-CMakeLists.txt in src and below
set(PX_CORE_INCLUDE_FILES "")
set(PX_CORE_SOURCE_FILES "")

# Add public and private source folders
add_subdirectory(public)
add_subdirectory(private)

# Library
add_library(px_core INTERFACE)
target_sources(px_core INTERFACE ${PX_CORE_INCLUDE_FILES} ${PX_CORE_SOURCE_FILES})
target_include_directories(px_core
	INTERFACE # For now as there is only a header...
	#PUBLIC # The folder must be used in the include path for any target using this library
		"public"
)
#target_link_libraries(px_core
	#PRIVATE
	#	ext::fmt
#)
# Give a 'scoped' name to libraries targets, as it can't be mistaken with system libraries
add_library(px::core ALIAS px_core)


# Tests
add_subdirectory(tests)