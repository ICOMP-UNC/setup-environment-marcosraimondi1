#include "div.h"
#include "prod.h"
#include <unity.h>

// executes before a test
void setUp(void)
{
}

// executes after a test
void tearDown(void)
{
}

void test_prod_prod()
{
    TEST_ASSERT_EQUAL(50, prod(10, 5));
    TEST_ASSERT_NOT_EQUAL(0, prod(5, 5));
}

void test_div_div()
{
    TEST_ASSERT_EQUAL(2, div(10, 5));
    TEST_ASSERT_EQUAL(0, div(5, 0));
    TEST_ASSERT_EQUAL(0, div(5, 10));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_prod_prod);
    RUN_TEST(test_div_div);
    return UNITY_END();
}
