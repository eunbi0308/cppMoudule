add_test([=[Parsing.invalid_char]=]  /home/eunbi/Desktop/cpp/09/ex01/build/btc [==[--gtest_filter=Parsing.invalid_char]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Parsing.invalid_char]=]  PROPERTIES WORKING_DIRECTORY /home/eunbi/Desktop/cpp/09/ex01/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[Parsing.calcaulte]=]  /home/eunbi/Desktop/cpp/09/ex01/build/btc [==[--gtest_filter=Parsing.calcaulte]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Parsing.calcaulte]=]  PROPERTIES WORKING_DIRECTORY /home/eunbi/Desktop/cpp/09/ex01/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  btc_TESTS Parsing.invalid_char Parsing.calcaulte)
