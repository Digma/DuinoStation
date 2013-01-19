##########################################
##              libepoc                ###
##########################################

# Create a library called "libepoc"
ADD_LIBRARY (emokit STATIC emokit.c) 
target_link_libraries (emokit ${LIBS}) 

INSTALL (TARGETS emokit
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  )

INSTALL(FILES
  ${LIBEMOKIT_HEADERS}
  DESTINATION include/libemokit
  )


# Create a library called "emokit_dsp"
ADD_LIBRARY (emokit_dsp STATIC emokit_dsp.c) 
# link the math library for linux, automatic for windows
IF(UNIX)
  TARGET_LINK_LIBRARIES(emokit_dsp m)
ENDIF(UNIX)
  target_link_libraries(emokit_dsp emokit ${LIBS})

INSTALL (TARGETS emokit_dsp
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  )

INSTALL(FILES
  ${EMOKIT_DSP_HEADERS}
  DESTINATION include/emokit_dsp_lib
  )

