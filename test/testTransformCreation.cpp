#include <gtest/gtest.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace {
template<int size, class T>
void ASSERT_MAT(const T& a, const T& b) {
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			ASSERT_NEAR(a[i][j], b[i][j], 0.001f);
}
}

TEST(testTransformCreation, translate) {
	glm::mat4 mat{
		glm::vec4{ 1.0, 0.0, 0.0, 0.0 },
		glm::vec4{ 0.0, 1.0, 0.0, 0.0 },
		glm::vec4{ 0.0, 0.0, 1.0, 0.0 },
		glm::vec4{ 1.0, 2.0, 3.0, 1.0 } };

	glm::mat4 m2 = glm::translate(glm::mat4(1), glm::vec3(1, 2, 3));
	ASSERT_MAT<4>(mat, m2);
}

TEST(testTransformCreation, rotate) {
	glm::mat4 mat{
		glm::vec4{ 0.0, 0.0, -1.0, 0.0 },
		glm::vec4{ 0.0, 1.0, 0.0, 0.0 },
		glm::vec4{ 1.0, 0.0, 0.0, 0.0 },
		glm::vec4{ 0.0, 0.0, 0.0, 1.0 } };

	glm::mat4 m2 = glm::rotate(glm::mat4(1), glm::radians(90.0f), glm::vec3(0, 1, 0));
	ASSERT_MAT<4>(mat, m2);
}

TEST(testTransformCreation, scale) {
	glm::mat4 mat{
		glm::vec4{ 4.0, 0.0, 0.0, 0.0 },
		glm::vec4{ 0.0, 2.0, 0.0, 0.0 },
		glm::vec4{ 0.0, 0.0, 3.0, 0.0 },
		glm::vec4{ 0.0, 0.0, 0.0, 1.0 } };

	glm::mat4 m2 = glm::scale(glm::mat4(1), glm::vec3(4, 2, 3));
	ASSERT_MAT<4>(mat, m2);
}

TEST(testTransformCreation, lookAt) {
	glm::mat4 mat{
		glm::vec4{ 0.0, 0.0, 1.0, 0.0 },
		glm::vec4{ 1.0, 0.0, 0.0, 0.0 },
		glm::vec4{ 0.0, 1.0, 0.0, 0.0 },
		glm::vec4{ 0.0, 0.0, -10.0, 1.0 } };

	glm::mat4 m2 = glm::lookAt(glm::vec3(10.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0));
	ASSERT_MAT<4>(mat, m2);
}

TEST(testTransformCreation, perspective) {
	glm::mat4 mat{
		glm::vec4{ 1.20710671, 0.0, 0.0, 0.0 },
		glm::vec4{ 0.0, 2.41421342, 0.0, 0.0 },
		glm::vec4{ 0.0, 0.0, -1.00200200, -1.0 },
		glm::vec4{ 0.0, 0.0, -0.200200200, 0.0 } };

	glm::mat4 m2 = glm::perspective(glm::radians(45.0f), 2.0f, 0.1f, 100.0f);
	ASSERT_MAT<4>(mat, m2);
}