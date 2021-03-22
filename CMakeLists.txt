cmake_minimum_required(VERSION 3.12)

project(us-intl-altgr
  VERSION 1.0.0.0
  DESCRIPTION "US Multinational (Alt Gr dead keys) Keyboard Layout"
  LANGUAGES C
)

set(OUTPUT_FILENAME "kbd-us-intl-altgr.dll" CACHE STRING "The name of the output library, extension included.")

string(TIMESTAMP CURRENT_YEAR "%Y")

configure_file("resources/layout.rc.in" "layout.rc")

add_library(us-intl-altgr MODULE
  "layout.c"
  "layout.rc"
)

set_target_properties(us-intl-altgr PROPERTIES
  OUTPUT_NAME ${OUTPUT_FILENAME}
  SUFFIX "" # It's set to ".dll" by default.
)

target_link_options(us-intl-altgr PRIVATE
  "/NOENTRY"
  "/IGNORE:4254"
  "-merge:.edata=.data"
  "-merge:.rdata=.data"
  "-merge:.text=.data"
  "-merge:.bss=.data"
  "-section:.data,re"
)
