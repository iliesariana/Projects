# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Stars_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Stars_autogen.dir\\ParseCache.txt"
  "Stars_autogen"
  )
endif()
