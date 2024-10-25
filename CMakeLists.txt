zephyr_library()

if (CONFIG_INPUT)
  zephyr_library_sources(src/math.c)
  zephyr_library_sources(src/input_behavior_listener.c)
  zephyr_library_sources(src/input_behavior_scaler.c)
  zephyr_library_sources(src/input_behavior_tog_layer.c)
endif()

zephyr_include_directories(${APPLICATION_SOURCE_DIR}/include)
