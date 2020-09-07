cd ../documentation
rm -rf generatedDocumentation

cd ../lib
make distclean
cd ../

cd test/end_course_sensors
make distclean

cd ../h_bridge
make distclean

cd ../pid_unit_test
make distclean

cd ../pwm
make distclean