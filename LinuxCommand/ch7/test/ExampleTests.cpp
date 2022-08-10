#include "Gun.h"
#include "Solider.h"
#include "gtest/gtest.h"


TEST(TESTCASE, test0)
{
    Solider sanduo("xusanduo");
    sanduo.addGun(new Gun("AK47"));
    sanduo.addBulletToGun(20);
    EXPECT_TRUE(sanduo.fire());
}