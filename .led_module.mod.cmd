savedcmd_/project/driver_prac/led_module.mod := printf '%s\n'   led_module.o | awk '!x[$$0]++ { print("/project/driver_prac/"$$0) }' > /project/driver_prac/led_module.mod
