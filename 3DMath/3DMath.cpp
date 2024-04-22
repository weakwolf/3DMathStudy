// 3DMath.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include "Vertex.h"
#include "Matrix3x3.h"

int main()
{
   std::cout << "Hello Vertex!\n"<<std::endl;

   CVertex vertex1(1.0f, 1.2f, 1.3f);
   vertex1.Show();
   std::cout << std::endl;
   CVertex vertex2(2.0f, 3.0f, 1.4f);
   vertex2.Show();
   std::cout << std::endl;
   CVertex vertex3(7.0f, 2.3f, 1.5f);
   vertex3.Show();
   std::cout << std::endl;

   std::cout << std::endl;
   CMatrix3x3 matrix1(vertex1, vertex2, vertex3);
   matrix1.Show();
   std::cout << std::endl;
   CMatrix3x3 matrix2(1.5f, 2.3f, 7.7f,
	   3.3f, 3.6f, 8.2f,
	   2.6f, 5.7f, 1.4f);
   matrix2.Show();
   std::cout << std::endl;
   auto matrix3 = matrix1 * matrix2;
   matrix3.Show();


   //CVertex vertex1(1.0f, 1.2f, 1.3f);
   //auto temp = vertex1 * 2.0f;
   //temp.Show();

   std::cout << "\n" << std::endl;
   system("pause");
}
