# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\laba1_algos_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\laba1_algos_autogen.dir\\ParseCache.txt"
  "laba1_algos_autogen"
  )
endif()
