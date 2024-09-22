board_runner_args(pyocd  "-t=nrf52840" )
include(${ZEPHYR_BASE}/boards/common/uf2.board.cmake)
include(${ZEPHYR_BASE}/boards/common/pyocd.board.cmake)
