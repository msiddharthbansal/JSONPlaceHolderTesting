#include <gtest/gtest.h>
#include "create_post.h"
#include "fetch_post.h"
#include "update_post.h"
#include "delete_post.h"

TEST(CreatePostTest, ValidPost) {
    ASSERT_NO_THROW(createPost("Test Title", "Test Body"));
}

TEST(FetchPostsTest, FetchAllPosts) {
    ASSERT_NO_THROW(fetchPosts());
}

TEST(UpdatePostTest, UpdatePostTitle) {
    // Assuming postId 1 exists for simplicity
    ASSERT_NO_THROW(updatePost(1, "Updated Title", ""));
}

TEST(UpdatePostTest, UpdatePostBody) {
    // Assuming postId 1 exists for simplicity
    ASSERT_NO_THROW(updatePost(1, "", "Updated Body"));
}
TEST(UpdatePostTest, UpdatePostTitleAndBody) {
    // Assuming postId 1 exists for simplicity
    ASSERT_NO_THROW(updatePost(1, "Updated Title", "Updated Body"));
}

TEST(DeletePostTest, DeleteExistingPost) {
    // Assuming postId 1 exists for simplicity
    ASSERT_NO_THROW(deletePost(2));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

