#ifndef __MATRIX3X3__
#define __MATRIX3X3__

#include "Vector.h"

// 旋转矩阵绕坐标轴类型
enum ERotateType
{
	ERT_Invalid = 0,
	ERT_X,		// X轴
	ERT_Y,		// Y轴
	ERT_Z,		// Z轴
	ERT_Count
};

// 矩阵类定义
// 3x3
class CMatrix3x3
{
public:
	// bigthree
	CMatrix3x3(float v11 = 1.0f, float v12 = 0.0f, float v13 = 0.0f,
		float v21 = 0.0f, float v22 = 1.0f, float v23 = 0.0f,
		float v31 = 0.0f, float v32 = 0.0f, float v33 = 1.0f);
	CMatrix3x3(const CVector& v1, const CVector& v2, const CVector& v3);
	CMatrix3x3(const CMatrix3x3& other);
	CMatrix3x3& operator=(const CMatrix3x3& other);
	bool operator==(const CMatrix3x3& other);

public:
	void Show() const;

public:
	// 设置矩阵为旋转矩阵--绕X轴，Y轴，Z轴
	void SetRotate(ERotateType type, float fAngle);
	// 设置缩放矩阵
	void SetScale(float x, float y, float z);
	// 重置为单位矩阵
	void SetIdentityMatrix();

public:
	// 使用三个行向量表示
	CVector m_vertex1;
	CVector m_vertex2;
	CVector m_vertex3;
};

CMatrix3x3 operator*(const CMatrix3x3& left, const CMatrix3x3& right);
CVector operator*(const CVector& vertex, const CMatrix3x3& matrix);

#endif
