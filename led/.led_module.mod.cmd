savedcmd_/project/driver/led/led_module.mod := printf '%s\n'   led_module.o | awk '!x[$$0]++ { print("/project/driver/led/"$$0) }' > /project/driver/led/led_module.mod
