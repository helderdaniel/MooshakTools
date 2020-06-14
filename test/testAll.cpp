/**
 * Run all unittest files at once
 *
 * hdaniel@ualg.pt
 * 25th may 2020
 */

/**
 * Too enable catch2 benchmarking
 * it is needed to be defined here before the inclusion of the <cathc.hpp>
 * and also in the file where is defined: CATCH_CONFIG_MAIN if NOT here
 */
#define CATCH_CONFIG_ENABLE_BENCHMARKING

#include "testEval.cpp"
#include "testCSubmissions.cpp"
#include "testSubmission.cpp"


