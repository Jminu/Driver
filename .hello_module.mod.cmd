savedcmd_/project/driver_prac/hello_module.mod := printf '%s\n'   hello_module.o | awk '!x[$$0]++ { print("/project/driver_prac/"$$0) }' > /project/driver_prac/hello_module.mod
