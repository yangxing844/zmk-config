# SPDX-License-Identifier: MIT

board_runner_args(pyocd  "--target=nrf528833")
include(${ZEPHYR_BASE}/boards/common/uf2.board.cmake)
include(${ZEPHYR_BASE}/boards/common/nrfjprog.board.cmake)

include(${ZEPHYR_BASE}/boards/common/pyocd.board.cmake)
