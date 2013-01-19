##################################################
#                epoc daemon                   #
##################################################
LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include)
add_executable (dsp dsp.c)
ADD_DEPENDENCIES(dsp emokit)
target_link_libraries (dsp emokit emokit_dsp plot ${LIBS})

SET_TARGET_PROPERTIES(dsp PROPERTIES
	INSTALL_RPATH_USE_LINK_PATH TRUE
	INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib
	BUILD_WITH_INSTALL_RPATH TRUE )

INSTALL (TARGETS dsp
	RUNTIME DESTINATION bin
)

