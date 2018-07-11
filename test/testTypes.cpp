#include <gtest/gtest.h>

#include <glm/glm.hpp>

TEST(glmTypes, vec3) {
	glm::vec3 x(1.0, 0.0, 0.0);
	ASSERT_FLOAT_EQ(1.0, x.x);
	ASSERT_FLOAT_EQ(0.0, x.y);
	ASSERT_FLOAT_EQ(0.0, x.z);

	x += glm::vec3(0.5);

	ASSERT_FLOAT_EQ(1.5, x.s);
	ASSERT_FLOAT_EQ(0.5, x.t);
	ASSERT_FLOAT_EQ(0.5, x.p);

	x *= 2.0;

	ASSERT_FLOAT_EQ(3.0, x.r);
	ASSERT_FLOAT_EQ(1.0, x.g);
	ASSERT_FLOAT_EQ(1.0, x.b);

	ASSERT_EQ(x, glm::vec3(3.0, 1.0, 1.0));
}

TEST(glmTypes, mat4) {
	glm::mat4 mat{
		glm::vec4{1.0, 0.0, 0.0, 0.0},
		glm::vec4{0.0, 0.0, 2.0, 0.0},
		glm::vec4{0.0, 2.0, 0.0, 0.5},
		glm::vec4{0.0, 0.0, 0.0, 1.0} };

	glm::vec4 v4 = mat * glm::vec4{ glm::vec3{4, 5, 6}, 1 };
	ASSERT_EQ(v4, glm::vec4(4, 12, 10, 4));

	glm::vec3 v3 = glm::vec3{ v4 } / v4.w;
	ASSERT_EQ(v3, glm::vec3(1, 3, 2.5));
}