// 3DMath.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include "Vector.h"
#include "Matrix3x3.h"

inline void LineFeed()
{
	std::cout << std::endl;
}

int main()
{
   //std::cout << "Hello Vector!\n"<<std::endl;

   //CVector vertex1(1.0f, 1.2f, 1.3f);
   //vertex1.Show();
   //std::cout << std::endl;
   //CVector vertex2(2.0f, 3.0f, 1.4f);
   //vertex2.Show();
   //std::cout << std::endl;
   //CVector vertex3(7.0f, 2.3f, 1.5f);
   //vertex3.Show();
   //std::cout << std::endl;

   //std::cout << std::endl;
   //CMatrix3x3 matrix1(vertex1, vertex2, vertex3);
   //matrix1.Show();
   //std::cout << std::endl;
   //CMatrix3x3 matrix2(1.5f, 2.3f, 7.7f,
	  // 3.3f, 3.6f, 8.2f,
	  // 2.6f, 5.7f, 1.4f);
   //matrix2.Show();
   //std::cout << std::endl;
   //auto matrix3 = matrix1 * matrix2;
   //matrix3.Show();

   // 行向量与矩阵相乘
   //CVector temp1(2.0f, 3.0f, 4.0f);
   //CMatrix3x3 temp2;
   //auto res = temp1 * temp2;
   //res.Show();

   //CMatrix3x3 matrix;
   //matrix.SetRotate(ERT_X, 60.0f);
   //matrix.Show();
   //std::cout << std::endl;

   //matrix.SetIdentityMatrix();
   //matrix.SetRotate(ERT_Y, 30.0f);
   //matrix.Show();
   //std::cout << std::endl;

   //matrix.SetIdentityMatrix();
   //matrix.SetRotate(ERT_Z, 90.0f);
   //matrix.Show();
   //std::cout << std::endl;


   //CVector vertex1(1.0f, 1.2f, 1.3f);
   //auto temp = vertex1 * 2.0f;
   //temp.Show();

   //CMatrix3x3 matrix;
   //matrix.SetRotate(ERT_X, 90.0f);
   //CVector vertex(1.0f, 2.0f, 3.0f);
   //vertex.Show();
   //std::cout << std::endl;
   //CVector res = vertex * matrix;
   //res.Show();

   CMatrix3x3 matrix;
   matrix.SetScale(1.0f, 2.0f, 3.0f);
   CVector v1(1, 2, 3);
   v1.Show();
   LineFeed();
   v1 = v1 * matrix;
   v1.Show();
   LineFeed();

   std::cout << "\n" << std::endl;
   system("pause");
}
