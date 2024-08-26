add_test( myfunctions.add /home/eucho/Desktop/CPP/googletest_tutorial/build/mytests [==[--gtest_filter=myfunctions.add]==] --gtest_also_run_disabled_tests)
set_tests_properties( myfunctions.add PROPERTIES WORKING_DIRECTORY /home/eucho/Desktop/CPP/googletest_tutorial/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( mytests_TESTS myfunctions.add)
