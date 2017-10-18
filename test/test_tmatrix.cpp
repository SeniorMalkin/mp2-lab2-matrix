#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> v(10);
	TMatrix<int> v1(v);
	EXPECT_EQ(v, v1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> v(10);
	TMatrix<int> v1(v);
	v[3] = v[3] + 7;
	EXPECT_NE(v, v1);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> v(4);
	EXPECT_EQ(4, v[0].GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> v(4);
	v[0][2] = 4;
	EXPECT_EQ(4, v[0][2]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> v(4);
	ASSERT_ANY_THROW(v[0][-5]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> v(4);
	ASSERT_ANY_THROW(v[5]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> v(4);
	TMatrix<int> v1(v);
	v = v;
	EXPECT_EQ(v, v1);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> v(4);
	TMatrix<int> v1(4);
	for (int i = 0; i < v.GetSize(); i++)
		v[i] = v[i] + 1;
	v1 = v;
	EXPECT_EQ(v, v1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	int size = 4;
	TMatrix<int> v(size);
	TMatrix<int> v1(7);
	v = v1;
	EXPECT_NE(size, v[0].GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> v(4);
	TMatrix<int> v1(7);
	for (int i = 0; i < v1[0].GetSize(); i++)
		v1[i] = v1[i] + 7;
	v = v1;
	EXPECT_EQ(v, v1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> v(4);
	TMatrix<int> v1(4);
	for (int i = 0; i < v[0].GetSize(); i++)
		v[i] = v1[i] = v1[i] + 1;
	EXPECT_EQ(v, v1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> v(4);
	EXPECT_TRUE(v == v);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> v(4);
	TMatrix<int> v1(7);
	EXPECT_FALSE(v == v1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> v(4);
	TMatrix<int> v1(4);
	EXPECT_NO_THROW(v + v1);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> v(4);
	TMatrix<int> v1(7);
	EXPECT_ANY_THROW(v + v1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> v(4);
	TMatrix<int> v1(4);
	EXPECT_NO_THROW(v - v1);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> v(4);
	TMatrix<int> v1(7);
	EXPECT_ANY_THROW(v - v1);
}

