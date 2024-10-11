# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\untitled14_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\untitled14_autogen.dir\\ParseCache.txt"
  "untitled14_autogen"
  )
endif()
