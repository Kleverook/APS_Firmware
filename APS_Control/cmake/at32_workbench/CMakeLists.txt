cmake_minimum_required(VERSION 3.22)
# Enable CMake support for ASM and C languages
enable_language(C ASM)
# AT32 WorkBench generated symbols (macros)
set(WK_Defines_Syms
    USE_STDPERIPH_DRIVER
    AT32F435VGT7
    $<$<CONFIG:Debug>:DEBUG>
)

# AT32 WorkBench generated include paths
set(WK_Include_Dirs
    ${CMAKE_SOURCE_DIR}/project/inc
    ${CMAKE_SOURCE_DIR}/project/src
    ${CMAKE_SOURCE_DIR}/project/inc/core
    ${CMAKE_SOURCE_DIR}/project/src/core
    ${CMAKE_SOURCE_DIR}/libraries/drivers/inc
    ${CMAKE_SOURCE_DIR}/libraries/cmsis/cm4/core_support
    ${CMAKE_SOURCE_DIR}/libraries/cmsis/cm4/device_support
)

# AT32 WorkBench generated application sources
set(WK_Application_Src
    ${CMAKE_SOURCE_DIR}/project/src/main.c
    ${CMAKE_SOURCE_DIR}/project/src/syscalls.c
    ${CMAKE_SOURCE_DIR}/project/src/sysmem.c
    ${CMAKE_SOURCE_DIR}/project/src/at32f435_437_wk_config.c
    ${CMAKE_SOURCE_DIR}/project/src/at32f435_437_int.c
    ${CMAKE_SOURCE_DIR}/project/src/wk_system.c
    ${CMAKE_SOURCE_DIR}/project/src/wk_adc.c
    ${CMAKE_SOURCE_DIR}/project/src/wk_can.c
    ${CMAKE_SOURCE_DIR}/project/src/wk_i2c.c
    ${CMAKE_SOURCE_DIR}/project/src/wk_tmr.c
    ${CMAKE_SOURCE_DIR}/project/src/wk_usart.c
    ${CMAKE_SOURCE_DIR}/project/src/wk_gpio.c
    ${CMAKE_SOURCE_DIR}/startup_at32f435_437.s
)

# AT32 Drivers
set(AT32_Drivers_Src
    ${CMAKE_SOURCE_DIR}/libraries/cmsis/cm4/device_support/system_at32f435_437.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_crm.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_tmr.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_ertc.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_gpio.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_i2c.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_usart.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_pwc.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_adc.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_spi.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_dma.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_edma.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_debug.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_flash.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_crc.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_wwdt.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_wdt.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_exint.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_misc.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_scfg.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_usb.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_acc.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_can.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_dac.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_xmc.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_qspi.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_sdio.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_dvp.c
    ${CMAKE_SOURCE_DIR}/libraries/drivers/src/at32f435_437_emac.c
)

# Drivers Middlewares

# Link directories setup
set(WK_LINK_DIRS

)

# Project static libraries
set(WK_LINK_LIBS
    AT32_Drivers
)

# Interface library for includes and symbols
add_library(at32_workbench INTERFACE)
target_include_directories(at32_workbench INTERFACE ${WK_Include_Dirs})
target_compile_definitions(at32_workbench INTERFACE ${WK_Defines_Syms})

# Create AT32_Drivers static library
add_library(AT32_Drivers OBJECT)
target_sources(AT32_Drivers PRIVATE ${AT32_Drivers_Src})
target_link_libraries(AT32_Drivers PUBLIC at32_workbench)

# Add AT32 WorkBench generated application sources to the project
target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${WK_Application_Src})

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE ${WK_LINK_DIRS})

# Add libraries to the project
target_link_libraries(${CMAKE_PROJECT_NAME} ${WK_LINK_LIBS})

# Add the map file to the list of files to be removed with 'clean' target
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES ADDITIONAL_CLEAN_FILES ${CMAKE_PROJECT_NAME}.map)

# Validate that AT32 WorkBench code is compatible with C standard
if((CMAKE_C_STANDARD EQUAL 90) OR (CMAKE_C_STANDARD EQUAL 99))
    message(ERROR "Generated code requires C11 or higher")
endif()

# Find objcopy utility
find_program(CMAKE_OBJCOPY arm-none-eabi-objcopy)

