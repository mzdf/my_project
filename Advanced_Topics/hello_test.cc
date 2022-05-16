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
    ASSERT_EQ(q2_.size(),1);
}



testing::AssertionResult IsEven(int n) {
    if(n%2==0) return testing::AssertionSuccess();
    else return testing::AssertionFailure()<<n<<" is odd!";
}


bool isEven(int n) {
    return n%2==0;
}

TEST(TestEven, t1) {
    EXPECT_TRUE(IsEven(3));
}


TEST(SkipTest,DoesSkip) {
    GTEST_SKIP()<<"Skipping a single test";
    EXPECT_EQ(0,1);
}

class SkipFixture:public::testing::Test {
    protected:
    void SetUp() override {
        GTEST_SKIP()<<"Skipping all tests for this fixture";
    }
};

TEST_F(SkipFixture, SkipOneTest){
    EXPECT_EQ(5,6);
}

bool Foo(int* a)
{
    if(*a==0) 
    {
        fprintf(stderr,"Sending myself unblocked signal");
        kill(getpid(),SIGKILL);
    }
    if(*a%2==1)
    {
        fprintf(stderr,"Error on line .* of Foo()");
        exit(1);
    }
    fprintf(stderr,"Success");
    exit(0);
    return *a%2==0;
}
TEST(MyDeathTest, Foo) {
    ASSERT_DEATH({
        int n=5;
        Foo(&n);
    },"Error on line .* of Foo()");
}

TEST(MyDeathTest,NormalExit) {
    int n=4;
    EXPECT_EXIT(Foo(&n),testing::ExitedWithCode(0),"Success");
}

TEST(MyDeathTest,KillProcess) {
    int n=0;
    EXPECT_EXIT(Foo(&n),testing::KilledBySignal(SIGKILL),"Sending myself unblocked signal");
}

int main(int argc,char **argv){
    EXPECT_EQ(3*4,15);
    ::testing::InitGoogleTest(&argc,argv);
    cout<<"main function runs here!";
    return RUN_ALL_TESTS();
}