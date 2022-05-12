#include <gtest/gtest.h>
#include <queue>
#include <cstdio>
using namespace std;

int foo(int a, int b)
{
    return a+b;
}


TEST(HelloTest, StringTest){
    EXPECT_STRNE("hello","hello")<<"The two strings are equal";
}

TEST(HelloTest, NumberTest){
    EXPECT_EQ(7*6,48)<<"The two numbers are not equal";
}

TEST(FooTest, ZeroTest)
{
    EXPECT_EQ(0,foo(0,0))<<"foo(0,0) is not equal to zeo";
}

TEST(FooTest, NumberTest)
{
    EXPECT_EQ(15,foo(6,6))<<"foo(6,6) is not equal to 15";
}


class QueueTest:public::testing::Test{
    protected:
    void SetUp() override{
        q1_.push(1);
        q2_.push(2);
        q2_.push(3);
    }

    std::queue<int> q0_;
    std::queue<int> q1_;
    std::queue<int> q2_;
};


TEST_F(QueueTest,IsEmptyInitially){
    EXPECT_EQ(q0_.size(),0);
}

TEST_F(QueueTest,DequeueWorks){
    q1_.pop();
    EXPECT_EQ(q1_.size(),0);
    q2_.pop();
    EXPECT_EQ(q2_.size(),1);
}

TEST_F(QueueTest,DequeueWorks1){
    EXPECT_EQ(q1_.size(),1);
    q2_.pop();
    EXPECT_EQ(q2_.size(),1);
}

int main(int argc,char **argv){
    ::testing::InitGoogleTest(&argc,argv);
    cout<<"main function runs here!";
    return RUN_ALL_TESTS();
}