#include "Matrix3x3.h"

#include "MathHelper.h"

#include <iostream>
#include <cmath>

#include <assert.h>

CMatrix3x3::CMatrix3x3(float v11, float v12, float v13, float v21, float v22, float v23, float v31, float v32, float v33)
	:m_vertex1(v11, v12, v13),
	m_vertex2(v21, v22, v13),
	m_vertex3(v31, v32, v33)
{

}

CMatrix3x3::CMatrix3x3(const CVertex& v1, const CVertex& v2, const CVertex& v3)
	:m_vertex1(v1),
	m_vertex2(v2),
	m_vertex3(v3)
{

}

CMatrix3x3::CMatrix3x3(const CMatrix3x3& other)
	:m_vertex1(other.m_vertex1),
	m_vertex2(other.m_vertex2),
	m_vertex3(other.m_vertex3)
{
	
}

bool CMatrix3x3::operator==(const CMatrix3x3& other)
{
	return m_vertex1 == other.m_vertex1 &&
		m_vertex2 == other.m_vertex2 &&
		m_vertex3 == other.m_vertex3;
}

CMatrix3x3& CMatrix3x3::CMatrix3x3::operator=(const CMatrix3x3& other)
{
	if (*this == other)
		return *this;

	m_vertex1 = other.m_vertex1;
	m_vertex2 = other.m_vertex2;
	m_vertex3 = other.m_vertex3;

	return *this;
}

void CMatrix3x3::Show() const
{
	m_vertex1.Show();
	std::cout << std::endl;

	m_vertex2.Show();
	std::cout << std::endl;

	m_vertex3.Show();
	std::cout << std::endl;
}

void CMatrix3x3::SetRotate(ERotateType type, float fAngle)
{
	float fRadian = GetRadian(fAngle);

	switch (type)
	{
	case ERT_X:

		m_vertex1.SetValue11(1.0f);
		m_vertex1.SetValue12(0.0f);
		m_vertex1.SetValue13(0.0f);

		m_vertex2.SetValue11(0.0f);
		m_vertex2.SetValue12(cos(fRadian));
		m_vertex2.SetValue13(sin(fRadian));

		m_vertex3.SetValue11(0.0f);
		m_vertex3.SetValue12(-sin(fRadian));
		m_vertex3.SetValue13(cos(fRadian));

		break;
	case ERT_Y:
		m_vertex1.SetValue11(cos(fRadian));
		m_vertex1.SetValue12(0.0f);
		m_vertex1.SetValue13(-sin(fRadian));

		m_vertex2.SetValue11(0.0f);
		m_vertex2.SetValue12(1.0f);
		m_vertex2.SetValue13(0.0f);

		m_vertex3.SetValue11(sin(fRadian));
		m_vertex3.SetValue12(0.0f);
		m_vertex3.SetValue13(cos(fRadian));

		break;
	case ERT_Z:
		m_vertex1.SetValue11(cos(fRadian));
		m_vertex1.SetValue12(sin(fRadian));
		m_vertex1.SetValue13(0.0f);

		m_vertex2.SetValue11(-sin(fRadian));
		m_vertex2.SetValue12(cos(fRadian));
		m_vertex2.SetValue13(0.0f);

		m_vertex3.SetValue11(0.0f);
		m_vertex3.SetValue12(0.0f);
		m_vertex3.SetValue13(1.0f);

		break;
	default:
		assert(0);
		return;
	}
}

void CMatrix3x3::SetIdentityMatrix()
{
	m_vertex1 = CVertex(1.0f, 0.0f, 0.0f);
	m_vertex2 = CVertex(0.0f, 1.0f, 0.0f);
	m_vertex3 = CVertex(0.0f, 0.0f, 1.0f);
}

CMatrix3x3 operator*(const CMatrix3x3& left, const CMatrix3x3& right)
{
	float fV11 = left.m_vertex1.m_v11 * right.m_vertex1.m_v11 + left.m_vertex1.m_v12 * right.m_vertex2.m_v11 + left.m_vertex1.m_v13 * right.m_vertex3.m_v11;
	float fV12 = left.m_vertex1.m_v11 * right.m_vertex1.m_v12 + left.m_vertex1.m_v12 * right.m_vertex2.m_v12 + left.m_vertex1.m_v13 * right.m_vertex3.m_v12;
	float fV13 = left.m_vertex1.m_v11 * right.m_vertex1.m_v13 + left.m_vertex1.m_v12 * right.m_vertex2.m_v13 + left.m_vertex1.m_v13 * right.m_vertex3.m_v13;

	float fV21 = left.m_vertex2.m_v11 * right.m_vertex1.m_v11 + left.m_vertex2.m_v12 * right.m_vertex2.m_v11 + left.m_vertex2.m_v13 * right.m_vertex3.m_v11;
	float fV22 = left.m_vertex2.m_v11 * right.m_vertex1.m_v12 + left.m_vertex2.m_v12 * right.m_vertex2.m_v12 + left.m_vertex2.m_v13 * right.m_vertex3.m_v12;
	float fV23 = left.m_vertex2.m_v11 * right.m_vertex1.m_v13 + left.m_vertex2.m_v12 * right.m_vertex2.m_v13 + left.m_vertex2.m_v13 * right.m_vertex3.m_v13;

	float fV31 = left.m_vertex3.m_v11 * right.m_vertex1.m_v11 + left.m_vertex3.m_v12 * right.m_vertex2.m_v11 + left.m_vertex3.m_v13 * right.m_vertex3.m_v11;
	float fV32 = left.m_vertex3.m_v11 * right.m_vertex1.m_v12 + left.m_vertex3.m_v12 * right.m_vertex2.m_v12 + left.m_vertex3.m_v13 * right.m_vertex3.m_v12;
	float fV33 = left.m_vertex3.m_v11 * right.m_vertex1.m_v13 + left.m_vertex3.m_v12 * right.m_vertex2.m_v13 + left.m_vertex3.m_v13 * right.m_vertex3.m_v13;


	return CMatrix3x3(fV11, fV12, fV12, fV21, fV22, fV23, fV31, fV32, fV33);
}

CVertex operator*(const CVertex& vertex, const CMatrix3x3& matrix)
{
	float fV11 = vertex.m_v11 * matrix.m_vertex1.m_v11 + vertex.m_v12 * matrix.m_vertex2.m_v11 + vertex.m_v13 * matrix.m_vertex3.m_v11;

	float fV12 = vertex.m_v11 * matrix.m_vertex1.m_v12 + vertex.m_v12 * matrix.m_vertex2.m_v12 + vertex.m_v13 * matrix.m_vertex3.m_v12;

	float fV13 = vertex.m_v11 * matrix.m_vertex1.m_v13 + vertex.m_v12 * matrix.m_vertex2.m_v13 + vertex.m_v13 * matrix.m_vertex3.m_v13;

	return CVertex(fV11, fV12, fV13);

}
