source iss_setup.sh

cd ..
doxygen doxygenConfigurationFile.conf

cd lib
make distclean
make
cd ../

cd test/end_course_sensors
make distclean
make

cd ../h_bridge
make distclean
make

cd ../pid_unit_test
make distclean
make

cd ../pwm
make distclean
make