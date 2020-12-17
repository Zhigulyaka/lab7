#include "StackList.h"
#include "QueueList.h"
#include <../gtest/gtest.h>


TEST(StackList, can_create_stack_with_default_constructor)
{
    ASSERT_NO_THROW(StackList<int> s);
}
TEST(StackList, can_create_copied_stack)
{
    StackList<int> s;
    ASSERT_NO_THROW(StackList<int> s1(s));
}

TEST(StackList, copied_stack_is_equal_to_source_one)
{
    StackList<int> s1;
    int f = 0;
    int g = 0;
    for (int i = 0; i < 5; i++)
        s1.push(i);
    StackList<int> s2(s1);
    EXPECT_EQ(s1.GetCount(), s2.GetCount());
    for (int i = 0; i < 5; i++)
    {
        f = s1.pull();
        g = s2.pull();
        EXPECT_EQ(f,g );
    }
        
}

TEST(StackList, can_get_count)
{
    StackList<int> s1;
    for (int i = 0; i < 5; i++)
        s1.push(i);

    EXPECT_EQ(5, s1.GetCount());
}

TEST(StackList, can_set_element)
{
    StackList<int> s;
    ASSERT_NO_THROW(s.push(6));
    EXPECT_EQ(6, s.pull());
}

TEST(StackList, can_get_element)
{
    StackList<int> s;
    s.push(6);
    EXPECT_EQ(6, s.pull());
}

TEST(StackList, can_assign_stacks_to_itself)
{
    StackList<int> s;
    ASSERT_NO_THROW(s = s);

}

TEST(StackList, can_assign_stacks_of_equal_size)
{
    StackList<int> s1;
    StackList<int> s2;
    for (int i = 0; i < 5; i++)
    {
        s1.push(i); 
        s2.push(1);
    }
        
    s2 = s1;
    EXPECT_EQ(s1.GetCount(), s2.GetCount());
    for (int i = 0; i < s1.GetCount(); i++)
        EXPECT_EQ(s1.pull(), s2.pull());
}

TEST(StackList, can_assign_stacks_of_different_size)
{
    StackList<int> s1;
    StackList<int> s2;
    for (int i = 0; i < 10; i++)
    {
        s1.push(i);
    }
    for (int i = 0; i < 5; i++)
    {
        s2.push(i);
    }
    s2 = s1;
    EXPECT_EQ(s1.GetCount(), s2.GetCount());
    for (int i = 0; i < s1.GetCount(); i++)
        EXPECT_EQ(s1.pull(), s2.pull());
}

TEST(QueueList, can_create_queue_with_default_constructor)
{
    ASSERT_NO_THROW(QueueList<int> s);
}
TEST(QueueList, can_create_copied_queue)
{
    QueueList<int> s;
    ASSERT_NO_THROW(QueueList<int> s1(s));
}

TEST(QueueList, copied_queue_is_equal_to_source_one)
{
    QueueList<int> s1;
    for (int i = 0; i < 5; i++)
        s1.push(i);
    QueueList<int> s2(s1);
    EXPECT_EQ(s1.GetCount(), s2.GetCount());
    for (int i = 0; i < s1.GetCount(); i++)
        EXPECT_EQ(s1.pull(), s2.pull());
}

TEST(QueueList, can_get_count)
{
    QueueList<int> s1;
    for (int i = 0; i < 5; i++)
        s1.push(i);

    EXPECT_EQ(5, s1.GetCount());
}

TEST(QueueList, can_set_element)
{
    QueueList<int> s;
    ASSERT_NO_THROW(s.push(6));
    EXPECT_EQ(6, s.pull());
}

TEST(QueueList, can_get_element)
{
    QueueList<int> s;
    s.push(6);
    EXPECT_EQ(6, s.pull());
}

TEST(QueueList, can_assign_queues_to_itself)
{
    QueueList<int> s;
    ASSERT_NO_THROW(s = s);

}

TEST(QueueList, can_assign_queues_of_equal_size)
{
    QueueList<int> s1;
    QueueList<int> s2;
    for (int i = 0; i < 5; i++)
    {
        s1.push(i);
        s2.push(1);
    }

    s2 = s1;
    EXPECT_EQ(s1.GetCount(), s2.GetCount());
    for (int i = 0; i < s1.GetCount(); i++)
        EXPECT_EQ(s1.pull(), s2.pull());
}

TEST(QueueList, can_assign_queues_of_different_size)
{
    QueueList<int> s1;
    QueueList<int> s2;
    for (int i = 0; i < 10; i++)
    {
        s1.push(i);
    }
    for (int i = 0; i < 5; i++)
    {
        s2.push(i);
    }
    s2 = s1;
    EXPECT_EQ(s1.GetCount(), s2.GetCount());
    for (int i = 0; i < s1.GetCount(); i++)
        EXPECT_EQ(s1.pull(), s2.pull());
}
