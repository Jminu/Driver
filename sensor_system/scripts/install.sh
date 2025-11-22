cd ../drivers/

echo "---- Driver Build ----"
make clean && make

echo "---- Removing Old Module"
rmmod hd44780_driver
rmmod sht20_driver

echo "---- Install Module ----"
insmod ../drivers/hd44780_driver.ko
insmod ../drivers/sht20_driver.ko

echo "---- App Build ----"
cd ../app/
gcc -o app app.c
./app
