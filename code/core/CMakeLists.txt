if(0)
	set(CORE_SOURCE_FILES )
	set(CORE_INCLUDE_FILES )

	add_library(px_foo ${CORE_SOURCE_FILES} ${CORE_INCLUDE_FILES})
	target_include_directories(px_core
		PUBLIC # The folder must be used in the include path for any target using this library
			include
	)
	target_link_libraries(px_core
		PRIVATE
			ext::fmt
	)
	# Give a 'scoped' name to libraries targets, as it can't be mistaken with system libraries
	add_library(px::core ALIAS px_core)

endif()

# Add sources
#add_subdirectory(src)

# Add tests
add_subdirectory(tests)