

#include "gtest/gtest.h"
#include "../Activities.h"

TEST(Activities, Constructor) {
    Activities A(12, 13, 5, "Curl");
    ASSERT_EQ(12, A.getStart());
    ASSERT_EQ(13, A.getAnEnd());
    ASSERT_EQ(5, A.getDay());
    ASSERT_EQ("Curl", A.getDescription());
}
