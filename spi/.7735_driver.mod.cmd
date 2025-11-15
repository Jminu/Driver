savedcmd_/project/driver/spi/7735_driver.mod := printf '%s\n'   7735_driver.o | awk '!x[$$0]++ { print("/project/driver/spi/"$$0) }' > /project/driver/spi/7735_driver.mod
