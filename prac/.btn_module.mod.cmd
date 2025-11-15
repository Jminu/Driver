savedcmd_/project/driver/prac/btn_module.mod := printf '%s\n'   btn_module.o | awk '!x[$$0]++ { print("/project/driver/prac/"$$0) }' > /project/driver/prac/btn_module.mod
