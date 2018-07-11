#include <gtest/gtest.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

TEST(testDataAccess, vec3) {
	glm::vec3 x(2.0, 3.0, 4.0);

	const float* data = glm::value_ptr(x);
	ASSERT_FLOAT_EQ(2.0, data[0]);
	ASSERT_FLOAT_EQ(3.0, data[1]);
	ASSERT_FLOAT_EQ(4.0, data[2]);

	float dat[] = { 2.0, 3.0, 4.0 };
	glm::vec3 y = glm::make_vec3(dat);
	ASSERT_EQ(x, y);
}

TEST(testDataAccess, mat4) {
	glm::mat4 mat{
		glm::vec4{ 1.0, 0.0, 0.0, 0.0 },
		glm::vec4{ 0.0, 0.0, 2.0, 0.0 },
		glm::vec4{ 0.0, 2.0, 0.0, 0.5 },
		glm::vec4{ 0.0, 0.0, 0.0, 1.0 } };

	const float* data = glm::value_ptr(mat);
	ASSERT_FLOAT_EQ(1.0, data[     0]);
	ASSERT_FLOAT_EQ(0.0, data[     1]);
	ASSERT_FLOAT_EQ(0.0, data[     2]);
	ASSERT_FLOAT_EQ(0.0, data[     3]);
	ASSERT_FLOAT_EQ(0.0, data[ 4 + 0]);
	ASSERT_FLOAT_EQ(0.0, data[ 4 + 1]);
	ASSERT_FLOAT_EQ(2.0, data[ 4 + 2]);
	ASSERT_FLOAT_EQ(0.0, data[ 4 + 3]);
	ASSERT_FLOAT_EQ(0.0, data[ 8 + 0]);
	ASSERT_FLOAT_EQ(2.0, data[ 8 + 1]);
	ASSERT_FLOAT_EQ(0.0, data[ 8 + 2]);
	ASSERT_FLOAT_EQ(0.5, data[ 8 + 3]);
	ASSERT_FLOAT_EQ(0.0, data[12 + 0]);
	ASSERT_FLOAT_EQ(0.0, data[12 + 1]);
	ASSERT_FLOAT_EQ(0.0, data[12 + 2]);
	ASSERT_FLOAT_EQ(1.0, data[12 + 3]);

	float dat[] = {
		1.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 2.0, 0.0,
		0.0, 2.0, 0.0, 0.5,
		0.0, 0.0, 0.0, 1.0 };
	glm::mat4 m2 = glm::make_mat4(dat);
	ASSERT_EQ(mat, m2);

}